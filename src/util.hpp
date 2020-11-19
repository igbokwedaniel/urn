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

class urn_sampler{
  
public:
  void get_all_draws(int per_cases, int min_color, int max_color);
  urn_sampler();
  
  
private:
  
  std::string file_name{"test_result.csv"};
  
  void random_draws(URN &urn, int draws);

  void get_all_cases(int per_cases, int min_color, int max_color);

  void get_single_cases(int num_cases, int colors);

  void get_one_cases(int colors);


  
}

std::ostream& operator<<(std::ostream &strm, const URN &urn);

std::ostream& operator<<(std::ostream &strm, const DRAWN_URN &drawn_urn);




#endif
