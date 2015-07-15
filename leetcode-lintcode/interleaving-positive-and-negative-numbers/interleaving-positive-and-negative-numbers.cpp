// Author : luowei

//lintcode
/*
给出一个含有正整数和负整数的数组，重新排列成一个正负数交错的数组。

样例：
    给出数组[-1, -2, -3, 4, 5, 6]，重新排序之后，变成[-1, 5, -2, 4, -3, 6]或者其他任何满足要求的答案

注意：
    不需要保持正整数或者负整数原来的顺序。

挑战：
    原地完成，没有额外的空间

标签： 
    两根指针
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
     
    /*方法一
    *基于问题“sort-letters-by-case”的方法二
    */
    /*void rerange(vector<int> &A) {
        // write your code here
        int posNum=0,negNum=0;
        for (int elem : A) {
            if (elem < 0)  negNum++;
            else  posNum++;
        }
        
        int zig_end = 0;
        //这段循环处理第一个数，如果正数多则放正数，负数多则放负数
        for (int i = 0; i < A.size();i++ ) {
            if(posNum > negNum){ 
                if (i < A.size() && A[i] >0) {
                    swap(A[i],A[zig_end]);
                    zig_end++;
                    break;
                }
            }
            else{
                if (i < A.size() && A[i] <0) {
                    swap(A[i],A[zig_end]);
                    zig_end++;
                    break;
                }
            }
        }
        
        for (int i = 1; i < A.size(); ) {
            if (((A[zig_end-1] <0) && (A[i] >0)) ||((A[zig_end-1]>0) && (A[i]<0)) ) {
                swap(A[i],A[zig_end]);
                zig_end++;
                i=zig_end;
                continue;
            }
            i++;
        }
    }*/
    
    /*方法二，一个指针处理奇数列(数量多的符号数)，一个处理偶数列
    */
    void rerange(vector<int> &A) {
        int posNum = 0, negNum = 0;
        for (int elem : A) {
            if (elem < 0) {
                negNum++;
            }
            else {
                posNum++;
            }
        }
        int posInd = 1, negInd = 0;
        if (posNum > negNum) {
            negInd = 1;
            posInd = 0;
        }
        
        while (posInd<A.size() && negInd<A.size()) {
            while (posInd < A.size() && A[posInd] > 0) {
                posInd += 2;
            }
            while (negInd < A.size() && A[negInd] < 0) {
                negInd += 2;
            }
            
            if (posInd<A.size() && negInd<A.size()) {
                swap(A[posInd], A[negInd]);
            }
        }
    }
    
    /*方法三，一个指针处理奇数列(数量多的符号数)，一个处理偶数列
    *与方法二类似，但是两个指针一个从头往尾遍历，一个从后往前遍历，代码待编写
    *参考：http://www.cnblogs.com/yuzhangcmu/p/4175620.html
    */
    
    
};
