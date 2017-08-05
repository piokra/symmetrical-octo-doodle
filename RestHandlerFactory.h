//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_RESTHANDLERFACTORY_H
#define ERF_RESTHANDLERFACTORY_H


#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include "URIArgsParser.h"
#include "HTTPHandler.hpp"

class ARestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
public:
    ARestHandlerFactory(const std::string &pattern);

    bool wants(const std::string &uri);

protected:
    const URIArgsParser &parser();

private:
    URIArgsParser _parser;
};

template<typename Handler>
class RestHandlerFactory : public ARestHandlerFactory {
public:
    RestHandlerFactory(const std::string &pattern) : ARestHandlerFactory(pattern) {}

    Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request) override {
        return new HTTPHandler<Handler>(parser());
    }
};

#endif //ERF_RESTHANDLERFACTORY_H
