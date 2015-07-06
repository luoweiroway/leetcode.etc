// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : luowei

/********************************************************************************** 
* 
* Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Tags Bit Manipulation

本题扩展
1.一个数组中有两个元素只出现一次，其他所有元素都出现两次，求这两个只出现一次的元素
2.一个数组中有一个元素只出现1次，其他所有元素都出现k次，求这个只出现1次的元素
**********************************************************************************/

class Solution {
public:
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


//以下代码为测试运行用
int main()
{
    int a[] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4};
	Solution solution;
	printf("%d\n", solution.singleNumber(a, 10));
    return 0;
}
