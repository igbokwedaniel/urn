#include <iostream>
#include <fstream>
#include "rand.hpp"
#include "util.hpp"

void test();

int main(int argc, char *argv[])
{
	
	test();
	return 0;
}

void test(){
	urn_sampler sampler{};
	sampler.get_all_draws(200,3,33);

}