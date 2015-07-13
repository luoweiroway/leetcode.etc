// Author : luowei

//leetcode
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Tags: Linked List
*/

//lintcode
/*
给定一个排序链表，删除所有重复的元素只留下原链表中没有重复的元素。

样例:
    给出1->2->3->3->4->4->5->null，返回1->2->5->null
    给出1->1->1->2->3->null，返回 2->3->null
标签:
    链表
*/

class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    /*方法一，迭代版，迭代中带着迭代
    *思路与问题“删除排序链表中的重复元素”方法三类似,不同之处在于需要加入头结点，两个指针指向结点值相同时删除前面一个结点
    */
    /*ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(head==nullptr)
            return head;
        ListNode *headNode=new ListNode(head->val -1,head);//因为有可能删除第一个结点，所以引入头结点
        ListNode *back=headNode;
        ListNode *forward=head;
        
        while(forward!= nullptr){
            bool duplicated = false;  //该标志标明是否需要删除当前最后一个重复元素
            while((forward->next != nullptr) && (forward->val == forward->next->val)){
                duplicated= true;
                ListNode *temp=forward;
                forward = forward->next;
                delete temp;
            }
            if(duplicated){  
                ListNode *temp=forward;
                forward = forward->next;
                delete temp;
                continue;
            }
            back->next=forward;
            back=back->next;
            forward = forward->next;
        }
        back->next=forward;
        
        head=headNode->next;//清除头结点
        delete headNode;
        
        return head;
    }*/
    
    /*方法二，递归版，与问题“删除排序链表中的重复元素”中的方法五递归版思想类似
     *递归中带着迭代
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p = head->next;
        if (head->val == p->val) {
            while (p && head->val == p->val) {
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            delete head;
            return deleteDuplicates(p);
            
        } else {
            head->next = deleteDuplicates(p);
            return head;
        }
    }
};