// Source : https://oj.leetcode.com/problems/repeated-dna-sequences/
// Author : luowei

/********************************************************************************** 
 * 
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
 *
 * For example: "ACGAATTCCG". 
 * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that 
 * occur more than once in a DNA molecule.
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * 
 *               
 **********************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int char2int(char c){
    switch (c){
        case 'A':return 0;
        case 'C':return 1;
        case 'G':return 2;
        case 'T':return 3;
    }
    return -1;
}
int dnaseq2int_hash(string &s,int begin){
    int hashcode=0;
    for (int i = 0; i < 10; i++){
        hashcode = (hashcode << 2) + char2int(s[i + begin]);
    }
    return hashcode;
}

vector<string> findRepeatedDnaSequences(string s){
    vector<string> result;
    unordered_map<int, int> repeated;
    if (s.size() <= 10)
        return result;
    for (unsigned int i = 0; i + 10 <= s.size(); i++){
        int hashcode = dnaseq2int_hash(s, i);
        repeated[hashcode]++;
        if (repeated[hashcode] == 2)
            result.push_back(s.substr(i, 10));
    }
    return result;
}

//下面这个不使用额外函数，但思想一致
vector<string> findRepeatedDnaSequences(string s){
    vector<string> result;
    unordered_map<int, int> repeated;
    unordered_map<int, int> charToint{ { 'A', 0 }, { 'C', 1 }, { 'G', 2 }, { 'T', 3 } };
    int hashcode = 0;
    if (s.size() <= 10)
        return result;
    for (unsigned int i = 0; i < 10; i++){
        hashcode = (hashcode << 2) + charToint[s[i]]; //初始化hashcode值
    }
    repeated[hashcode]++;
    for (unsigned int i = 10; i < s.size(); i++){
        hashcode = ((hashcode&0x3ffff)<<2) + charToint[s[i]];//动态更新hashcode值
        repeated[hashcode]++;
        if (repeated[hashcode] == 2)
            result.push_back(s.substr(i-9, 10));
    }
    return result;
}




//以下代码为测试运行用
void printVector( vector<string> v ) {
    cout << "[ " ;
    for(int i=0; i<v.size(); i++ ){
        cout << v[i] << (i<v.size()-1 ? ", " : "");
    }
    cout << " ]" << endl;
}

int main(int argc, char** argv)
{
    string s =  "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT" ;
    if (argc > 1){
        s = argv[1];
    }
    printVector(findRepeatedDnaSequences(s));
}
