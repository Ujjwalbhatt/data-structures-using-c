#include <stdio.h>
int stack[100], n = 100, top = -1;
void push(int val)
{
    if (top >= n - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Popped item is : %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("stacks items are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);

        }
    }
    else{
        printf("Stack is empty");
    }
}
int main(){
    int ch, val;
    push(34);
    push(67);
    push(56);
    pop();
    display();
    return 0;

}