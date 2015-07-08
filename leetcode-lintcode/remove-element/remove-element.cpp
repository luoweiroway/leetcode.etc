// Author : luowei

//leetcode
/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Tags: Array    Two Pointers

*/

//lintcode
/*
给定一个数组和一个值，在原地删除与值相同的数字，返回新数组的长度。

元素的顺序可以改变，并且对新的数组不会有影响。

样例：
    给出一个数组 [0,4,4,0,0,2,4,4]，和值 4
    返回 4 并且4个元素的新数组为[0,0,0,2]

标签：
    两根指针 数组
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    /*方法一
     *直接使用容器的删除接口，而且是真正删除元素，即元素的size变小了，且元素顺序不变
     */
    /*int removeElement(vector<int> &A, int elem) {
        // write your code here
        for(auto i=A.begin();i<A.end();){
            if(*i == elem){
                i=A.erase(i);
            }
            else{
                i++;
            }
        }
        return A.size();
    }*/
    
    /*方法二
     *使用两个指针，一个从头往后走，一个从后往前走，元素顺序会变，容器大小不变，后边的元素仍在
     */
    /*int removeElement(vector<int> &A, int elem) {
        int count=A.size();
        for(auto i=0,j=count-1;i<count;){
            if(A[i]==elem){
                A[i]=A[j];
                j--;
                count--;
            }
            else
                i++;
        }
        return count;
    }*/
    
    //精简一下方法二的代码
    int removeElement(vector<int> &A, int elem) {
        int count=A.size();
        for(auto i=0;i<count;){
            if(A[i]==elem){
                A[i]=A[count-1];
                count--;
            }
            else
                i++;
        }
        return count;
    }
};