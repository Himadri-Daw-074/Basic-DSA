#include<stdio.h>
#include<stdlib.h>

//global variables
struct node{
    int data;
    struct node *next;
}*head,*var,*trav;

//Function prototype declarations
void push(int);
void pop(int);
int display();

//Main function
int main(){
    int i, value, disp;
    head=NULL;
    while(1){
        printf("***************** MENU ******************\n");
        printf("* 1 -- Push an element into stack *\n");
        printf("* 2 -- Pop an element from stack *\n");
        printf("* 3 -- Print the stack *\n");
        printf("* 4 -- Exit *\n");
        printf("*******************************************\n");
        printf("\nEnter your choice : ");
        scanf("%d",&i);
        switch(i){
            case 1:
                printf("\nEnter the value to be pushed : ");
                scanf("%d",&value);
                push(value);
                disp = display();
                break;
            case 2:
                pop(value);
                disp = display();
                break;
            case 3:
                disp = display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }//end of switch
    }//end of while
}

//Functions implementation
void push(int value){
    var=(struct node *)malloc(sizeof (struct node));
    var->data=value;
    var->next=NULL;
    if(head==NULL){
        head=var;
    }
    else{
        var->next=head;
        head=var;
    }
}//end of push

void pop(int value){
    if(head==NULL){
        printf("\nStack is empty. Cannot pop.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}//end of pop

int display(){
    if(head==NULL){
        printf("\nStack is empty.\n");
        return 0;
    }
    trav=head;
    printf("\nStack: ");
    while(trav!=NULL){
        printf("%d -> ",trav->data);
        trav=trav->next;
    }
    printf("NULL\n");
    return 1;
}//end of display