#include <stdio.h>
#include <stdlib.h>
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack *createStack(int cap)
{
    struct ArrayStack *stack;
    stack = malloc(sizeof(struct ArrayStack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = malloc(sizeof(int) * stack->capacity);
    return (stack);
}
int isFull(struct ArrayStack *stack)
{
    if (stack->top == stack->capacity - 1)
    {
        return 1;
    }
    else
        return 0;
}
int isEmpty(struct ArrayStack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
void push(struct ArrayStack *stack, int value)
{
    if(!isFull(stack)){
       stack->top++;
       stack->array[stack->top] = value;
    }
    else{
        printf("\nStack overflow!!");
    }
}
int pop(struct ArrayStack *stack){
    int value;
    
    if(!isEmpty(stack)){ 
        value = stack->array[stack->top];
        printf("Value %d is popped out from stack\n", value);
        stack->top--;
    }
    else{
        printf("stack is empty\n");
    }
}

void printStack(struct ArrayStack* stack){
    if(!isEmpty(stack)){
        for(int i = 0 ; i<=stack->top;i++){
            printf("%d ", stack->array[i]);
        }
    }
    else{
        printf("stack is empty");
    }

}
int main()
{
    struct ArrayStack *stack;
    
    stack = createStack(4);
    pop(stack);
    push(stack,12);
    push(stack,3);
    push(stack,15);
    push(stack,134);
    printStack(stack);
    push(stack,13);
    return 0;
}