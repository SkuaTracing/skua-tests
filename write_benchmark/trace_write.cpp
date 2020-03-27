#include <iostream>
#include <fcntl.h>
#include <jaegertracing/Tracer.h>
#include <opentracing/tracer.h>

int main() 
{
	auto sampler = jaegertracing::samplers::Config(jaegertracing::kSamplerTypeConst, 1);
    auto config = jaegertracing::Config(
        false, sampler,
        jaegertracing::reporters::Config(jaegertracing::reporters::Config::kDefaultQueueSize, std::chrono::seconds(1), true));
    auto tracer = jaegertracing::Tracer::make("trace_write", config);
	opentracing::Tracer::InitGlobal(std::static_pointer_cast<opentracing::Tracer>(tracer));

	auto parent_span = opentracing::Tracer::Global()->StartSpan("request");
	
	int f = open("foo", O_WRONLY);
	int data = 0;
	for(ssize_t i = 1000; i > 0; i--) {
		auto child_span = opentracing::Tracer::Global()->StartSpan("write", { opentracing::ChildOf(&parent_span->context()) });
		write(f, &data, sizeof(data));
		child_span->Finish();
	}
	close(f);
	
	parent_span->Finish();
	opentracing::Tracer::Global()->Close();
	return 0;
}

// g++ -O3 -march=native -flto -std=c++11 trace_write.cpp -o trace_write -L/usr/local/lib/ -ljaegertracing -lopentracing