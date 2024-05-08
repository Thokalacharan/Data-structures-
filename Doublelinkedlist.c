/*C Program to perform operations on Doubly Linked List*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node NODE;
void create();
void insertfront(int);
void insertlast(int);
void insertpos(int,int);
void deletefront();
void deletelast();
void deletepos();
void traversalLtoR();
void traversalRtoL();
NODE *head = NULL;
int main()
{
    int choice, item, pos;
    create();
    while(1)
    {
        printf("\nMENU\n");
        printf("1.Insert front\n2.Insert Last\n3.Insert at the specified Position\n4.Delete front\n5.Delete Last\n6.Delete at the specified position\n7.Traversal (left to right)\n8.Traversal (right to left\n9.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d",&item);
            insertfront(item);
            break;
        case 2:
            printf("Enter the element to be inserted:");
            scanf("%d",&item);
            insertlast(item);
            break;
        case 3:
            printf("Enter the element:");
            scanf("%d",&item);
            printf("Enter the position:");
            scanf("%d",&pos);
            insertpos(item,pos);
            break;
        case 4:
            deletefront();
            break;
        case 5:
            deletelast();
            break;
        case 6:
            printf("Enter the pos:");
            scanf("%d",&pos);
            deletepos(pos);
            break;
        case 7:
            traversalLtoR();
            break;
        case 8:
            traversalRtoL();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
void create()
{
    NODE *cur, *temp;
    int item, ch;
    do
    {
        printf("Enter the element:");
        scanf("%d",&item);
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = item;
        if(head==NULL)
        {
            head = cur = temp;
        }
        else
        {
            cur->next = temp;
            temp->prev = cur;
            cur = temp;
        }
        printf("Press 1 to continue:");
        scanf("%d",&ch);
    } while(ch==1);
    head->prev = NULL;
    cur->next = NULL;
}
void insertfront(int item)
{
    NODE* temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}
void insertlast(int item)
{
    NODE *temp, *cur;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    if(head==NULL)
    {
        head=temp;
        temp->prev = NULL;
    }
    else
    {
        cur=head;
        while(cur->next!=NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->prev = cur;
    }
    temp->next = NULL;
}
void insertpos(int item,int pos)
{
    int i;
    NODE *cur1=head, *cur2, *temp;
    if(pos==1)
        insertfront(item);
    else
    {
        for(i=1; i<=(pos-2) && cur1!=NULL; i++)
            cur1=cur1->next;
        if(cur1==NULL)
            printf("Invalid Position\n");
        else
        {
            cur2 = cur1->next;
            if(cur2==NULL)
                insertlast(item);
            else
            {
                temp = (NODE*)malloc(sizeof(NODE));
                temp->data = item;
                temp->next = cur2;
                cur2->prev = temp;
                cur1->next = temp;
                temp->prev = cur1;
            }
        }
    }
}
void deletefront()
{
    NODE *temp;
    if(head==NULL) printf("List is empty\n");
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("Element deleted: %d\n",temp->data);
        free(temp);
    }
}
void deletelast()
{
    NODE *temp, *cur;
    if(head==NULL) printf("List is empty\n");
    else if(head->next==NULL)
    {
        temp = head;
        head = NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
    else
    {
        cur = head;
        while(cur->next->next != NULL)
            cur = cur->next;
        temp = cur->next;
        cur->next = NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
}
void deletepos(int pos)
{
    int i;
    NODE *cur1=head, *cur2, *temp;
    if(pos==1)
        deletefront();
    else
    {
        for(i=1; i<=(pos-2) && cur1->next!=NULL; i++)
            cur1=cur1->next;
        if(cur1->next == NULL)
            printf("Invalid Position\n");
        else
        {
            temp = cur1->next;
            cur2 = temp->next;
            if(cur2==NULL)
                deletelast();
            else
            {
                cur1->next = cur2;
                cur2->prev = cur1;
                printf("Deleted element: %d\n",temp->data);
                free(temp);
            }
        }
    }
}
void traversalLtoR()
{
    NODE *cur=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        printf("List content:\n");
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur = cur-> next;
        }
    }
}
void traversalRtoL()
{
    NODE *cur=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        while(cur->next!=NULL)
            cur=cur->next;
        while(cur!=NULL)
        {
            printf("%4d",cur->data);
            cur=cur->prev;
        }
    }
}
void display()
{
    NODE *temp=head;
    if(head==NULL)
        printf("Stack is empty\n");
    else
    {
        printf("Stack content:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp-> next;
        }
    }
}

   