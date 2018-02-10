//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_RESTSERVER_H
#define ERF_RESTSERVER_H

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/ThreadPool.h>

#include <memory>

#include "RestHandlerSelector.h"

namespace ERF {
    class RestServer : public Poco::Util::ServerApplication {
    public:
        template<typename Handler>
        void registerHandler(const std::string &pattern);

    protected:
        void initialize(Application &self) override;

        void uninitialize() override;

        void defineOptions(Poco::Util::OptionSet &options) override;

    private:
        std::unique_ptr<Poco::ThreadPool> _pool;
        std::unique_ptr<Poco::Net::HTTPServer> _server;
        std::unique_ptr<Poco::Thread> _serverThread;

        Poco::SharedPtr<RestHandlerSelector> _selector;

    };

    template<typename Handler>
    void RestServer::registerHandler(const std::string &pattern) {
        if (_selector.isNull()) {
            _selector = new RestHandlerSelector();
        }
        _selector->registerHandler<Handler>(pattern);
    }
}

#endif //ERF_RESTSERVER_H
