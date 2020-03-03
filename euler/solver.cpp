#include <vector>

#include "solver.h"
#include "math_utils.h"

void Solver::problem1()
{
    unsigned int sum = 0;
    for (int i = 0; i < 1000; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}

void Solver::problem2()
{
    // 2 of the previous Fibonacci terms
    unsigned int prev1 = 0;
    unsigned int prev2 = 1;

    unsigned int sum = 0;
    while (prev2 < 4000000)
    {
        unsigned int current = prev1 + prev2;
        if (current % 2 == 0)
        {
            sum += current;
        }
        prev1 = prev2;
        prev2 = current;
    }
    std::cout << sum << std::endl;
}

void Solver::problem3()
{
    std::vector<unsigned int> factors;
    std::vector<unsigned int> powers;
    prime_factor_decomposition(600851475143, factors, powers);
    unsigned int largest_prime_factor = factors[factors.size() - 1];

    std::cout << largest_prime_factor << std::endl;
}

void Solver::problem4()
{
    int n = 3;
    unsigned int lower_bound = 0;
    unsigned int uppwer_bound = pow(10, n);
    unsigned int max_palindrome = 0;
    for (int i = uppwer_bound; i > lower_bound; --i)
    {
        for (int j = i; j > lower_bound; --j)
        {
            unsigned int prod = i * j;
            if (is_palindrome(prod))
            {
                if (prod > max_palindrome)
                {
                    max_palindrome = prod;
                    lower_bound = j;
                }
            }
        }
    }

    std::cout << max_palindrome << std::endl;
}