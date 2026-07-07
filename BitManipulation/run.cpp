#include <iostream>
using namespace std;

int clear_last_i_bits(int num, int i)
{
    int bitMask = ~((1 << i) - 1);
    return num & bitMask;
}

int clear_range_of_bits(int num, int i, int j)
{
    int bitMask = ~(((1 << (j - i + 1)) - 1) << i);
    return num & bitMask;
}

bool is_power_of_two(int num)
{
    return (num > 0) && ((num & (num - 1)) == 0);
}

int count_set_bits(int num)
{
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int fast_exponentiation(int base, int exponent)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            result *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return result;
}

int main()
{
    // Clearing last i bits
    int num = 15; // Example number
    int i = 2; // Example position
    cout << clear_last_i_bits(num, i) << endl;
}