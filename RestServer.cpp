//
// Created by panpiotr on 05.08.17.
//

#include "RestServer.h"
#include "examples/PrintArgsHandler.h"

#include <Poco/Environment.h>

#include <Poco/Util/IntValidator.h>

using namespace Poco;
using namespace Poco::Util;
using namespace Poco::Net;

void ERF::RestServer::initialize(Poco::Util::Application &self) {
    loadConfiguration();

    if (config().has("erf.config")) {
        loadConfiguration(config().getString("erf.config"));
    }

    bool ssl = config().getBool("erf.secure", false);

    if (ssl) {
        initSSL();
    } else {
        initPlainText();
    }

    Application::initialize(self);
}

void ERF::RestServer::uninitialize() {
    Application::uninitialize();

    _server->stopAll(true);
    _server->stop();

    _serverThread->join();
    _pool->joinAll();

    _server = nullptr;

    _serverThread = nullptr;

    _pool = nullptr;


}

void ERF::RestServer::defineOptions(Poco::Util::OptionSet &options) {
    ServerApplication::defineOptions(options);

    options.addOption(Option("config", "cf", "Path to a config file")
                              .required(false)
                              .binding("erf.config")
    );

    options.addOption(Option("secure", "sc", "Use secure server")
                              .required(false)
                              .validator(new IntValidator(0, 1))
                              .binding("erf.secure")
    );

    options.addOption(Option("port", "p", "Port to bind to")
                              .required(false)
                              .validator(new IntValidator(0, 65535))
                              .binding("erf.port")
    );

    options.addOption(Option("cert", "pk", "SSL Certificate")
                              .required(false)
                              .binding("erf.ssl.cert"));

    options.addOption(Option("key", "k", "SSL Pub key")
                              .required(false)
                              .binding("erf.ssl.key"));

    options.addOption(Option("dcert", "dpk", "SSL Certificate Directory")
                              .required(false)
                              .binding("erf.ssl.dcert"));


    options.addOption(Option("threads", "t", "Thread Count")
                              .required(false)
                              .validator(new IntValidator(0, 1000))
                              .binding("erf.threads"));
}

void ERF::RestServer::initPlainText() {
    auto threadCount = config().getInt("erf.threads", Environment::processorCount());
    auto port = config().getInt("erf.port", 80);

    std::cout << threadCount << std::endl;

    auto threadPool = new ThreadPool(2, threadCount);

    auto socket = ServerSocket(static_cast<UInt16>(port));

    if (_selector.isNull()) {
        _selector = new RestHandlerSelector();
    }

    auto server = new HTTPServer(_selector, *threadPool, socket, new HTTPServerParams());

    _pool.reset(threadPool);

    _server.reset(server);

    _serverThread.reset(new Thread());

    _serverThread->start(*_server);
}

void ERF::RestServer::initSSL() {

}

int ERF::RestServer::main(const std::vector<std::string> &args) {
    registerHandler<PrintArgsHandler>("{asia}/{piotr}/imie:{basia}");
    _server->start();
    waitForTerminationRequest();
    std::cout << "Done" << std::endl;
}

