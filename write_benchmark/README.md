# Write operation benchmark

#### In the directory you will see two c++ file:

- Simple_write will simply write for 1000 time.

- Trace_write will write for 1000 time with SKUA enabled.

#### Instruction:

##### For simple_write.cpp:

```shell
g++ -O3 -march=native -flto -std=c++11 simple_write.cpp -o simple_write -L/usr/local/lib/

# create a new target file to write:
rm too && touch too

# use time for timing the operation
time ./simple_write
```

##### For trace_write.cpp:

```shell
g++ -O3 -march=native -flto -std=c++11 trace_write.cpp -o trace_write -L/usr/local/lib/ -ljaegertracing -lopentracing

# go to skua directory for further operation
cd ~/skua
./start-tracing.sh

# open another terminal window:
cd ~/skua
rm foo && touch foo
time ./trace-process.sh ~/test/write_test/trace_write
```

#####The result with our spec:
On Mass Open Cloud:

1. **Flavor**: m1.s2.xlarge & 50+ GB Volume (comply kernel takes space)
2. **OS**: Ubuntu 18 LTS
3. **Security Group** need to open the following ports for **Ingress** and **Egress**
	
	TCP: 5000, 5778, 9411, 14268, 16686, 22, 80, 443
	
	UDP: 5775, 6831, 6832
	
###simple_write:
```shell
# 1
real    0m0.014s
user    0m0.005s
sys     0m0.009s
# 2
real    0m0.010s
user    0m0.000s
sys     0m0.010s
# 3
real    0m0.008s
user    0m0.000s
sys     0m0.007s
# 4
real    0m0.008s
user    0m0.004s
sys     0m0.004s
# 5
real    0m0.010s
user    0m0.000s
sys     0m0.010s
# 6
real    0m0.016s
user    0m0.000s
sys     0m0.012s
# 7
real    0m0.018s
user    0m0.001s
sys     0m0.017s
# 8
real    0m0.008s
user    0m0.000s
sys     0m0.008s
# 9
real    0m0.012s
user    0m0.000s
sys     0m0.012s
# 10
real    0m0.015s
user    0m0.006s
sys     0m0.007s
```

###trace_write:
```shell
# 1
real    0m0.363s
user    0m0.228s
sys     0m0.126s
# 2
real    0m0.332s
user    0m0.229s
sys     0m0.131s
# 3
real    0m0.311s
user    0m0.186s
sys     0m0.159s
# 4
real    0m0.330s
user    0m0.233s
sys     0m0.129s
# 5
real    0m0.483s
user    0m0.202s
sys     0m0.200s
# 6
real    0m0.392s
user    0m0.214s
sys     0m0.170s
# 7
real    0m0.419s
user    0m0.227s
sys     0m0.178s
# 8
real    0m0.543s
user    0m0.305s
sys     0m0.176s
# 9
real    0m0.459s
user    0m0.322s
sys     0m0.136s
# 10
real    0m0.418s
user    0m0.254s
sys     0m0.131s
```