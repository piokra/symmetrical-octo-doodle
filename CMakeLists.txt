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

# set(LIBS ${LIBS} ${Poco_LIBRARIES})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        include/IRestHandler.h
        src/RestServer.cpp include/RestServer.h include/IRestHandlerWithParams.h src/RestHandlerWithoutParamsProxy.cpp include/RestHandlerWithoutParamsProxy.h include/HTTPHandler.hpp src/URIArgsParser.cpp include/URIArgsParser.h src/RestHandlerFactory.cpp include/RestHandlerFactory.h src/RestHandlerSelector.cpp include/RestHandlerSelector.h src/ForbiddenHandler.cpp include/ForbiddenHandler.h src/EmptyRestHandler.cpp include/EmptyRestHandler.h include/JSONUtil.h src/JSONUtil.cpp)

# MESSAGE(${LIBS})

set(SIMPLE_EXAMPLE_FILES ${SOURCE_FILES} examples/simple/main.cpp examples/simple/PrintArgsHandler.h examples/simple/PrintArgsHandler.cpp examples/simple/SimpleServer.cpp examples/simple/SimpleServer.hpp)

add_executable(SimpleExample ${SIMPLE_EXAMPLE_FILES})

configure_file(ERF.xml ERF.xml COPYONLY)
configure_file(server.key server.key COPYONLY)
configure_file(server.cert server.cert COPYONLY)

target_link_libraries(SimpleExample ${LIBS} -pthread -lPocoFoundation -lPocoNet -lPocoNetSSL)

add_library(ERF SHARED ${SOURCE_FILES})

target_link_libraries(ERF ${LIBS} -pthread -lPocoFoundation -lPocoNet -lPocoNetSSL) # My FindPoco.cmake fails to find PocoNetSSL
