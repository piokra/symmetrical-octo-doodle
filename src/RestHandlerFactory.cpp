//
// Created by panpiotr on 05.08.17.
//

#include "../include/RestHandlerFactory.h"

bool ARestHandlerFactory::wants(const std::string &uri) {
    return _parser.matches(uri);
}

const URIArgsParser &ARestHandlerFactory::parser() {
    return _parser;
}

ARestHandlerFactory::ARestHandlerFactory(const std::string &pattern) : _parser(pattern) {

}
