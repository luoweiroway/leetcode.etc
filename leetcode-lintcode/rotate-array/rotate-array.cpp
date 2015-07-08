// Author : luowei

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II

Tags: Array

*/

class Solution {
public:
    /*方法一
     *这种方法比较慢，因为vector容器插入操作效率较低
     */
    /*void rotate(vector<int>& nums, int k) {
        if (nums.size()==0)
            return ;
        k %=nums.size();
        while(k--){
            int temp=nums.back();
            nums.pop_back();
            nums.insert(nums.begin(),temp);
        }
    }*/
    
    /*方法二
     *这种方法比上面的快，不涉及插入删除操作
     */
    void rotate(vector<int>& nums, int k) {
        if (nums.size()==0)
            return ;
        k %=nums.size();
        mirror(nums.begin(),nums.end()-k-1);
        mirror(nums.end()-k,nums.end()-1);
        mirror(nums.begin(),nums.end()-1);
    }
    void mirror(vector<int>::iterator start,vector<int>::iterator end){
        for(auto i=start,j=end;i<j;i++,j--){
            int temp=*i;
            *i=*j;
            *j=temp;
        }
    }
    
};


