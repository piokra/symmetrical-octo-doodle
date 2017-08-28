//
// Created by piotr on 8/28/17.
//

#include "SimpleServer.hpp"
#include "PrintArgsHandler.h"

int ERF::SimpleServer::main(const std::vector<std::string> &args) {
    registerHandler<PrintArgsHandler>("simple/{example}");
    waitForTerminationRequest();
}
