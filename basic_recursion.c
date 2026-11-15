#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

/*
 * Precondition: n >= 0
 * Returns n! using recursion.
 */
long long factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return (long long)n * factorial(n - 1);
}

/*
 * Precondition: n >= 0
 * Returns the nth Fibonacci number using recursion.
 */
long long fib(int n)
{
    if (n < 2)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

/*
 * Returns 0 if a is NULL or n == 0.
 * Otherwise returns the maximum value in the array recursively.
 */
int max_in_array(const int *a, size_t n)
{
    if (a == NULL || n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return a[0];
    }

    int max_rest = max_in_array(a + 1, n - 1);

    return (a[0] > max_rest) ? a[0] : max_rest;
}

/*
 * Returns true if s[i..j] is a palindrome.
 * Returns false if s is NULL.
 */
bool is_palindrome(const char *s, size_t i, size_t j)
{
    if (s == NULL)
    {
        return false;
    }

    if (i >= j)
    {
        return true;
    }

    if (s[i] != s[j])
    {
        return false;
    }

    return is_palindrome(s, i + 1, j - 1);
}

int main(void)
{
    int numbers[] = {8, 3, 14, 2, 9, 20, 5};

    const char *word1 = "racecar";
    const char *word2 = "hello";

    printf("factorial(0) = %lld\n", factorial(0));
    printf("factorial(5) = %lld\n", factorial(5));

    printf("fib(0) = %lld\n", fib(0));
    printf("fib(10) = %lld\n", fib(10));

    printf("max_in_array(numbers, 7) = %d\n",
           max_in_array(numbers, 7));

    printf("\"%s\" is palindrome: %s\n",
           word1,
           is_palindrome(word1, 0, 6) ? "true" : "false");

    printf("\"%s\" is palindrome: %s\n",
           word2,
           is_palindrome(word2, 0, 4) ? "true" : "false");

    return 0;
}
