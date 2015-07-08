// Author : luowei

//leetcode
/********************************************************************************** 
* 
* Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Tags: Bit Manipulation
**********************************************************************************/

//lintcode
/*
给出3*n + 1 个的数字，除其中一个数字之外其他每个数字均出现三次，找到这个数字。

样例:
    给出 [1,1,2,3,3,3,2,2,4,1] ，返回 4
挑战:
    一次遍历，常数级的额外空间复杂度
标签:
    贪心
*/
class Solution {
public:
    //将3改为k即为此题通用
    int singleNumber(int A[], int n) {
        int result = 0;
        int bits[32] = { 0 };
        for (int i = 0; i < 32; i++){
            for (int j = 0; j < n; j++){
                if ((A[j] >> i) & 1u)
                    bits[i]++;
            }
            result |= (bits[i] % 3)<<i;
        }

        return result;
    }
};
