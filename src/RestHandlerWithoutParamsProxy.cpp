//
// Created by panpiotr on 05.08.17.
//

#include "ERF/RestHandlerWithoutParamsProxy.h"

Poco::Dynamic::Var
ERF::RestHandlerWithoutParamsProxy::onGet(const std::unordered_map<std::string, std::string> &params) {
    return _handler->onGet();
}

Poco::Dynamic::Var ERF::RestHandlerWithoutParamsProxy::onPost(Poco::JSON::Array::Ptr ptr,
                                                              const std::unordered_map<std::string, std::string> &params) {
    return _handler->onPost(ptr);
}

Poco::Dynamic::Var ERF::RestHandlerWithoutParamsProxy::onPut(Poco::JSON::Array::Ptr ptr,
                                                             const std::unordered_map<std::string, std::string> &params) {
    return _handler->onPut(ptr);
}

Poco::Dynamic::Var ERF::RestHandlerWithoutParamsProxy::onDelete(Poco::JSON::Array::Ptr ptr,
                                                                const std::unordered_map<std::string, std::string> &params) {
    return _handler->onDelete(ptr);
}

ERF::RestHandlerWithoutParamsProxy::RestHandlerWithoutParamsProxy(IRestHandler *handler)
        : _handler(handler) {}
