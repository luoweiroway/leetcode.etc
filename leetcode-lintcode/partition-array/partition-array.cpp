// Author : luowei

//lintcode
/*
给出一个整数数组nums和一个整数k。划分数组（即移动数组nums中的元素），使得：

所有小于k的元素移到左边
所有大于等于k的元素移到右边
返回数组划分的位置，即数组中第一个位置i，满足nums[i]大于等于k。

样例：
    给出数组nums=[3,2,2,1]和 k=2，返回 1

注意：
    你应该真正的划分数组nums，而不仅仅只是计算比k小的整数数，如果数组nums中的所有元素都比k小，则返回nums.length。

挑战：
    要求在原地使用O(n)的时间复杂度来划分数组

标签：
    两根指针 排序 数组
*/
class Solution {
public:

    //注：此问题本质上与问题“sort-letters-by-case”一样，如果再要求k排在中间，则与问题“sort-colors”一样;
    //下面将问题当作“sort-colors”来接，即把k和大于k的也给排序了;
    
    
    /*方法一，同问题“sort-colors”方法二，一次遍历
    *一个主指针用于遍历，两个从指针
    */
    int partitionArray(vector<int> &nums, int k) {
        int left=0;
        int right=nums.size()-1;
        for(int i=0;i<=right;){
            if(nums[i]<k){
                swap(nums[i],nums[left]);
                left++;
            }else if (nums[i]>k){
                swap(nums[i],nums[right]);
                right--;
                continue;
            }
            i++;
        }
        return left;
    }
    
    /*方法二，同问题“sort-colors”方法三，两次遍历，第一次排小于k，第二次排k
    */
    /*int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int sequence_end = 0; 
        for (int curr = 0; curr < nums.size(); ++curr) {
            if (nums[curr] < k) {
                swap(nums[sequence_end], nums[curr]);
                sequence_end ++;
            }
        }
        int position = sequence_end;
        
        //上面已经得出结果，下面的则是将k和大于k的再排序
        for (int curr = sequence_end; curr < nums.size(); ++curr) {
            if (nums[curr] == k) {
                swap(nums[sequence_end], nums[curr]);
                sequence_end++;
            }
        }
        
        return position;
    }*/
    
    /*方法三，同问题“sort-colors”方法四，都借助于问题“字符大小写排序”的方法一思想，两次快排遍历;
    */
    /*int partitionArray(vector<int> &nums, int k) {
        int left = 0,right=nums.size()-1;
        while(left<right){
            while(left<right && nums[left]<k) left++;
            while(left<right && nums[right]>=k) right--;
            swap(nums[left],nums[right]);
        }
        int position= (right==(nums.size()-1) ? (right+1):right);
        
        //上面已经得出结果，下面的则是将k和大于k的再排序
        right=nums.size()-1;
        while(left<right){
            while(left<right && nums[left] ==k) left++;
            while(left<right && nums[right]>k) right--;
            swap(nums[left],nums[right]);
        }
        
        return position;
    }*/
};
