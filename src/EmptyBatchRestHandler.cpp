//
// Created by PanPiotr on 2/25/2018.
//

#include "ERF/EmptyBatchRestHandler.h"

#include "ERF/JSONUtil.h"

using namespace ERF::Util;

Poco::Dynamic::Var ERF::EmptyBatchRestHandler::onOnePost(Poco::JSON::Object::Ptr ptr,
                                                         const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Method not implemented");
}

Poco::Dynamic::Var ERF::EmptyBatchRestHandler::onOnePut(Poco::JSON::Object::Ptr ptr,
                                                        const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Method not implemented");
}

Poco::Dynamic::Var ERF::EmptyBatchRestHandler::onOneDelete(Poco::JSON::Object::Ptr ptr,
                                                           const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Method not implemented");
}

Poco::Dynamic::Var ERF::EmptyBatchRestHandler::onGet(const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Method not implemented");
}

ERF::EmptyBatchRestHandler::EmptyBatchRestHandler(const Poco::Net::HTTPRequest &request) : IBatchRestHandler(request) {}


#define DEBATCH(METHOD) \
auto ret = emptyArray(); \
for (auto &&item : *ptr) { \
try { \
auto json = item.extract<Poco::JSON::Object::Ptr>(); \
ret->add(METHOD(json, params)); \
} catch (Poco::Exception& e) { \
auto errObj = emptyObject(); \
emptyObject()->set("error", e.displayText()); \
} \
} \
return ret \

Poco::Dynamic::Var ERF::EmptyBatchRestHandler::onPost(Poco::JSON::Array::Ptr ptr,
                                                      const std::unordered_map<std::string, std::string> &params) {
    DEBATCH(onOnePost);
}

Poco::Dynamic::Var ERF::EmptyBatchRestHandler::onPut(Poco::JSON::Array::Ptr ptr,
                                                     const std::unordered_map<std::string, std::string> &params) {
    DEBATCH(onOnePut);
}

Poco::Dynamic::Var ERF::EmptyBatchRestHandler::onDelete(Poco::JSON::Array::Ptr ptr,
                                                        const std::unordered_map<std::string, std::string> &params) {
    DEBATCH(onOneDelete);
}
