// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : luowei

/********************************************************************************** 
* 
* Given an array of integers, every element appears twice except for one. Find that single one.
*
*Note:
*Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*Tags: Hash Table Bit Manipulation

本题扩展
1.一个数组中有两个元素只出现一次，其他所有元素都出现两次，求这两个只出现一次的元素
2.一个数组中有一个元素只出现1次，其他所有元素都出现k次，求这个只出现1次的元素,见single number II
**********************************************************************************/

#include <stdio.h>

int singleNumber(int A[], int n) {
    int result=0;
    for(int i=0;i<n;i++){
        result^=A[i];
    }
    return result;
}

int main()
{
    int a[] = { 1, 1, 2, 2, 3, 3, 4 };
	printf("%d\n", singleNumber(a, 7));
    return 0;
}
