//
// Created by PanPiotr on 2/25/2018.
//

#ifndef ERF_IBATCHRESTHANDLER_H
#define ERF_IBATCHRESTHANDLER_H

#include "IRestHandlerWithParams.h"

#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>

namespace ERF {
    class IBatchRestHandler : public ERF::IRestHandlerWithParams {
    public:
        Poco::Dynamic::Var
        onPost(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onPut(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onDelete(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;


        virtual Poco::Dynamic::Var
        onOnePost(Poco::JSON::Object::Ptr ptr, const std::unordered_map<std::string, std::string> &params) = 0;

        virtual Poco::Dynamic::Var
        onOnePut(Poco::JSON::Object::Ptr ptr, const std::unordered_map<std::string, std::string> &params) = 0;

        virtual Poco::Dynamic::Var
        onOneDelete(Poco::JSON::Object::Ptr ptr, const std::unordered_map<std::string, std::string> &params) = 0;


    };
}

#endif //ERF_IBATCHRESTHANDLER_H
