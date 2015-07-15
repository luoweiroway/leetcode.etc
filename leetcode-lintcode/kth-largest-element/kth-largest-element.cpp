// Author : luowei

//lintcode
/*
在数组中找到第k大的元素

样例：
    给出数组[9,3,2,4,8]，第三大的元素是4
    给出数组 [1,2,3,4,5]，第一大的元素是5，第二大的元素是4，第三大的元素是3，以此类推
注意：
    你可以交换数组中的元素的位置

挑战：
    要求时间复杂度为O(n），空间复杂度为O(1）

标签：
    快速排序 排序
*/
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
     
    /*快速排序的利用，quickselect算法
    */
    /*int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if(k> nums.size()) return 0;
        return quickSelect(k,nums,0,nums.size()-1);
    }
    
    int quickSelect(int k, vector<int> &nums, int start, int end){
        int l=start,r=end;
        int pivot=end;
        while(l<r){
            while(l<r && nums[l]<nums[pivot]) l++;
            while(l<r && nums[r]>=nums[pivot]) r--;
            swap(nums[l],nums[r]);
        }
        swap(nums[l],nums[end]);  //l此时指向右边大于pivot的第一个数,故将其与pivot交换
        if((end-l+1) == k) return nums[l];
        else if((end-l+1)>k) return quickSelect(k,nums,l+1,end);
        else return quickSelect((k-end+l-1),nums,start,l-1);
    }*/
    
    /*与上面一样，只是变一种写法，quickselect的k参数表示第k小
    *即此法是求kth-smallest-element
    */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if(k> nums.size()) return 0;
        return quickSelect(nums.size()-k+1,nums,0,nums.size()-1);
    }
    
    int quickSelect(int k, vector<int> &nums, int start, int end){
        int l=start,r=end;
        int pivot=end;
        while(l<r){
            while(l<r && nums[l]<nums[pivot]) l++;
            while(l<r && nums[r]>=nums[pivot]) r--;
            swap(nums[l],nums[r]);
        }
        swap(nums[l],nums[end]);  //l此时指向右边大于pivot的第一个数,故将其与pivot交换
        
        if((l-start+1) == k) return nums[l];
        else if((l-start+1)<k) return quickSelect(k-l+start-1,nums,l+1,end);
        else return quickSelect(k,nums,start,l-1);
        
        //上面的语句也可以直接写成下面
        /*if((l+1) == k) return nums[l];
        else if((l+1)<k) return quickSelect(k,nums,l+1,end);
        else return quickSelect(k,nums,start,l-1);*/
        
    }
};
