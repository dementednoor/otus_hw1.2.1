#include <algorithm>
// #include <boost/range/adaptor/reversed.hpp>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "ip_filter.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> splitInputString(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}


std::vector<int> splitIpAddress(const std::string& str, char d) {
    std::vector<int> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(std::atoi(str.substr(start, stop - start).c_str()));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(std::atoi(str.substr(start).c_str()));

    return r;
}


void print_address(std::vector<int> addr) {
    for (const auto& inner_string : addr) {
        std::cout << inner_string;
        if (&inner_string != &addr.back()) {
            std::cout << ".";
        }
    }
    std::cout << '\n';
}


// either vector or boost::reversed_range<std::vector<[int | std::string]>>
template <typename T>
void print_vector_of_addresses(T& vec) {
    // the way of printing I'm more got used to
    for (const auto& v : vec) {
        print_address(v);
    }
}

int main(/*int argc, char const *argv[]*/)
{
    try
    {
        std::vector<std::vector<int>> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = splitInputString(line, '\t');
            ip_pool.push_back(splitIpAddress(v.at(0), '.'));
        }

        std::sort(ip_pool.begin(), ip_pool.end()); 
        std::reverse(ip_pool.begin(), ip_pool.end());
        print_vector_of_addresses(ip_pool);
        // std::cout << std::endl << "------------------------------------" << std::endl;
        const auto filtered_vector1 = filter(ip_pool, 1);
        const auto filtered_vector2 = filter(ip_pool, 46, 70);
        const auto filtered_vector3 = filter_any(ip_pool, 46);
        print_vector_of_addresses(filtered_vector1);
        // std::cout << std::endl << "------------------------------------" << std::endl;
        print_vector_of_addresses(filtered_vector2);
        // std::cout << std::endl << "------------------------------------" << std::endl;
        print_vector_of_addresses(filtered_vector3);

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
