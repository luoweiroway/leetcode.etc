// Author : luowei

//leetcode
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Tags： Array    Two Pointers

*/

//lintcode
/*
跟进“删除重复数字”：

如果可以允许出现两次重复将如何处理？

样例：
    给出数组A =[1,1,1,2,2,3]，你的函数应该返回长度5，此时A=[1,1,2,2,3]。

标签：
    两根指针 数组
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    //因为是可重复两次，所以采用了标志位，如果要通用可重复k次，则可以设置变量,见第二种
    /*int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size()==0)
            return 0;
        int back=0;
        bool flag=false;
        for(vector<int>::size_type i=1;i<nums.size();i++){
            if(nums[i]==nums[back]){
                if(flag==false){
                    nums[++back]=nums[i];
                    flag=true;
                }
            }
            else{
                nums[++back]=nums[i];
                flag=false;
            }
        }
        nums.resize(++back);
        return back;
    }*/
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size()==0)
            return 0;
        int back=0;
        int flag = 1;
        
        for (vector<int>::size_type i = 1; i < nums.size(); i++) {
            if (nums[back] == nums[i]) {
                if (flag++ < 2) {
                    nums[++back] = nums[i];
                }
            }
            else {
                nums[++back] = nums[i];
                flag = 1;
            } 
        }

        nums.resize(++back);
        return back;
    }
};