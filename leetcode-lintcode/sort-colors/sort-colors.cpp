// Author : luowei

//lintcode
/*
给定一个包含红，白，蓝且长度为n的数组，将数组元素进行分类使相同颜色的元素相邻，并按照红、白、蓝的顺序进行排序。

我们可以使用整数0，1和2分别代表红，白，蓝。

样例
注意：
    不能使用代码库中的排序函数来解决这个问题

说明：
一个相当直接的解决方案是使用计数排序扫描2遍的算法。
首先，迭代数组计算0,1,2出现的次数，然后依次用0,1,2出现的次数去覆盖数组。
你否能想出一个仅使用常数级额外空间复杂度且只扫描遍历一遍数组的算法？

标签：
    两根指针 排序 数组
*/
class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    
    /*方法一，借助额外存储，使用计数排序，第一次遍历计算0/1/2的个数，第二次遍历则生成结果，代码就不写了
    */
    
    /*方法二：借助于问题“字符大小写排序”的方法二思想，一次遍历即可，时间O(n);
     *这里用两个从指针，分别在左右;
     *主指针用于遍历，左从指针指向整数0序列(红球)末尾的后一个位置，右从指针指向整数2序列(蓝球)首端的前一个位置;
     *借助于问题“字符大小写排序”的方法一思想，写不出一次遍历的版本;
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        int left=0;
        int right=nums.size()-1;
        for(int i=0;i<=right;){
            if(nums[i]==0){
                swap(nums[i],nums[left]);
                left++;
            }else if (nums[i]==2){
                swap(nums[i],nums[right]);
                right--;
                continue;
            }
            i++;
        }
    }
    
    /*方法三：借助于问题“字符大小写排序”的方法二思想，两次遍历;
     *不同于方法二，本方法具有扩展性，见问题“sort-colors-ii”;
     *n种球则n-1次遍历，遍历次数增加遍历量减少;
     */
    /*void sortColors(vector<int> &nums) {
        int sequence_end = 0;
        /*for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                swap(nums[i],nums[sequence_end]);
                sequence_end++;
            }
        }
        for(int i=sequence_end;i<nums.size();i++){
            if(nums[i] == 1){
                swap(nums[i],nums[sequence_end]);
                sequence_end++;
            }
        }*/
        
        //改写上面的循环，具有扩展性
        /*for(int k =0;k<2;k++){
            for(int i=sequence_end;i<nums.size();i++){
                if(nums[i] == k){
                    swap(nums[i],nums[sequence_end]);
                    sequence_end++;
                }
            }
        }
    }*/
    
    /*方法四，借助于问题“字符大小写排序”的方法一思想，两次快排遍历;
     *此法也具有扩展性
     */
};
