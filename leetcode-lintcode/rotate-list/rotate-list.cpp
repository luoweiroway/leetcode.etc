// Author : luowei

//leetcode
/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL.

TagsL Linked List    Two Pointers
*/

//lintcode
/*
给定一个链表，旋转链表，使得每个节点向右移动k个位置，其中k是一个非负数


样例
  给出链表1->2->3->4->5->null和k=2
  返回4->5->1->2->3->null

标签:
  基本实现 链表
*/
  
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(head==NULL)
            return head;
            
        int length=getlength(head);
        k%=length;
        if(k==0)
            return head;
            
        //注：前面已求出链表长度，其实就没必要像下面这样设置快慢指针的方法来定位倒数第k+1个结点（若下面代码中为--k则是定位倒数第k个结点）
        ListNode *forward=head;
        ListNode *back=head;
        while(k-->0){
            forward=forward->next;
        }
        
        while(forward->next!=NULL){
            forward=forward->next;
            back=back->next;
        }
        
        forward->next=head;
        head=back->next;
        back->next=NULL;
        
        return head;
    }
    
    int getlength(ListNode *head){
        int length=0;
        while(head!=NULL){
            length++;
            head=head->next;
        }
        return length;
    }
};


