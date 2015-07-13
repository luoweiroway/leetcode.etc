// Author : luowei

//leetcode
/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Tags： Array    Two Pointers


*/

//lintcode
/*
给定一个排序数组，在原数组中删除重复出现的数字，使得每个元素只出现一次，并且返回新的数组的长度。

不要使用额外的数组空间，必须在原地没有额外空间的条件下完成。

样例：
    给出数组A =[1,1,2]，你的函数应该返回长度2，此时A=[1,2]。

标签：
    两根指针 数组
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
     //设置前后两个指针
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size()==0)
            return 0;
        int back=0;
        for(vector<int>::size_type i=1;i<nums.size();i++){
            if(nums[i]!=nums[back]){
                if(++back != i)
                    nums[back]=nums[i];
            }
        }
        nums.resize(++back);//删除后面余留的数字空间
        return back;
    }

    //方法二，直接使用STL
    /*int removeDuplicates(vector<int> &nums) {
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
    }*/
};
