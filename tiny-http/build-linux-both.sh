#!/bin/bash

pushd ~/jaeger-client-cpp/build
make install
popd

g++ -O3 -march=native -flto -std=c++11 -lopentracing -ljaegertracing -lssl -lz -lcrypto -luv -luWS $@ ~/jaeger-client-cpp/build/libjaegertracing.a test.cpp
