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
	rand_gen gen{};
	std::ofstream testFile ("test_result.csv");

	auto cases = get_all_cases(100,3,33,gen);
	auto my_draws = get_all_draws(cases,gen,2000);

	std::for_each(my_draws.begin(), my_draws.end(), [&](DRAWN_URN &draw)
	{
		int colors_in_box{draw.first};
		int colors_picked{draw.second.size()};
		testFile << colors_in_box << "," << colors_picked << std::endl;
	});
	
	testFile.close();

}