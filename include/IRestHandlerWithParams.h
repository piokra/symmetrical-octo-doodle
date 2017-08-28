//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_IRESTHANDLERWITHPARAMS_H
#define ERF_IRESTHANDLERWITHPARAMS_H

#include <Poco/JSON/Array.h>
#include <unordered_map>

namespace ERF {
    class IRestHandlerWithParams {
    public:
        virtual Poco::Dynamic::Var onGet(const std::unordered_map<std::string, std::string> &params) = 0;

        virtual Poco::Dynamic::Var onPost(Poco::JSON::Array::Ptr ptr,
                                          const std::unordered_map<std::string, std::string> &params) = 0;

        virtual Poco::Dynamic::Var onPut(Poco::JSON::Array::Ptr ptr,
                                         const std::unordered_map<std::string, std::string> &params) = 0;

        virtual Poco::Dynamic::Var onDelete(Poco::JSON::Array::Ptr ptr,
                                            const std::unordered_map<std::string, std::string> &params) = 0;
    };
}
#endif //ERF_IRESTHANDLERWITHPARAMS_H
