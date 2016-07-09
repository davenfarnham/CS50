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

    /*** INSERT A NEW NODE4 AT THE FRONT ***/
    // TODO

    /*** DELETE NODE1 ***/
    // TODO

    /*** PRINT OUT LIST ***/
    // TODO
}
