// Author : luowei

//leetcode
/********************************************************************************** 
* 
* Given an array of integers, every element appears twice except for one. Find that single one.

*Note:
*Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*Tags: Hash Table Bit Manipulation
**********************************************************************************/
//lintcode
/*
给出2*n + 1 个的数字，除其中一个数字之外其他每个数字均出现两次，找到这个数字。

样例:
	给出 [1,2,2,1,3,4,3]，返回 4
挑战:
	一次遍历，常数级的额外空间复杂度
标签:
	贪心
*/
int singleNumber(int A[], int n) {
    int result=0;
    for(int i=0;i<n;i++){
        result^=A[i];
    }
    return result;
}