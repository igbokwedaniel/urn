#include<cmath>
#include<random>


#ifndef _RANDOM_GENERATOR
#define _RANDOM_GENERATOR

/**
 * Random Numbr generator base class with default
 * Mersene Twister Engine and Uniform Distribution  function
 **/
class rand_gen
{
    public:
 
        rand_gen();
        int get_next(int min_val, int max_val); 
    
    protected:
        std::mt19937 random_num_engine;
        
};

#endif