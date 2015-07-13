// Author : luowei

//lintcode
/*
写出一个函数 anagram(s, t) 去判断两个字符串是否是颠倒字母顺序构成的

样例:
  给出 s="abcd"，t="dcab"，返回 true

标签:
  字符串处理
*/

//luowei
/*
anagram的意思是把单词的字母顺序打乱,重新排列后变成一个新单词
*/
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
     
    /*方法一
    *hash表统计词频
    */
    /*bool anagram(string s, string t) {
        // write your code here
        if(s.size()!=t.size()){
            return false;
        }
        
        int charCount[256]{0};
        for(auto i=0;i!=s.size();i++){
            ++charCount[s[i]];
            --charCount[t[i]];
        }
        for(auto i:charCount){
            if(i!=0)
                return false;
        }
        return true;
    }*/
    
    /*方法二
    *先排序，然后比较有序字符串;
    *这里使用STL中sort算法
    */
    bool anagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        return s==t ? true:false;
    }
};