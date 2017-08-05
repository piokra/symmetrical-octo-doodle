cmake_minimum_required(VERSION 3.5)
project(ERF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Poco REQUIRED Foundation Util Net JSON)

find_package(Threads)

set(LIBS ${LIBS} ${CMAKE_THREAD_LIBS_INIT})

include_directories(${Poco_DIRECTORIES})

set(LIBS ${LIBS} ${Poco_LIBRARIES})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        IRestHandler.h
        main.cpp RestServer.cpp RestServer.h IRestHandlerWithParams.h RestHandlerWithoutParamsProxy.cpp RestHandlerWithoutParamsProxy.h HTTPHandler.hpp URIArgsParser.cpp URIArgsParser.h RestHandlerFactory.cpp RestHandlerFactory.h RestHandlerSelector.cpp RestHandlerSelector.h ForbiddenHandler.cpp ForbiddenHandler.h EmptyRestHandler.cpp EmptyRestHandler.h examples/PrintArgsHandler.cpp examples/PrintArgsHandler.h JSONUtil.h JSONUtil.cpp)

add_executable(ERF ${SOURCE_FILES})

target_link_libraries(ERF ${LIBS})