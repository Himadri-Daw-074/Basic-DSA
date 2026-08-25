#include<stdio.h>
#include<stdlib.h>

//Function prototype declarations

void insert_at_begning(int);
void insert_at_end(int);
void insert_at_middle(int, int);
void delete_from_middle(int);
void delete_from_end();
int display();

//Structure declaration

struct node
{
int data;
struct node *next;
}*head,*var,*trav;

//Main function

void main()
{
int i=0, value, loc, disp;
head=NULL;
while(1)
{
printf("***************** MENU ******************\n");
printf("* 1 -- Insert at begning of linked list *\n");
printf("* 2 -- Insert at the end of linked list *\n");
printf("* 3 -- Insert at the middle *\n");
printf("* 4 -- Delete from the end of linked list *\n");
printf("* 5 -- Delete a specific data *\n");
printf("* 6 -- Print the linked list *\n");
printf("* 7 -- Exit *\n");
printf("*******************************************\n");
printf("\nEnter your choice : ");
scanf("%d",&i);
switch(i)
{
case 1:
printf("\nEnter the value to be inserted : ");
scanf("%d",&value);
insert_at_begning(value);
disp = display();
break;
case 2:
printf("\nEnter value to be inserted : ");
scanf("%d",&value);
insert_at_end(value);
disp = display();
break;
case 3:
printf("\nEnter the value to be inserted : ");
scanf("%d",&value);
printf("\nInsert after : ");
scanf("%d",&loc);
insert_at_middle(value,loc);
disp = display();
break;
case 4:
disp = display();
if(disp!=0)
{
delete_from_end();
disp = display();
}
break;
case 5:
disp = display();
if(disp!=0)
{
printf("\nEnter the data to be deleted : ");
scanf("%d",&value);
delete_from_middle(value);
disp = display();
}
break;
case 6:
disp = display();
break;
case 7:
exit(0);
}//end of switch
}//end of while
}//end of main

//Functions implementation

void insert_at_begning(int value)
{
var=(struct node *)malloc(sizeof (struct node));
var->data=value;
if(head==NULL)
{
head=var;
head->next=NULL;
}
else
{
var->next=head;
head=var;
}
}//end of insert_at_begning


void insert_at_end(int value)
{
var=(struct node *)malloc(sizeof (struct node));
var->data=value;
var->next=NULL;
if(head==NULL)
{
head=var;
}
else
{
trav=head;
while(trav->next!=NULL)
{
trav=trav->next;
}
trav->next=var;
}
}//end of insert_at_end


void insert_at_middle(int value, int loc)
{
var=(struct node *)malloc(sizeof (struct node));
var->data=value;
var->next=NULL;
if(head==NULL)
{
head=var;
}
else
{
    trav=head;
    for(int i=0; i<loc-1 && trav->next!=NULL; i++)
    {
        trav=trav->next;
    }
    var->next=trav->next;
    trav->next=var;
}
}//end of insert_at_middle


void delete_from_middle(int value)
{
    if(head==NULL)
    {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }
    
    struct node *temp = head, *prev = NULL;
    
    // If head node itself holds the value to be deleted
    if(temp != NULL && temp->data == value)
    {
        head = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
    
    // Search for the value to be deleted, keep track of the previous node
    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    
    // If value was not present in linked list
    if(temp == NULL)
    {
        printf("\nValue %d not found in the list.\n", value);
        return;
    }
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    free(temp); // Free memory
}//end of delete_from_middle


void delete_from_end()
{
    if(head == NULL)
    {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }
    
    struct node *temp = head;
    
    // If there is only one node in the list
    if(temp->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    
    // Traverse to the second last node
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    
    free(temp->next); // Free memory of last node
    temp->next = NULL; // Change next of second last node
}//end of delete_from_end


int display()
{
    if(head == NULL)
    {
        printf("\nList is empty.\n");
        return 0;
    }
    
    trav = head;
    printf("\nLinked List: ");
    while(trav != NULL)
    {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
    return 1;
}//end of display