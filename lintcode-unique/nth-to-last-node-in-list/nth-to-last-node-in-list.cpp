// Author : luowei

/*
链表倒数第n个节点
找到单链表倒数第n个节点，保证链表中节点的最少数量为n。

样例:
  给出链表 3->2->1->5->null和n = 2，返回倒数第二个节点的值1.

标签: 
  链表
*/

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
     
    /*
     *设置快慢指针
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if(head==NULL || n==0)
            return head;
        
        ListNode *forward=head;
        ListNode *back=head;
        while(--n>0){
            forward=forward->next;
        }
        
        while(forward->next!=NULL){
            forward=forward->next;
            back=back->next;
        }
        return back;
    }
};


