//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_FORBIDDENHANDLER_H
#define ERF_FORBIDDENHANDLER_H


#include <Poco/Net/HTTPRequestHandler.h>

class ForbiddenHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;
};


#endif //ERF_FORBIDDENHANDLER_H
