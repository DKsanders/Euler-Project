#pragma once
#include <vector>

/**
 *  Determines whether the given number is prime
 */
bool is_prime(unsigned long long num);

/**
 *  Prime factor decomposition.
 */
void prime_factor_decomposition(
    unsigned long long num,
    std::vector<unsigned int>& factors,
    std::vector<unsigned int>& powers);

/**
 *  Determines whether the given number is a palindrome.
 */
bool is_palindrome(unsigned long long num);

/**
 *  Calculates the least common multiple of given numbers.
 */
unsigned long long least_common_multiple(std::vector<unsigned int>& factors);

/**
 *  Calculates the least common multiple of given numbers.
 */
std::vector<unsigned long long> get_factors(unsigned long long num);
