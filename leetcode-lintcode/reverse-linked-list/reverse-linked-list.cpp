// Author : luowei

//leetcode
/*
Reverse a singly linked list.

Hint:
  A linked list can be reversed either iteratively or recursively. Could you implement both?

Tags: Linked List
*/

//lintcode
/*
翻转一个链表

样例:
  给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null

挑战:
  在原地一次翻转完成

标签:
  链表
*/

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    /*ListNode *reverse(ListNode *head) {
        // write your code here
        if(head==NULL){
            return head;
        }
        ListNode *q=head;
        ListNode *p=head->next;
        while(p!=NULL){
            ListNode *temp=p->next;
            q->next=temp;
            p->next=head;
            head=p;
            p=temp;
        }
        return head;
    }*/
    
    //循环中只使用三个指针变量，更简洁
    ListNode *reverse(ListNode *head) {
        // 如果链表为空或只有一个结点，无需反转，直接返回原链表头指针，这一段去掉程序也能正确运行，因为后面的代码思想已经包含了这两种情况
      if(head == NULL || head->next == NULL)
        return head;

        ListNode *newhead=NULL;
      ListNode *p=head;
      while(p!=NULL){
          ListNode *temp=p;
          p=p->next;
          temp->next=newhead;
          newhead=temp;
      }
      return newhead;
    }
    
    
    /*递归版本
     *newhead用来传递新的头指针，递归尽头中得到后就一直往回传
     */
    /*ListNode* reverse(ListNode* head){
        if (head == NULL || head->next == NULL) 
            return head;
        ListNode *newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newhead;
    }*/
};
