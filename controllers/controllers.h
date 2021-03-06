#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../models/models.h"

Node *createNode(patient *a)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->a.name, a->name);
    temp->a.day = a->day;
    strcpy(temp->a.month, a->month);
    temp->a.year = a->year;
    temp->prev = temp->next = NULL;
    return temp;
}

void insert(patient *a)
{
    Node *temp = createNode(a);
    if (!head)
    {
        head = tail = temp;
    }
    else if (a->year > head->a.year)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else if (a->year < tail->a.year)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        Node *curr = createNode(a);
        while (curr)
        {
            if (curr->a.year == a->year)
            {
                curr = curr->next;
            }
            curr->next->prev = temp;
            temp->next = curr->next;
            curr->next = temp;
            temp->prev = curr;
        }
    }
}

void deletion(patient *a)
{
    {
        if (head && head == tail)
        {
            head = tail = NULL;
            free(head);
        }
        else
        {
            Node *newTail = tail->prev;
            tail->prev = newTail->next = NULL;
            free(tail);
            tail = newTail;
        }
    }
}

void print()
{
    Node *curr = head;
    while (curr)
    {
        printf("%d\n", curr->a.day);
        curr = curr->next;
    }
}