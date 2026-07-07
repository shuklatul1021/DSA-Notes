//              Bit Manipulation
/**
 * Bit is an Technique to manipulate data at the bit level. 
 * It is a very efficient way to store and process data. 
 * Bit manipulation is used in many applications such as cryptography, compression, and error detection/correction.
 * It is a process of performing operations on individual bits of data. The basic operations include AND
 */

/**
 * Decimal To Binary Conversion
 * Example: Decimal Number 20
 * Binary Representation of 20 is 10100
 * 
 */
/**
 * Binary To Decimal Conversion
 * Example: Binary Number 10100
 *  1 *  2^4 + 0 * 2^3 + 1 * 2^2 + 0 * 2^1 + 0 * 2^0 = 16 + 0 + 4 + 0 + 0 = 20
 * Decimal Representation of 10100 is 20
 */

/**
 * Bitwise Operators
 * Binary AND (&): Compares each bit of the first operand to the corresponding bit of the second operand. If both bits are 1, the corresponding result bit is set to 1. Otherwise, it is set to 0.
 * Binary OR (|): Compares each bit of the first operand to the corresponding bit of the second operand. If either bit is 1, the corresponding result bit is set to 1. Otherwise, it is set to 0.
 * Binary XOR (^): Compares each bit of the first operand to the corresponding bit of the second operand. If the bits are different, the corresponding result bit is set to 1. Otherwise, it is set to 0.
 * Binary NOT (~): Inverts each bit of the operand. If a bit is 0, it becomes 1, and if it is 1, it becomes 0.
 * Left Shift (<<): Shifts the bits of the first operand to the left by the specified number of positions.
 * Right Shift (>>): Shifts the bits of the first operand to the right by the specified number of positions.
 */

/**
 * Binary AND (&) Operator( * = Multiplication )
 * Example: 5 & 6
 * 5 in binary: 101
 * 6 in binary: 110
 * Result: 100 (4 in decimal)
 */

/**
 * Binary OR (|) Operator( + = Addition )
 * Example: 5 | 6
 * 5 in binary: 101
 * 6 in binary: 110
 * Result: 111 (7 in decimal)
 */

/**
 * Binary XOR (^) Operator( + = Addition )
 * Example: 5 ^ 6
 *  Same : 0
 *  Different : 1
 * 
 * 5 in binary: 101
 * 6 in binary: 110
 * Result: 011 (3 in decimal)
 */

 /**
 * Binary NOT (~) Operator complement
 * Example: ~5
 * 5 in binary: 0000 0101
 * Result: 1111 1010 (2s complement then it becomes) (-6 in decimal, using two's complement representation)
 */

/**
 * Left Shift (<<) Operator
 * Example: 5 << 1
 * 5 in binary: 0000 0101
 * Result: 0000 1010 (10 in decimal)
 */

/**
 * Right Shift (>>) Operator
 * Example: 5 >> 1
 * 5 in binary: 0000 0101
 * Result: 0000 0010 (2 in decimal)
 */
 
 // Odd and even number check using bitwise operator
#include <iostream>
using namespace std;

int main()
{
    int num = 6; // Example number
    int bitMask = 1;

    if((num & bitMask) == 0){
        cout<<"Even"<<endl;
    } else {
        cout<<"Odd"<<endl;
    }

    return 0;
}

/**
 * Operation In Bits
 * 1. Get i th bit
 * 2. Set i th bit
 * 3. Clear i th bit
 */
int main()
{
    // For Setting i th bit  
    int num = 6; // Example number
                       
    int bitMask = 1 << 2; // 1 << i (ith postion)

    if((num & bitMask) == 0){
        cout<<"0"<<endl;
    } else {
        cout<<"1"<<endl;
    } 

    return 0;
}

int main()
{
    // For Getting i th bit 
    int num = 6; // Example number
                       
    int bitMask = 1 << 2; // 1 << i (ith postion)

    if((num | bitMask) == 0){
        cout<<"0"<<endl;
    } else {
        cout<<"1"<<endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    // For Clear  i th bit 
    int num = 6; // Example number
                       
    int bitMask = ~(1 << 2); // 1 << i (ith postion)

    if((num & bitMask) == 0){
        cout<<"0"<<endl;
    } else {
        cout<<"1"<<endl;
    }

    return 0;
}

