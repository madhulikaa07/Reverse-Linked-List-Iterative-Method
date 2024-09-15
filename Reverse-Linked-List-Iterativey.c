#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* add_node(struct ListNode* head,int val)
{
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!temp)
    {
        printf("Error allocating memory\n");
    }
    temp->val = val;
    temp->next = NULL;

    if(head == NULL)//if list is empty
    {
        head = temp;
        return head;
    }
    else
    {
        //iterate to the last node of the list
        struct ListNode* current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        return head;
    }

}

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode *prev,*current,*next;
    prev = NULL;
    current = head;
    
    while( current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    return head;
}

void print(struct ListNode* head)
{
    printf("\n");
    struct ListNode* temp = head;
    while(temp != NULL)
    {
        printf(" %d",temp->val);
        temp = temp->next;
    }
    printf("\n");
    
    return;
}


int main()
{
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    struct ListNode* result = NULL;
    
    l1 = add_node(l1,1);
    l1 = add_node(l1,2);
    l1 = add_node(l1,3);
    l1 = add_node(l1,4);
    l1 = add_node(l1,5);
    l1 = add_node(l1,6);
    l1 = add_node(l1,7);
    
    
    printf("L1:");
    print(l1);
 
    result = reverse(l1);
    
    printf("Result:");
    print(result);	
    
}