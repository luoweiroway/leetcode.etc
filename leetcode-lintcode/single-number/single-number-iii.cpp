// Author : luowei

//lintcode
/********************************************************************************** 
给出2*n + 2个的数字，除其中两个数字之外其他每个数字均出现两次，找到这两个数字。

样例:
    给出 [1,2,2,3,4,4,5,3]，返回 1和5
挑战:
    O(n)时间复杂度，O(1)的额外空间复杂度
标签:
    贪心

**********************************************************************************/
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    /*
     *先将所有数字异或求和，即两个独特数字求异或的结果，然后以该结果中为1的某一位来判断，可将数组分为两部分，分别包含两个独特数字，然后对两部分分别异或求和。下面代码中选择了最右边一个比特位1。
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        
        int xorSum=0;
        for(auto i : A){
            xorSum^=i;
        }
        
        xorSum &=~(xorSum-1);
        int num1=0;
        int num2=0;
        for(auto i:A){
            if(i&xorSum)
                num1^=i;
            else
                num2^=i;
        }
        
        vector<int> result;
        result.push_back(num1);
        result.push_back(num2);
        return result;
    }
};