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


// //      Updated Single Linked List Using C 
// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void create(struct node **);
// void display(struct node *);
// void insert(struct node **);
// void delete (struct node **);

// int main()
// {
//     struct node *head = NULL;
//     int option;

//     printf("\nPlease select your desired option from below : \n");
//     printf("1.  Create a Linked List.\n");
//     printf("2.  Display the Linked List.\n");
//     printf("3.  Inserting a node to Linked List.\n");
//     printf("4.  Deleting a node from Linked List.\n");
//     printf("5.  EXIT\n");
//     scanf("%d", &option);

//     while (option != 5)
//     {
//         switch (option)
//         {
//         case 1:
//             create(&head);
//             display(head);
//             break;
//         case 2:
//             display(head);
//             break;
//         case 3:
//             insert(&head);
//             display(head);
//             break;
//         case 4:
//             delete (&head);
//             display(head);
//             break;
//         default:
//             printf("Please enter a number between 1 and 5 according to your choice : ");
//             break;
//         }
//         printf("\nPlease select your desired option from below : \n");
//         printf("1.  Create a Linked List.\n");
//         printf("2.  Display the Linked List.\n");
//         printf("3.  Inserting a node to Linked List.\n");
//         printf("4.  Deleting a node from Linked List.\n");
//         printf("5.  EXIT\n");
//         scanf("%d", &option);
//     }
//     return 0;
// }

// void create(struct node **h)
// {
//     struct node *curr, *ptr;
//     int n, i;
//     printf("Enter the number of nodes you want : ");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         curr = (struct node *)malloc(sizeof(struct node));
//         printf("Enter the data of Node %d : ", i + 1);
//         scanf("%d", &curr->data);
//         curr->next = NULL;

//         if (*h == NULL)
//         {
//             *h = curr;
//             ptr = curr;
//         }
//         else
//         {
//             ptr->next = curr;
//             ptr = curr;
//         }
//     }
// }

// void display(struct node *h)
// {
//     struct node *curr;
//     for (curr = h; curr != NULL; curr = curr->next)
//     {
//         printf("%d\t", curr->data);
//     }
// }

// void insert(struct node **h)
// {
//     int v, p;
//     struct node *curr, *ptr;
//     printf("Enter the value you want to add : ");
//     scanf("%d", &v);
//     printf("Enter the position at which you want to enter the value : ");
//     scanf("%d", &p);

//     curr = (struct node *)malloc(sizeof(struct node));
//     curr->data = v;
//     curr->next = NULL;

//     if (*h == NULL)
//     {
//         (*h) = curr;
//     }
//     else if (p == 0)
//     {
//         curr->next = *h;
//         *h = curr;
//     }
//     else
//     {
//         ptr = *h;
//         int i = 1;
//         while (i < p && ptr->next != NULL)
//         {
//             ptr = ptr->next;
//             i++;
//         }
//         curr->next = ptr->next;
//         ptr->next = curr;
//     }
// }

// void delete (struct node **h)
// {
//     struct node *ptr;
//     int p;
//     printf("Enter the position at which you want to delete : ");
//     scanf("%d", &p);

//     if (*h == NULL)
//     {
//         printf("Linked List is Empty.");
//     }
//     else if (p == 1)
//     {
//         ptr = *h;
//         *h = ptr->next;
//         free(ptr);
//     }
//     else
//     {
//         ptr = *h;
//         struct node *prv;
//         int i = 1;
//         while (i < p && ptr != NULL)
//         {
//             i++;
//             prv = ptr;
//             ptr = ptr->next;
//         }
//         if (ptr == NULL)
//         {
//             printf("Not found.");
//         }
//         else
//         {
//             prv->next = ptr->next;
//             free(ptr);
//         }
//     }
// }
