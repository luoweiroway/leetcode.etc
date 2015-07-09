// Author : luowei

//leetcode
/*****************************************
Given an input string, reverse the string word by word.

For example,
    Given s = "the sky is blue",
    return "blue is sky the".

Update (2015-02-12):
    For C programmers: Try to solve it in-place in O(1) space.

Clarification:
    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.
Tags: String
*******************************************/

//lintcode
/*
给定一个字符串，逐个翻转字符串中的每个单词。

样例:
    给出s = "the sky is blue"，返回"blue is sky the"

说明:
    单词的构成：无空格字母构成一个单词
    输入字符串是否包括前导或者尾随空格？可以包括，但是反转后的字符不能包括
    如何处理两个单词间的多个空格？在反转字符串中间空格减少到只含一个
标签:
    字符串处理
*/
//leetcode
class Solution {
public:
    /*O(1)空间，O(n)时间，设置三个指针
     *参考https://leetcode.com/discuss/16669/c-solution-in-place-runtime-o-n-memory-o-1
     */
    void reverseWords(string &s) {
        int i=0,j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;  //记录单词数量
        
        if(len==0) return;
        
        while(true){
            while(i<len && s[i]==' ') i++;  //跳过每个单词前面的若干个空格
            if(i==len) break;
            
            if(wordcount!=0) s[j++]=' ';
            l=j;
            while(i<len && s[i]!=' '){ //将单个单词拷贝到前面
                s[j]=s[i];
                j++;
                i++;
            }

            reverseword(s,l,j-1);  //逆转该单词
            wordcount++;
        }
        
        s.resize(j);  //将后面的字符截断
        reverseword(s,0,j-1);
    }
    void reverseword(string &s, int i, int j){
        while(i<j){
            char temp=s[i];
            s[i++]=s[j];
            s[j--]=temp;
        } 
    }
};

//lintcode
class Solution {
public:
    /*O(n)的额外空间
     *从后往前遍历，一次添加单词
     */
    string reverseWords(string s) {
        // write your code here
        string result;
        string temp;
        for (auto it = s.rbegin(); it<s.rend(); it++){
            temp.clear();
            while (!isspace(*it)){
                temp.push_back(*it);
                it++;
                if (it == s.rend())
                    break;
            }
            if (!temp.empty()){
                if (!result.empty()) //反转后的字符串首不能加空格
                    result.push_back(' ');
                std::reverse(temp.begin(), temp.end());
                result.append(temp);
            }
            if (it == s.rend())
                break;
        }
        return result;
    }
};