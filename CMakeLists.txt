cmake_minimum_required(VERSION 3.5)
project(ERF)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
# find_package(Poco REQUIRED Net JSON)
# list(FILTER Poco_LIBRARIES EXCLUDE REGEX optimized)

# find_package(Threads)

# set(LIBS ${LIBS} ${CMAKE_THREAD_LIBS_INIT})

include_directories(${Poco_DIRECTORIES})
INCLUDE_DIRECTORIES(${Poco_INCLUDE_DIRS})
include_directories("include/")

# set(LIBS ${LIBS} ${Poco_LIBRARIES} -pthread -lPocoFoundation -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoJSON)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        include/ERF/IRestHandler.h
        src/RestServer.cpp include/ERF/RestServer.h include/ERF/IRestHandlerWithParams.h src/RestHandlerWithoutParamsProxy.cpp include/ERF/RestHandlerWithoutParamsProxy.h include/ERF/HTTPHandler.hpp src/URIArgsParser.cpp include/ERF/URIArgsParser.h src/RestHandlerFactory.cpp include/ERF/RestHandlerFactory.h src/RestHandlerSelector.cpp include/ERF/RestHandlerSelector.h src/ForbiddenHandler.cpp include/ERF/ForbiddenHandler.h src/EmptyRestHandler.cpp include/ERF/EmptyRestHandler.h include/ERF/JSONUtil.h src/JSONUtil.cpp)

# MESSAGE(${LIBS})

set(SIMPLE_EXAMPLE_FILES ${SOURCE_FILES} examples/simple/main.cpp examples/simple/PrintArgsHandler.h examples/simple/PrintArgsHandler.cpp examples/simple/SimpleServer.cpp examples/simple/SimpleServer.hpp)

add_executable(SimpleExample ${SIMPLE_EXAMPLE_FILES})

configure_file(ERF.xml ERF.xml COPYONLY)
configure_file(server.key server.key COPYONLY)
configure_file(server.cert server.cert COPYONLY)

target_link_libraries(SimpleExample ${LIBS})

add_library(ERF SHARED ${SOURCE_FILES})

target_link_libraries(ERF ${LIBS))
