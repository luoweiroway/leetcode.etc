// Author : luowei

//lintcode
/*
分割一个整数数组，使得奇数在前偶数在后。

样例：
    给定 [1, 2, 3, 4]，返回 [1, 3, 2, 4]。

挑战：
    在原数组中完成，不使用额外空间。

标签：
    两根指针 数组
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    //此问题本质上与问题“sort-letters-by-case”一样
    
    
    /*方法一，左右两个指针，一趟快排,时间O(n);
    *与问题“sort-letters-by-case”的方法一一样，其实这两个问题本质上是一样的
    */
    /*void partitionArray(vector<int> &nums) {
        // write your code here
        int start = 0, end = nums.size() - 1;
        
        while (start < end) {
            while (start < end && (nums[start] & 1) == 1) start++;
            while (start < end && (nums[end] & 1) == 0) end--;
            swap(nums[start],nums[end]);
        }
    }*/
    
    /*方法二，主从两个指针，也是快排思想的体现，一次遍历，时间O(n);
    *与问题“sort-letters-by-case”的方法二一样
    */
    /*void partitionArray(vector<int> &nums) {
        int odd_end = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1 == 1) {
                swap(nums[i],nums[odd_end]);
                odd_end++;
            }
        }
    }*/
    
    /*方法三，基于方法二实现一个保持顺序不变的方案，时间介于O(n)与O(n*n)之间;
     *与问题“sort-letters-by-case”的方法三一样
     */
    void partitionArray(vector<int> &nums) {
        int odd_end = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & 1 == 1){
                int temp=nums[i];
                for(int j=i;j>odd_end;j--){
                    nums[j]=nums[j-1];
                }
                nums[odd_end]=temp;
                
                odd_end++;
            }
        }
    }
};
