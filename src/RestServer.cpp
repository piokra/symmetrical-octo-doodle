//
// Created by panpiotr on 05.08.17.
//

#include "ERF/RestServer.h"
#include <Poco/Net/SecureServerSocket.h>
#include "../examples/simple/PrintArgsHandler.h"

#include <Poco/Environment.h>

#include <Poco/Util/IntValidator.h>

#include <Poco/Path.h>

using namespace Poco;
using namespace Poco::Util;
using namespace Poco::Net;

void ERF::RestServer::initialize(Poco::Util::Application &self) {
    
    try {
	auto p = Path(argv()[0]);
        loadConfiguration(p.current() + "/ERF.xml");
    } catch (Exception& e) {
    	std::cout << e.displayText() << std::endl;
    }
    if (config().has("erf.config")) {
        loadConfiguration(config().getString("erf.config"));
    }

    bool ssl = config().getBool("erf.secure", false);

    Application::initialize(self);

    auto threadCount = config().getInt("erf.threads", Environment::processorCount());
    auto port = config().getInt("erf.port", 80);

    auto threadPool = new ThreadPool(1, threadCount);

    ServerSocket socket;

    if (ssl) {
        socket = SecureServerSocket(static_cast<UInt16>(port));
    } else {
        socket = ServerSocket(static_cast<UInt16>(port));
    }

    if (_selector.isNull()) {
        _selector = new RestHandlerSelector();
    }

    auto server = new HTTPServer(_selector, *threadPool, socket, new HTTPServerParams());

    _pool.reset(threadPool);

    _server.reset(server);

    _serverThread = std::make_unique<Poco::Thread>();

    _serverThread->start(*_server);

    _server->start();

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
                              .argument("value")
    );

    options.addOption(Option("secure", "sc", "Use secure server")
                              .required(false)
                              .validator(new IntValidator(0, 1))
                              .binding("erf.secure")
                              .argument("value")
    );

    options.addOption(Option("port", "p", "Port to bind to")
                              .required(false)
                              .validator(new IntValidator(0, 65535))
                              .binding("erf.port")
                              .argument("value")
    );

    options.addOption(Option("threads", "t", "Thread Count")
                              .required(false)
                              .validator(new IntValidator(0, 1000))
                              .binding("erf.threads")
                              .argument("value"));
}

