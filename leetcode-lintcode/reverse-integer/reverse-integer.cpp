// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : luowei

//leetcode
/*****************************************
* Reverse digits of an integer.
* 
* Example1: x =  123, return  321
* Example2: x = -123, return -321
* 
* Have you thought about this?
* 
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
* 
* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
* 
* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
*   then the reverse of 1000000003 overflows. How should you handle such cases?
* 
* > For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*            
**********************************************************************************/

//lintcode
/*将一个整数中的数字进行颠倒，当颠倒后的整数溢出时，返回 0 (标记为 32 位整数)。
*样例:
*给定 x = 123，返回 321
*给定 x = -123，返回 -321
*
*标签:整数
*/

class Solution {
public:
    int reverse(int num) {
        //bool minusFlag=(num<0)?TRUE:FALSE;
        int rev = 0;
        int last;
        while(num != 0){
            if((rev>(INT_MAX/10)) || (rev<(INT_MIN/10)))
                return 0;
            rev = rev*10 + num%10;
            num = num/10;
        }
        return rev;
    }
};