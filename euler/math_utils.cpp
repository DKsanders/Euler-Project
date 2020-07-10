
#include "math_utils.h"
#include <iostream>
#include <string>
#include <unordered_map>

bool is_prime(unsigned long long num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }

    unsigned long long current_factor = 2;
    while ((current_factor * current_factor) <= num)
    {
        if (num % current_factor == 0)
        {
            return false;
        }
        current_factor += 1;
    }
    return true;
}

void prime_factor_decomposition(
    unsigned long long num,
    std::vector<unsigned int>& factors,
    std::vector<unsigned int>& powers)
{
    factors.clear();
    powers.clear();

    if (num == 0 || num == 1)
    {
        return;
    }

    unsigned long long current_factor = 2;
    while(num > 1)
    {
        // Optimization: if factor^2 greater than num,
        // then num is prime.
        if ( (current_factor * current_factor) > num )
        {
            factors.push_back(num);
            powers.push_back(1);
            break;
        }

        unsigned int current_power = 0;
        if (num % current_factor == 0)
        {
            // Divide by factor until no longer divisible
            while (num % current_factor == 0)
            {
                num /= current_factor;
                ++current_power;
            }
            factors.push_back(current_factor);
            powers.push_back(current_power);
        }

        current_factor += 1;
    }
}

bool is_palindrome(unsigned long long num)
{
    std::string const& num_str = std::to_string(num);
    for (int i = 0; i < num_str.length() / 2; ++i)
    {
        if (num_str[i] != num_str[num_str.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

unsigned long long least_common_multiple(std::vector<unsigned int>& factors)
{
    std::unordered_map<unsigned int, unsigned int> prime_to_highest_power;
    for (auto factor : factors)
    {
        std::vector<unsigned int> primes;
        std::vector<unsigned int> powers;
        prime_factor_decomposition(factor, primes, powers);

        for (int i = 0; i < primes.size(); ++i)
        {
            unsigned int prime = primes[i];
            unsigned int power = powers[i];
            auto iter = prime_to_highest_power.find(prime);
            if (iter == prime_to_highest_power.end())
            {
                prime_to_highest_power[prime] = power;
            }
            else
            {
                if (power > iter->second)
                {
                    prime_to_highest_power[prime] = power;
                }
            }
        }
    }

    unsigned long long lcm = 1;
    for (auto iter : prime_to_highest_power)
    {
        lcm = lcm * pow(iter.first, iter.second);
    }
    return lcm;
}

std::vector<unsigned long long> get_factors(unsigned long long num)
{
    std::vector<unsigned long long> factors;
    for (unsigned long long i = 1; i <= num; ++i)
    {
        if (num % i == 0)
        {
            factors.push_back(i);
        }
    }
    return factors;
}