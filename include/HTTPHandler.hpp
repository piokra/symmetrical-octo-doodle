//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_HTTPHANDLER_HPP
#define ERF_HTTPHANDLER_HPP

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/MediaType.h>
#include <Poco/JSON/Parser.h>
#include <Poco/StreamCopier.h>
#include "URIArgsParser.h"

template<typename RHandler>
class HTTPHandler : public Poco::Net::HTTPRequestHandler {
public:
    HTTPHandler(const URIArgsParser &_parser) : _parser(_parser) {}

    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override {

        try {


            Poco::JSON::Array::Ptr array;
            if (request.getMethod() != Poco::Net::HTTPRequest::HTTP_GET) {

                Poco::JSON::Parser parser;
                auto var = parser.parse(request.stream());

                try {
                    auto object = var.extract<Poco::JSON::Object::Ptr>();
                    array = new Poco::JSON::Array();
                    array->add(object);
                } catch (Poco::BadCastException &e) {
                    array = var.extract<Poco::JSON::Array::Ptr>();
                }
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET) {
                sendJson(request, response,
                         _handler.onGet(_parser.parse(request.getURI())));
                return;
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST) {
                sendJson(request, response,
                         _handler.onPost(array, _parser.parse(request.getURI())));
                return;
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT) {
                sendJson(request, response,
                         _handler.onPut(array, _parser.parse(request.getURI())));
                return;
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE) {
                sendJson(request, response,
                         _handler.onDelete(array, _parser.parse(request.getURI())));
                return;
            }

            response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_UNKNOWN);
            response.send();

        } catch (Poco::JSON::JSONException &e) {
            std::cout << e.displayText() << std::endl;
            response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_BAD_REQUEST);
            response.send();
        } catch (Poco::Exception &e) {
            std::cout << e.displayText() << std::endl;
            response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_METHOD_NOT_ALLOWED);
            response.send();
        }
    }

protected:
    void sendJson(Poco::Net::HTTPServerRequest &request,
                  Poco::Net::HTTPServerResponse &response,
                  Poco::Dynamic::Var ptr) {

        response.setContentType("application/json");

        response.setChunkedTransferEncoding(true);
        Poco::JSON::Stringifier::stringify(ptr, response.send());
    }

private:
    const URIArgsParser &_parser;
    RHandler _handler;
};


#endif //ERF_HTTPHANDLER_HPP
