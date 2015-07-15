// Author : luowei

//lintcode
/*
给定一个只包含字母的字符串，按照先小写字母后大写字母的顺序进行排序。

样例：
    给出"abAcD"，一个可能的答案为"acbAD"

注意：
    小写字母或者大写字母他们之间不一定要保持在原始字符串中的相对位置。

挑战：
    在原地扫描一遍完成

标签：
    字符串处理 两根指针 排序
*/
class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
     
    /*方法一，左右两个指针，一趟快排,时间O(n);
     *左指针从左向右走，右指针从右向左走;
     *左指针碰到小写字母则不管，碰到大写字母停下，右指针碰到大写字母则不管，碰到小写字母停下，然后交换内容，知道两指针相遇
     */
    /*void sortLetters(string &letters) {
        // write your code here
        int i = 0,j=letters.size()-1;
        while(i<j){
            while(i<j && letters[i]>='a') i++;
            while(i<j && letters[j]<='Z') j--;
            swap(letters[i],letters[j]);
        }
    }*/
    
    /*方法二，主从两个指针，也是快排思想的体现，一次遍历，时间O(n);
     *主指针用于遍历，从指针指向小写字母队列的后一个位置;
     *从左向右遍历，碰到大写字母则不管，碰到小写字母则将小写字母添加到小写字母队列的后一个位置，即交换两个指针指向的内容;
     *从指针也可以从右往左走，即指向大写字母队列的前一个位置，这也使得问题“set colors”的方法二可行
     */
    void sortLetters(string &letters) {
        int low_end = 0;
        for(int i=0;i<letters.size();i++){
            if(letters[i]>='a'){
                swap(letters[i],letters[low_end]);
                low_end++;
            }
        }
    }
    /*方法三，基于方法二实现一个保持顺序不变的方案，时间介于O(n)与O(n*n)之间;
     *不同之处在于碰到小写字母时将小写字母添加到小写字母队列的后一个位置，不是简单的交换两个指针指向的内容，需要右移这之间的元素;
     */
    /*void sortLetters(string &letters) {
        int low_end = 0;
        for(int i=0;i<letters.size();i++){
            if(letters[i]>='a'){
                int temp=letters[i];
                for(int j=i;j>low_end;j--){
                    letters[j]=letters[j-1];
                }
                letters[low_end]=temp;
                
                low_end++;
            }
        }
    }*/
};
