#include <stdio.h>
struct list
{
    int Element;
    struct list *next;
};
typedef struct list node;

void insert_at(node **st, node *newnode, int position)
{
    int count=1;
    node *first=*st;
    if(position == count)
    {
        newnode->next = *st;
        *st = newnode;
        return;
    }
    else if(first == NULL)
        printf("\nError: Index out of bound\n");
    else
    {
        while(1)
        {
            count+=1;
            if(first->next == NULL)
            {
                if(count == position)
                    first->next = newnode;
                else
                    printf("\nError: Index out of bound\n");
                break;
            }
            if(count == position)
            {
                newnode->next = first->next;
                first->next = newnode;
                break;
            }
            first = first->next;
        }
    }
}

void traverse_list(node *first)
{
    if(first == NULL)
    {
        printf("The list is empty.\n\nPress any key to continue...");
        getch();
        return;
    }

    while(first != NULL)
    {
        printf("%d ", first->Element);
        first = first->next;
    }
    printf("\n\nPress any to continue...");
    getch();
}

int find_length(node * first)
{
    int length = 0;
    while(first != NULL)
    {
        length += 1;
        first = first->next;
    }
    return length;
}

int main()
{
    int choice, position;
    node *start=NULL, *record;
    do
    {
        system("cls");
        printf("\n1:INSERT\n2:LENGTH\n3:TRAVERSELIST\n4:EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        if(choice == 1)
        {
            record = (node *) malloc(sizeof(node));
            printf("Enter the number: ");
            scanf("%d", &record->Element);
            printf("Enter the position: ");
            scanf("%d", &position);
            record->next = NULL;
            insert_at(&start, record, position);
            printf("\n");
            traverse_list(start);
            printf("\n");
        }
        else if(choice == 2)
        {
            printf("The length of the linked list is: %d",find_length(start));
            printf("\n\nPress any to continue...");
            getch();
        }
        else if(choice == 3)
        {
            printf("\n");
            traverse_list(start);
            printf("\n");
        }
    }
    while(choice != 4);
    return 0;
}
