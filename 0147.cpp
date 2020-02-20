/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* listHead = new ListNode(0);   //头节点
        listHead->next = head;
        head = head->next;
        listHead->next->next = NULL;    //断开链表
        ListNode* sorted;        //sorted为已排序序列起始元素
        ListNode* p = NULL;       //指针p指向当前操作元素

        while(head) {
            p = head;       //未排序序列弹出起始元素
            head = head->next;
            p->next = NULL;
            sorted = listHead;
            
            while(sorted->next != NULL && (p->val > sorted->next->val)) {
                //条件判断sorted非结尾元素，且p指向元素的值大于sorted后一个元素的值
                //二者不可调换位置，优先级不同，sorted到达末尾触发短路评估
                sorted = sorted->next;
            }
            p->next = sorted->next;
            sorted->next = p;   //在已排序序列中插入p
        }
        head = listHead->next;
        delete listHead;
        return head;
    }
};