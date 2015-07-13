// Author : luowei

//lintcode
/*
比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母

样例:
    给出 A = "ABCD" B = "ACD"，返回 true
    给出 A = "ABCD" B = "AABC"， 返回 false
注意:
    在 A 中出现的 B 字符串里的字符不需要连续或者有序。
标签:
    基本实现 字符串处理
*/

//luowei
/*
题目的意思是包含B中所有的字符，即使重复，比如B中有两个A，那么A中就得有两个A
*/
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    /*思路与问题“两个字符串是变位词”类似
     *分别统计A、B中各字符的出现次数，只要B中有一个字符频次大于A则返回false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if(A.size()<B.size()){
            return false;
        }
        int charCount[26]={0};
        for(auto i:A){
            ++charCount[i-'A'];
        }
        for(auto i:B){
            if(--charCount[i-'A']<0)
            return false;
        }
        return true;
    }
};