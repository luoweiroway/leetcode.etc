// Author : luowei

//leetcode
/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Tags: Hash Table String
*/

//lintcode
/*
给出一个字符串数组S，找到其中所有的乱序字符串(Anagram)。如果一个字符串是乱序字符串，那么他存在一个字母集合相同，但顺序不同的字符串也在S中。

样例：
    对于字符串数组 ["lint","intl","inlt","code"]
    返回 ["lint","inlt","intl"]
注意：
    所有的字符串都只包含小写字母
标签：
    字符串处理 哈希表
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    /*方法一
     *双重循环,时间复杂度较高，当输入数据集较大时，会超出OJ的时间限制，Time Limit Exceeded!
     */
    /*vector<string> anagrams(vector<string> &strs) {
        // write your code here
        if(strs.size()<2){
            return strs;
        }
        
        vector<string> result;
        vector<bool> visited(strs.size(),false);
        for(auto i=0;i<strs.size();i++){
            bool hasAnagram = false;
            for(auto j=i+1;j<strs.size();j++){
                if(!visited[j] && isAnagram(strs[i],strs[j])){
                    result.push_back(strs[j]);
                    visited[j]=true;
                    hasAnagram=true;
                }
            }
            if(!visited[i] && hasAnagram)
                result.push_back(strs[i]);
        }
        return result;
    }
    bool isAnagram(string s, string t) {
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
     *将问题“两个字符串是变位词(two-strings-are-anagrams)”中的两种解法结合起来，即排序加哈希表
     *第一次遍历将所有字符串排序后哈希计数，第二次遍历再对所有字符串排序后哈希并判断
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        unordered_map<string,int> hash;
        for(auto i:strs){
            sort(i.begin(),i.end());
            ++hash[i];
        }
        for(auto i:strs){
            string temp(i);
            sort(temp.begin(),temp.end());
            if(hash[temp]>1)
                result.push_back(i);
        }
        return result;
    }
    
};