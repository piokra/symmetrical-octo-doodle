//
// Created by panpiotr on 05.08.17.
//

#include <Poco/JSON/Object.h>
#include "PrintArgsHandler.h"
#include "../../include/JSONUtil.h"

using namespace Poco;
using namespace Poco::JSON;

using namespace ERF;
using namespace ERF::Util;

Poco::Dynamic::Var
ERF::PrintArgsHandler::onGet(const std::unordered_map<std::string, std::string> &params) {
    auto json = emptyObject();
    for (auto &pair: params) {
        json->set(pair.first, pair.second);
    }

    return array(json);
}
