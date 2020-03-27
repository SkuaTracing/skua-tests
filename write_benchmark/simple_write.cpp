#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() 
{
	int f = open("too", O_WRONLY);
	
	int data = 0;
	for(ssize_t i = 1000; i > 0; i--) {
	  write(f, &data, sizeof(data));
	}
	close(f);
	return 0;	
}

// g++ -O3 -march=native -flto -std=c++11 simple_write.cpp -o simple_write -L/usr/local/lib/