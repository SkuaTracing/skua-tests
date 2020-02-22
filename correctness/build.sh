#!/bin/bash

sudo ldconfig # rebuild shared library cache

g++ -O3 -march=native -flto -std=c++11 ~/skua-jaeger-client-cpp/build/libjaegertracing.a main.cpp -L/usr/local/lib/ -lopentracing -ljaegertracing -lpthread
