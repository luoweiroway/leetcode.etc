// Author : luowei

/*
设计一种方法，将一个字符串中的所有空格替换成 %20 。你可以假设该字符串有足够的空间来加入新的字符，且你得到的是“真实的”字符长度。


样例：
    对于字符串"Mr John Smith", 长度为 13，替换空格之后的结果为"Mr%20John%20Smith"
注意：
    如果使用 Java 或 Python, 程序中请用字符数组表示字符串。
挑战：
    在原字符串(字符数组)中完成替换，不适用额外空间

标签： 
    字符串处理
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        for (int i = length - 1; i >= 0; i--){
            if (string[i] == ' ') {
                for (int j = length - 1; j > i; j--) {
                    string[j + 2] = string[j];
                }
                string[i] = '%';
                string[i + 1] = '2';
                string[i + 2] = '0';
                length += 2;
            }
        }
        return length;
    }
};