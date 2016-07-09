#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int i;
    struct node* next;
} node;

int main(void)
{

    node* node0 = malloc(sizeof(node));
    node* node1 = malloc(sizeof(node));
    node* node2 = malloc(sizeof(node));


    node0 -> i = 0;
    node0 -> next = node1;

    node1 -> i = 1;
    node1 -> next = node2;

    node2 -> i = 2;
    node2 -> next = NULL;

    /*** INSERT A NEW NODE3 AT THE FRONT ***/
    node* node3 = malloc(sizeof(node));
    node3 -> i = 3;
    node3 -> next = node0;

    /*** DELETE NODE1 ***/
    node* prev = node3;
    node* head = node3 -> next;

    while(head != NULL)
    {
        if(head -> i == 1)
        {
            head = head -> next;
            break;
        }

        // move forward
        prev = prev -> next;
        head = head -> next;
    }

    // set previous equal to new head
    prev -> next = head;

    /*** PRINT OUT LIST ***/
    node* print  = node3;
    while(print != NULL)
    {
        printf("%i\n", print->i);
        print = print->next;
    }

}
