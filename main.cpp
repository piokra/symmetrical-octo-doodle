//
// Created by panpiotr on 05.08.17.
//

#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <iostream>
#include <Poco/StreamCopier.h>
#include <Poco/RegularExpression.h>
#include <Poco/Util/ServerApplication.h>
#include "RestServer.h"

using namespace Poco;
using namespace Poco::Net;
using namespace ERF;

POCO_SERVER_MAIN(RestServer);