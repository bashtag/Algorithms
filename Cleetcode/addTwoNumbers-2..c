#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode returnList = {.next = NULL};
    struct ListNode* current = &returnList;
    
    int temp = 0;
    
    while (l1 != NULL || l2 != NULL)
    {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->next = NULL;
        current->val = 0;
        
        if (l1 != NULL)
            current->val += (l1->val);

        if (l2 != NULL)
            current->val += (l2->val);
    
        current->val += temp;
        
        temp = current->val / 10;
        current->val %= 10;
        
        if (l2 != NULL)
            l2 = l2->next;
        
        if (l1 != NULL)
            l1 = l1->next;
    }
    
    if (temp != 0)
    {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = temp;
        current->next = NULL;
    }
    
    return (returnList.next);
}