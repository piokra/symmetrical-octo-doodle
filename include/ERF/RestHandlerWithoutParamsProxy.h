//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_RESTHANDLERWITHOUTPARAMSPROXY_H
#define ERF_RESTHANDLERWITHOUTPARAMSPROXY_H


#include <memory>

#include "IRestHandlerWithParams.h"
#include "IRestHandler.h"

namespace ERF {
    class RestHandlerWithoutParamsProxy : public IRestHandlerWithParams {
    public:
        RestHandlerWithoutParamsProxy(IRestHandler *handler);

        Poco::Dynamic::Var
        onGet(const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onPost(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onPut(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onDelete(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

    private:
        std::unique_ptr<IRestHandler> _handler;
    };
}


#endif //ERF_RESTHANDLERWITHOUTPARAMSPROXY_H
