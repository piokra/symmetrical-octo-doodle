//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_EMPTYRESTHANDLER_H
#define ERF_EMPTYRESTHANDLER_H

#include "IRestHandlerWithParams.h"

namespace ERF {
    class EmptyRestHandler : public IRestHandlerWithParams {
    public:
        Poco::Dynamic::Var
        onGet(const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onPost(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onPut(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onDelete(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;
    };
}

#endif //ERF_EMPTYRESTHANDLER_H
