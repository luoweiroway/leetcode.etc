// Author : luowei

//leetcode
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Tags: Linked List
*/

//lintcode
/*
给定一个排序链表，删除所有重复的元素每个元素只留下一个。

样例:
    给出1->1->2->null，返回 1->2->null
    给出1->1->2->3->3->null，返回 1->2->3->null

标签:
    链表
*/

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    /*方法一，迭代版
     *思路与"删除排序数组中的重复数字"中类似
     */
    /*ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *back=head;
        ListNode *forward=back;
        while(forward!=nullptr){
            if(forward->val != back->val){
                ListNode *temp=back->next;
                back->next=forward;
                back=forward;
                while(temp!=forward){// 释放中间重复结点的空间
                    ListNode *temp_temp=temp;
                    temp=temp->next;
                    free(temp_temp);
                }
            }
            else
                forward=forward->next;
        }
        
        if(back!=forward){//清除最后面可能的重复结点
            ListNode *temp=back->next;
            back->next=nullptr;
            while(temp!=forward){// 释放中间重复结点的空间
                ListNode *temp_temp=temp;
                temp=temp->next;
                free(temp_temp);
            }
        }
        
        return head;
    }*/
    
    /*方法二，迭代版，此版本最好理解
     *与方法一不同的是，这里循环过程中只要有相同就删除，而方法一是相同就先不管，等到不同时再把两者之间的重复结点删除，两者本质上一样;
     *这里比较一下问题"删除排序数组中的重复数字"，其也可采用这种方法，但是数组删除太麻烦，需要移动后面元素，所以其更好的解法与本题中的方法一类似，即先攒着相同的点;
     */
    /*ListNode *deleteDuplicates(ListNode *head) {
        if(head==nullptr)  return head;
        ListNode *back=head;
        ListNode *forward=head->next;
        
        while(forward!=nullptr){
            if(back->val == forward->val){
                back->next=forward->next;
                delete forward;
            }
            else{
                back=forward;
            }
            forward=forward->next;
        }
        
        return head;
    }*/
    
    /*方法三，迭代版，迭代中带着迭代
     *基于方法二的改动版，循环过程中也是只要两个指针指向结点值相同就删除后一个结点，但是一旦遇到相同就会一直删到碰到不等的结点才会退出小迭代，两者本质上一样。
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==nullptr)  return head;
        ListNode *back=head;
        ListNode *forward=head->next;
        
        while(forward!=nullptr){
            while(forward!=nullptr && back->val == forward->val) {
                ListNode *temp = forward;
                forward = forward->next;
                delete temp;
            }
            back->next=forward;
            back=forward;
            if(forward==nullptr)
                return head;
            forward=forward->next;
        }
        
        return head;
    }
    
    /*方法四，递归版
     *基于方法二迭代的递归版本
     */
    /*ListNode *deleteDuplicates(ListNode *head) {
        if(head==nullptr)  return head;
        
        recur(head,head->next);
        return  head;
    }
    static void recur(ListNode *back, ListNode *forward){
        if(forward == nullptr) return ;
        
        if(back->val == forward->val){
            back->next=forward->next;
            delete forward;
            recur(back,back->next);
        }
        else{
            recur(back->next,forward->next);
        }
    }*/
    
    /*方法五，递归版
     *基于方法三的递归版，递归中带着迭代
     */
    /*ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *p = head->next;
        if (head->val == p->val) {//这个if体运行完head与p指向的结点要么值不相等，要么p到null了
            while(p!=nullptr && head->val == p->val) {
                ListNode *temp = p;
                p = p->next;
                delete temp;
            }
        }
        head->next=deleteDuplicates(p);
        return head;
    }*/
};
