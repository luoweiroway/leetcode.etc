// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : luowei

//leetcode
/*****************************************
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:
    Special thanks to @ts for adding this problem and creating all test cases.

Tags: 
    Bit Manipulation 
*******************************************/

//lintcode
/*
计算在一个 32 位的整数的二进制表式中有多少个 1.

样例:
    给定 32 (100000)，返回 1
    给定 5 (101)，返回 2
    给定 1023 (111111111)，返回 9
标签: 
    二进制 比特位操作
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int count = 0;
        /*while (num != 0) {
            num &= num-1;
            count++;
        }*/
        while (num != 0) {
            if ((num & 1) == 1)
                count++;
            num = num>>1;
        }
        return count;
    }
};