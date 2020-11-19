#include "util.hpp"
#include "rand.hpp"
#include <stdexcept>
#include<iostream>

DRAWN_URN random_draws(URN &urn, int draws, rand_gen &gen)
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
    return DRAWN_URN{urn.first,draw_bag};

}

URN get_one_cases(int colors, rand_gen &gen )
{
    std::array<int, URNSIZE> urn{};

    for(auto it = urn.begin(); it != urn.end(); it++)
        *it = gen.get_next(1,colors);

    return URN{colors,urn};
}

std::vector<URN> get_single_cases(int num_cases, int colors, rand_gen &gen )
{

    std::vector<URN> single_cases{};

    for(int i  = 0; i <num_cases ; i++)
        single_cases.push_back(get_one_cases(colors, gen));

    return single_cases;
}

std::vector<URN> get_all_cases(int per_cases, int min_color, int max_color , rand_gen &gen)
{
    std::vector<URN> all_cases{};

     for(int i  = min_color; i <= max_color ; i++)
     {
         std::vector<URN> single_cases = get_single_cases(per_cases,i,gen);
         auto end = all_cases.end();
         all_cases.insert(end,single_cases.begin(), single_cases.end());
     }

     return all_cases;
        
}

std::vector<DRAWN_URN> get_all_draws(std::vector<URN> &cases, rand_gen &gen, int samples)
{
    std::vector<DRAWN_URN> all_draws{};
    for(auto& one_case: cases)
    {
        for(int i = 0 ; i <samples ; i++)
             all_draws.push_back(random_draws(one_case,20,gen));

    }
    return all_draws;    
}

std::ostream& operator<<(std::ostream &strm, const URN &urn) {
    std::string res{""};
    res +=  std::to_string(urn.first) + " colors => [ ";
    for(auto& ball : urn.second)
        res += std::to_string(ball) + ", ";
    res += "]";
    return strm << res << std::endl ;

}

std::ostream& operator<<(std::ostream &strm, const DRAWN_URN &drawn_urn)
{
     std::string res{""};
    res +=  std::to_string(drawn_urn.first) + " colors : colors and draws => [ ";
    for(auto it = drawn_urn.second.begin(); it != drawn_urn.second.end(); it++)
    {
        res += std::to_string(it->first) + ": " + std::to_string(it->second) + ", ";
    }

    res += "]";
    return strm << res << std::endl ;


}