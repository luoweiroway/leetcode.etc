// Author : luowei

//lintcode
/*
给定一个单链表和数值x，划分链表使得所有小于x的节点排在大于等于x的节点之前。
你应该保留两部分内链表节点原有的相对顺序。

样例：
    给定链表 1->4->3->2->5->2->null，并且 x=3
    返回 1->2->2->4->3->5->null
标签：
    两根指针 链表
*/
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
     
     /*思路与数组划分一样，只是链表处理上有点不一样，不是交换，而是断开和插入
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head==nullptr) return nullptr;
        ListNode *headNode=new ListNode(-1);
        headNode->next=head;
        
        ListNode *p=headNode;
        ListNode *back=headNode;
        while(p->next!=nullptr){
            if(p->next->val < x){
                //这一段if体去掉，加上下面的小if体也可以
                if(back==p){
                    back=back->next;
                    p=p->next;
                    continue;
                }
                ListNode *temp=p->next;
                p->next=temp->next;
                temp->next=back->next;
                back->next=temp;
                /*if(back==p)
                    p=p->next;*/
                back=back->next;
                
            }
            else
                p = p->next;
        }
        
        return headNode->next;
    }
};
