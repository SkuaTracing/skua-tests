#!/bin/bash

#pushd ~/jaeger-client-cpp/build
#make install
#popd
sudo ldconfig
#g++ -O3 -march=native -flto -std=c++11 -lopentracing -ljaegertracing -lpthread ~/jaeger-client-cpp/build/libjaegertracing.a main.cpp
g++ -O3 -march=native -flto -std=c++11 ~/skua-jaeger-client-cpp/build/libjaegertracing.a main.cpp -L/usr/local/lib/ -lopentracing -ljaegertracing -lpthread
