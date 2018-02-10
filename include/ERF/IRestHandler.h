//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_IRESTHANDLER_H
#define ERF_IRESTHANDLER_H

#include <Poco/JSON/Array.h>
#include <Poco/JSON/Object.h>

namespace ERF {
    class IRestHandler {
    public:
        virtual Poco::Dynamic::Var onGet() = 0;

        virtual Poco::Dynamic::Var onPost(Poco::JSON::Array::Ptr ptr) = 0;

        virtual Poco::Dynamic::Var onPut(Poco::JSON::Array::Ptr ptr) = 0;

        virtual Poco::Dynamic::Var onDelete(Poco::JSON::Array::Ptr ptr) = 0;
    };
}
#endif //ERF_IRESTHANDLER_H
