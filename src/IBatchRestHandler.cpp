//
// Created by PanPiotr on 2/25/2018.
//

#include "ERF/IBatchRestHandler.h"

#include "ERF/JSONUtil.h"

#define RETURN_ARRAY(METHOD) \
do {\
auto retArray = ERF::Util::emptyArray();\
\
for (auto it = ptr->begin(); it != ptr->end(); ++it) {\
retArray->add(METHOD(it->extract<Poco::JSON::Object::Ptr>(), params));\
}\
\
return retArray;\
} while(0)

Poco::Dynamic::Var
ERF::IBatchRestHandler::onPost(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) {
    RETURN_ARRAY(onOnePost);
}

Poco::Dynamic::Var
ERF::IBatchRestHandler::onPut(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) {
    RETURN_ARRAY(onOnePut);
}

Poco::Dynamic::Var ERF::IBatchRestHandler::onDelete(Poco::JSON::Array::Ptr ptr,
                                                    const std::unordered_map<std::string, std::string> &params) {
    RETURN_ARRAY(onOneDelete);
}

ERF::IBatchRestHandler::IBatchRestHandler(const Poco::Net::HTTPRequest &request) : IRestHandlerWithParams(request) {}

#undef RETURN_ARRAY
