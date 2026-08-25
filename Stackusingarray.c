#include<stdio.h>
#define max 100

//global variabales

int stack[max];
int top = -1;

//functions

int isfull();
int isempty();
int push();
int pop();
void display();

//main programme

int main(void)
{
int choice, value;

while(1)
{
    //Menu For Stack
    printf("\n-------Stack Menu-------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Check if stack is full or empty\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop(value);
            printf("Popped value: %d\n", value);
            break;
        case 3:
            display();
            break;
        case 4:
            if (isfull())
            {
                printf("Stack is full!\n");
            } 
            else if(isempty())
            {
                printf("Stack is empty!\n");
            }
            else
            {
                printf("Stack is neither full nor empty.\n");
            }
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
    }
}

return 0;
}

// Functions programme 

int isfull()
{
    if(top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int value)
{
    if(isfull() == 1)
    {
        printf("Cannot push %d, stack is full!\n", value);
        return -1;
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

int pop(int value)
{
    if(isempty() == 1)
    {
        printf("Cannot pop, stack is empty!\n");
        return -1;
    }
    else
    {
        value = stack[top];
        top--;
        printf("Popped %d from the stack.\n", value);
        return value;
    }
}

void display()
{
    if(isempty() == 1)
    {
        printf("Stack is empty, nothing to display!\n");
    }
    else
    {
        printf("Stack elements: ");
        for(int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}