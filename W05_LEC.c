#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

void insert_at_front(int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;
    if(head != NULL)
    {
        head->prev = new_node;
    }
    head = new_node;
}

void remove_duplicates()
{
    struct node *current = head;
    while(current != NULL)
    {
        struct node *temp = current->next;
        while(temp != NULL)
        {
            if(temp->data == current->data)
            {
                struct node *duplicate = temp;
                temp = temp->next;
                if(duplicate->prev != NULL)
                {
                    duplicate->prev->next = duplicate->next;
                }
                else
                {
                    head = duplicate->next;
                }
                if(duplicate->next != NULL)
                {
                    duplicate->next->prev = duplicate->prev;
                }
                free(duplicate);
            }
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void remove_node(int data)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            if(temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                head = temp->next;
            }
            if(temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Node with data %d removed from list\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found in list\n", data);
}

int main()
{
    insert_at_front(5);
    insert_at_front(10);
    insert_at_front(15);
    insert_at_front(10);
    insert_at_front(20);
    insert_at_front(15);
    insert_at_front(25);

    printf("Original list: ");
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    remove_duplicates();

    printf("List after removing duplicates: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    remove_node(10);

    printf("List after removing node with data 10: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    remove_node(30);

    return 0;
}
