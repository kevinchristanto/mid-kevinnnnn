#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../models/models.h"

Node *createNode(int day, char *month, int year, char *name)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->a.name, name);
    temp->a.day = day;
    strcpy(temp->a.month, month);
    temp->a.year = year;
    temp->prev = temp->next = NULL;
    return temp;
}

void insert(int day, char *month, int year, char *name)
{
    Node *temp = createNode(day, month, year, name);
    if (!head)
    {
        head = tail = temp;
    }
    else if (year > head->a.year)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else if (year < tail->a.year)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        Node *curr = createNode(day, month, year, name);
        while (curr)
        {
            if (curr->a.year == year)
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