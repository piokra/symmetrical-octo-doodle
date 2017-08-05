//
// Created by panpiotr on 05.08.17.
//

#ifndef ERF_PRINTARGSHANDLER_H
#define ERF_PRINTARGSHANDLER_H

#include "../EmptyRestHandler.h"

namespace ERF {
    class PrintArgsHandler : public EmptyRestHandler {
    public:
        Poco::Dynamic::Var
        onGet(const std::unordered_map<std::string, std::string> &params) override;
    };
}

#endif //ERF_PRINTARGSHANDLER_H
