#include<utility>
#include<map>
#include<algorithm>
#include<vector>
#include "rand.hpp"


#ifndef _URN_UTIL
#define _URN_UTIL

static const std::size_t URNSIZE = 50;
typedef std::pair<int, std::map<int, int>> DRAWN_URN;
typedef std::pair<int, std::array<int, URNSIZE>> URN;


/**
 * Utility Functions
 * 1. Functions for simulating random draws from the box
 * 2. Getting the basket for all different scenarios accross all color combinations
 * 3. Getting the basket for different scenarios for just one color
 * 4. getting single scenario for one one coloe
 * Fn 2-4 defined to prevent complicated nested loops
 * 5.Output stream for urn
 * 6. Simulate the draws fom the urn 
**/

DRAWN_URN random_draws(URN &urn, int draws, rand_gen &gen);

std::vector<URN> get_all_cases(int per_cases, int min_color, int max_color, rand_gen &gen);

std::vector<URN> get_single_cases(int num_cases, int colors , rand_gen &gen);

URN get_one_cases(int colors , rand_gen &gen);

std::ostream& operator<<(std::ostream &strm, const URN &urn);

std::ostream& operator<<(std::ostream &strm, const DRAWN_URN &drawn_urn);

std::vector<DRAWN_URN> get_all_draws(std::vector<URN> &cases, rand_gen &gen, int samples);


#endif