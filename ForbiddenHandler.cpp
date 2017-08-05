//
// Created by panpiotr on 05.08.17.
//

#include "ForbiddenHandler.h"

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

void ForbiddenHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_FORBIDDEN);
    response.send();
}
