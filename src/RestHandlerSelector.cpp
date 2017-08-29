//
// Created by panpiotr on 05.08.17.
//

#include "../include/RestHandlerSelector.h"
#include "../include/ForbiddenHandler.h"

Poco::Net::HTTPRequestHandler *RestHandlerSelector::createRequestHandler(const Poco::Net::HTTPServerRequest &request) {

    Poco::ScopedReadRWLock guard(_lock);

    for (auto &factory: _factories) {
        if (factory->wants(request.getURI())) {
            return factory->createRequestHandler(request);
        }
    }
    return new ForbiddenHandler();
}
