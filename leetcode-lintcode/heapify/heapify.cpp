// Author : luowei

//lintcode
/*
给出一个整数数组，堆化操作就是把它变成一个最小堆数组。
对于堆数组A，A[0]是堆的根，并对于每个A[i]，A [i * 2 + 1]是A[i]的左儿子并且A[i * 2 + 2]是A[i]的右儿子。

样例：
给出 [3,2,1,4,5]，返回[1,2,3,4,5] 或者任何一个合法的堆数组

挑战：
    O(n)的时间复杂度完成堆化

说明：
什么是堆？
堆是一种数据结构，它通常有三种方法：push， pop 和 top。其中，“push”添加新的元素进入堆，“pop”删除堆中最小/最大元素，“top”返回堆中最小/最大元素。
什么是堆化？
把一个无序整数数组变成一个堆数组。如果是最小堆，每个元素A[i]，我们将得到A[i * 2 + 1] >= A[i]和A[i  * 2 + 2] >= A[i]
如果有很多种堆化的结果？
返回其中任何一个。

标签： 
    堆
*/
class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        for(int i=A.size()/2;i>=0;i--){
            minHeapify_iter(A,i,A.size()-1);
        }
    }
    
    //筛选法调整堆，递归版
    /*void minHeapify_recur(vector<int> &A,int start,int end){
        int min=start;
        int left=2*start+1;
        int right=2*start+2;
        
        if(left<=end)
            min= A[left]<A[min]?left:min;
        if(right<=end)
            min= A[right]<A[min]?right:min;
        
        if(min!=start){
            swap(A[start],A[min]);
            minHeapify_recur(A,min,end);
        }
    }*/
    
    //筛选法调整堆，迭代版
    void minHeapify_iter(vector<int> &A,int start,int end){
        for(int i=start;i<=end;){
            int min=i;
            int left=2*i+1;
            int right=2*i+2;
        
            if(left<=end)
                min= A[left]<A[min]?left:min;
            if(right<=end)
                min= A[right]<A[min]?right:min;
            
            if(i!=min){
                swap(A[i],A[min]);
                i=min;
            }
            else
                break;
        }
    }
};
