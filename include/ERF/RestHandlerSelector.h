//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_RESTHANDLERSELECTOR_H
#define ERF_RESTHANDLERSELECTOR_H

#include <Poco/RWLock.h>

#include "RestHandlerFactory.h"
#include <memory>

class RestHandlerSelector : public Poco::Net::HTTPRequestHandlerFactory {
public:
    Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request) override;

    template<typename Handler>
    void registerHandler(const std::string &pattern);

private:
    std::vector<std::unique_ptr<ARestHandlerFactory>> _factories;
    Poco::RWLock _lock;
};


template<typename Handler>
void RestHandlerSelector::registerHandler(const std::string &pattern) {
    Poco::ScopedWriteRWLock guard(_lock);
    _factories.emplace_back(new RestHandlerFactory<Handler>(pattern));

}


#endif //ERF_RESTHANDLERSELECTOR_H
