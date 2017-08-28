//
// Created by piotr on 8/28/17.
//

#ifndef ERF_SIMPLESERVER_HPP
#define ERF_SIMPLESERVER_HPP

#include <RestServer.h>

namespace ERF {
    class SimpleServer : public RestServer {
    protected:
        int main(const std::vector<std::string> &args) override;
    };
}

#endif //ERF_SIMPLESERVER_HPP
