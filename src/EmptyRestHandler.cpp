//
// Created by panpiotr on 05.08.17.
//

#include "ERF/EmptyRestHandler.h"

Poco::Dynamic::Var
ERF::EmptyRestHandler::onGet(const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Not implemented");
}

Poco::Dynamic::Var
ERF::EmptyRestHandler::onPost(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Not implemented");
}

Poco::Dynamic::Var
ERF::EmptyRestHandler::onPut(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Not implemented");
}

Poco::Dynamic::Var
ERF::EmptyRestHandler::onDelete(Poco::JSON::Array::Ptr ptr,
                                const std::unordered_map<std::string, std::string> &params) {
    throw Poco::Exception("Not implemented");
}
