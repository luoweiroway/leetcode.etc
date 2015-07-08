// Author : luowei

//leetcode
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
  Given 1->2->3->4->5->NULL, m = 2 and n = 4,
  return 1->4->3->2->5->NULL.

Note:
  Given m, n satisfy the following condition:
  1 ≤ m ≤ n ≤ length of list.

Tags: Linked List

*/

//lintcode
/*
翻转链表中第m个节点到第n个节点的部分

样例:
  给出链表1->2->3->4->5->null， m = 2 和n = 4，返回1->4->3->2->5->null
  注意m，n满足1 ≤ m ≤ n ≤ 链表长度

挑战:
  在原地一次翻转完成

标签: 
  链表
*/

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
     
    /*链表翻转部分的基本算法思路还是与从头至尾翻转链表一样
     *m和n两个值将链表分成三个部分
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
        if((head==NULL) || (m<=0) || (n<=0) ||(m>=n)){
            return head;
        }
        int m_temp=m;
        
        //m>1时,让firstPartEnd指向m处结点前一个结点，p指向m处结点
        //m=1时,firstPartEnd失效不用(如果有头结点则可将其设为指向头结点)
        ListNode *firstPartEnd=head;
        ListNode *p=head;
        if(m>1){
            while((--m_temp)-1){
                firstPartEnd=firstPartEnd->next;
            }
            p=firstPartEnd->next;
        }
        
        //让secondPartBegin指向n处结点下一个结点
        ListNode *secondPartBegin=head;
        while(n--){
            secondPartBegin=secondPartBegin->next;
        }
        
        //这一部分为翻转代码，与从头至尾翻转一样，翻转完毕后也已与后部分结合
        ListNode *reversePartHead=secondPartBegin;
        while(p!=secondPartBegin){
            ListNode *temp=p;
            p=p->next;
            temp->next=reversePartHead;
            reversePartHead=temp;
        }
        
        //与前半部分结合
        if(m>1){
            firstPartEnd->next=reversePartHead;
        }
        else{
            head=reversePartHead;
        }
        return head;
    }
};

