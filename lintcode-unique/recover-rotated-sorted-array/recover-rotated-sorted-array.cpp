// Author : luowei

/*
给定一个旋转排序数组，在原地恢复其排序。

样例:
  [4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

挑战:
  使用O(1)的额外空间和O(n)时间复杂度

说明:
  什么是旋转数组？
  比如，原始数组为[1,2,3,4], 则其旋转数组可以是[1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
标签:
  排序数组 数组
*/

class Solution {
public:
    
    /*方法一
     *先求出已旋转的个数，然后依次左移
     */
    /*void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if (nums.size()==0)
            return ;
        auto k=0;
        for(auto i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                k++;
                break;
            }
            if(nums[i]>nums[i+1]){
                k++;
                break;
            }
            k++;
        }
        
        k%=nums.size();
        
        while(k--){
            int temp=nums.front();
            for(auto i=0;i<nums.size()-1;i++){
                nums[i]=nums[i+1];
            }
            nums.back()=temp;
        }
    }*/
    
    /*方法二
     *求已旋转的个数这一部分与方法一相同
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        if (nums.size()==0)
            return ;
        auto k=0;
        for(auto i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                k++;
                break;
            }
            if(nums[i]>nums[i+1]){
                k++;
                break;
            }
            k++;
        }
        
        k%=nums.size();
        
        mirror(nums.begin(),nums.begin()+k-1);
        mirror(nums.begin()+k,nums.end()-1);
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


