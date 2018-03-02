//
// Created by PanPiotr on 2/25/2018.
//

#ifndef ERF_EMPTYBATCHHANDLER_H
#define ERF_EMPTYBATCHHANDLER_H

#include "IBatchRestHandler.h"
namespace ERF {
    class EmptyBatchRestHandler : public IBatchRestHandler {
    public:
        Poco::Dynamic::Var
        onPost(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onPut(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onDelete(Poco::JSON::Array::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onOnePost(Poco::JSON::Object::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onOnePut(Poco::JSON::Object::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var
        onOneDelete(Poco::JSON::Object::Ptr ptr, const std::unordered_map<std::string, std::string> &params) override;

        Poco::Dynamic::Var onGet(const std::unordered_map<std::string, std::string> &params) override;
    };
}

#endif //ERF_EMPTYBATCHHANDLER_H
