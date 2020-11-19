#include<random>
#include "rand.hpp"

rand_gen::rand_gen(){
   
    std::default_random_engine rd;
    std::random_device random_device;

    random_num_engine   = std::mt19937(random_device());
}

int rand_gen::get_next(int min_val, int max_val){
    auto distribution = std::uniform_int_distribution<std::mt19937::result_type>(min_val, max_val);
    return distribution(random_num_engine);
}

