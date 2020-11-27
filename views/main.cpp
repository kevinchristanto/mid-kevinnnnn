#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../controllers/controllers.h"

int main()
{
    Node *people = NULL;
    int total, cure;
    scanf("%d %d", &total, &cure);
    for (int i = 0; i < total; i++)
    {
        scanf("%d %[^\n] %d - %[^\n]", &people->a.day, people->a.month, &people->a.year, people->a.name);
        people = people->next;
    }

    if ((total - cure) > 0)
    {
        printf("Need %d cure more\n", total - cure);
        print();
    }
    else
    {
        printf("All the patients get cured, %d cure left\n", total - cure);
        print();
    }

    return 0;
}