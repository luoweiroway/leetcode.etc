// Author : luowei

//lintcode
/*
给定一个有n个对象（包括k种不同的颜色，并按照1到k进行编号）的数组，将对象进行分类使相同颜色的对象相邻，并按照1,2，...k的顺序进行排序。

样例：
    给出colors=[3, 2, 2, 1, 4]，k=4, 你的代码应该在原地操作使得数组变成[1, 2, 2, 3, 4]

注意：
    不能使用代码库中的排序函数来解决这个问题

挑战：
    一个相当直接的解决方案是使用计数排序扫描2遍的算法。这样你会花费O(k)的额外空间。你否能在不使用额外空间的情况下完成？

标签：
    两根指针 排序
*/
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
     
    /*方法一，借助额外存储空间，使用计数排序，代码就不写了;
    */
    
    /*方法二，问题“sort-colors”的方法三的体现;
    */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int sequence_end = 0;
        
        for(int n =1;n<=k;n++){
            for(int i=sequence_end;i<colors.size();i++){
                if(colors[i] == n){
                    swap(colors[i],colors[sequence_end]);
                    sequence_end++;
                }
            }
        }
    }
    
    /*方法三，问题“sort-colors”的方法四的体现;
    *代码略
    */
};
