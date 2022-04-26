#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

void    calculateMiddle(struct ListNode *head, int *result, struct ListNode *resHead)
{
    int here = *result;
    
    if (head == NULL) return;
    
    (*result)++;
    
    calculateMiddle(head->next, result, resHead);
    if (here == (*result)/2)
    {
        resHead->val = head->val;
        resHead->next = head->next;
    }
}

struct ListNode* middleNode(struct ListNode* head){
    int *result = (int *)calloc(1, sizeof(int));
    struct ListNode *resHead = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    *result = 0;
    
    calculateMiddle(head, result, resHead);
    
    return (resHead);
}