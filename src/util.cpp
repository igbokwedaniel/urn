#include "util.hpp"
#include "rand.hpp"
#include <stdexcept>
#include<iostream>


urn_sampler::urn_sampler()
{
    gen = rand_gen{};
    test_file_strm = std::ofstream{file_name};
    
}

void urn_sampler::random_draws(URN &urn, int draws)
{
    if (draws > URNSIZE)
    {
        throw std::invalid_argument("Nunber of Draws Greater than Urn size!");
    }

    std::map<int, int> draw_bag{};
    std::map<int, bool> drawn{};


    while(draws > 0)
    {
        
        int pick{gen.get_next(0,URNSIZE-1)};
        if(drawn[pick])
            continue;

        drawn[pick] = true;
        ++draw_bag[urn.second[pick]];
        --draws;

    }
    
    DRAWN_URN drawn_urn{urn.first, draw_bag};
    
    test_file_strm << urn.first << "," << draw_bag.size()  << drawn_urn << std::endl;
}

void urn_sampler::get_one_cases(int colors)
{
    std::array<int, URNSIZE> urn{};

    for(auto it = urn.begin(); it != urn.end(); it++)
        *it = gen.get_next(1,colors);

    random_draws(urn, draws)
}

void urn_sampler::get_single_cases(int num_cases, int colors)
{
    for(int i  = 0; i <num_cases ; i++)
        get_one_cases(colors);
}

void urn_sampler::get_all_cases(int per_cases, int min_color, int max_color)
{


     for(int i  = min_color; i <= max_color ; i++)
     {
         get_single_cases(per_cases,i);
     }

 
        
}

void urn_sampler::get_all_draws(int per_cases, int min_color, int max_color)
{
    get_all_cases(per_cases, min_color, max_color);
    test_file_strm.close();
      
}

std::ostream& operator<<(std::ostream &strm, const URN &urn) {
    std::string res{""};
    res +=  std::to_string(urn.first) + " colors => [ ";
    for(auto& ball : urn.second)
        res += std::to_string(ball) + " ";
    res += "]";
    return strm << res << std::endl ;

}

std::ostream& operator<<(std::ostream &strm, const DRAWN_URN &drawn_urn)
{
     std::string res{""};
    res +=  std::to_string(drawn_urn.first) + " colors : colors and draws => [ ";
    for(auto it = drawn_urn.second.begin(); it != drawn_urn.second.end(); it++)
    {
        res += std::to_string(it->first) + ": " + std::to_string(it->second) + " ";
    }

    res += "]";
    return strm << res << std::endl ;


}
