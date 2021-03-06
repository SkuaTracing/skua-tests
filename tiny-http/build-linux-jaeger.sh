#!/bin/bash

pushd ~/jaeger-client-cpp-0.3.0/build
make install
popd

g++ -O3 -march=native -flto -std=c++11 -lopentracing -ljaegertracing -lssl -lz -lcrypto -luv -luWS ~/jaeger-client-cpp-0.3.0/build/libjaegertracing.a test.cpp
