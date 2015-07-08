// Author : luowei

/*
给定一个字符串和一个偏移量，根据偏移量旋转字符串(从左向右旋转)

样例:
    对于字符串 "abcdefg".

    offset=0 => "abcdefg"
    offset=1 => "gabcdef"
    offset=2 => "fgabcde"
    offset=3 => "efgabcd"
挑战:
    在数组上原地旋转，使用O(1)的额外空间

标签:
    字符串处理
*/

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
     /*方法一
     *这种方法比较慢，因为vector容器插入操作效率较低,lintcode关于此题的test case较少，leetcode就明显不如第二种方法
     */
    /*string rotateString(string A, int offset) {
        if(A.size()==0)
            return "";
        offset %=A.size();
        while(offset--){
            auto temp=A.back();
            A.pop_back();
            A.insert(A.begin(),temp);
        }
        return A;
    }*/
    
    /*方法二
     *这种方法比上面的快，不涉及插入删除操作
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        if (A.size()==0)
            return "";
        offset %=A.size();
        mirror(A.begin(),A.end()-offset-1);
        mirror(A.end()-offset,A.end()-1);
        mirror(A.begin(),A.end()-1);
        
        return A;
    }
    void mirror(string::iterator start,string::iterator end){
        for(auto i=start,j=end;i<j;i++,j--){
            int temp=*i;
            *i=*j;
            *j=temp;
        }
    }
};


