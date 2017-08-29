//
// Created by panpiotr on 05.08.17.
//

#include <Poco/SharedPtr.h>
#include <Poco/JSON/Object.h>
#include "../include/JSONUtil.h"


Poco::SharedPtr<Poco::JSON::Object> ERF::Util::emptyObject() {
    return new Poco::JSON::Object();
}

Poco::SharedPtr<Poco::JSON::Array> ERF::Util::emptyArray() {
    return new Poco::JSON::Array();
}
