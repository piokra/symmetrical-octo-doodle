//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_JSONUTIL_H
#define ERF_JSONUTIL_H


#include <Poco/SharedPtr.h>

#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>

namespace Poco {
    namespace JSON {
        class Object;

        class Array;
    }
}

namespace ERF {
    namespace Util {
        Poco::SharedPtr<Poco::JSON::Object> emptyObject();

        Poco::SharedPtr<Poco::JSON::Array> emptyArray();


        inline Poco::JSON::Array::Ptr fillArray(Poco::JSON::Array::Ptr ptr) {
            return ptr;
        }

        template<typename T, typename...Ts>
        inline Poco::JSON::Array::Ptr fillArray(Poco::JSON::Array::Ptr array, const T &t, const Ts &...ts) {
            array->add(t);
            return fillArray(array, ts...);
        };

        template<typename T, typename...Ts>
        inline Poco::SharedPtr<Poco::JSON::Array> array(const T &t, const Ts &...ts) {
            auto ret = emptyArray();
            return fillArray(ret, t, ts...);
        };


    }
}

#endif //ERF_JSONUTIL_H
