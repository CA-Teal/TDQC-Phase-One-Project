#include <stdlib.h>
#include <stack_adt.h>
#include <stdio.h>


stack_adt_t * stack_init(uint32_t stack_size){
    stack_adt_t * new_stack = (stack_adt_t *)calloc(1, sizeof(stack_adt_t));
    new_stack->size = stack_size;
    new_stack->items = 0;
    new_stack->stack_array = (node_t*)calloc(stack_size, sizeof(*(new_stack->stack_array)));
    return new_stack;
}


void stack_push(stack_adt_t * stack, void * data){
    if (stack->items == stack->size)
    {
        fprintf(stderr, "No more items can currently be pushed to the stack");
        return;
    }
    
    uint current = stack->items;
    stack->stack_array[current].data = calloc(1, sizeof(void*));

    memcpy(stack->stack_array[current].data, data, sizeof(void*));
    stack->items++;
}

void * stack_pop(stack_adt_t * stack){
    if (NULL == stack)
    {
        fprintf(stderr, "The stack contains no more items");
        return NULL;
    }

    int top_node = stack->items - 1;
    void * pop_data = calloc(1, sizeof(void*));
    memcpy(pop_data, stack->stack_array[top_node].data, sizeof(void*));

    free(stack->stack_array[top_node].data);
    stack->items--;
    return pop_data;
}

void * stack_nth_peek(stack_adt_t * stack, uint32_t index){
    if (NULL == stack)
    {
        fprintf(stderr, "The stack contains no items");
        return NULL;
    }else if (index > (stack->items - 1))
    {
        fprintf(stderr, "The position is outside of the stacks range");
        return NULL;
    }
    
    
    void * peek_data = calloc(1, sizeof(void*));
    memcpy(peek_data, stack->stack_array[index].data, sizeof(void*));

    return peek_data;

}


void stack_dump(stack_adt_t * stack){

}

void stack_destroy(stack_adt_t * stack){
    if (NULL == stack)
    {
        return;
    }
    for (size_t i = 0; i < stack->items; i++)
    {
        free(stack->stack_array[i].data);
    }
    
    free(stack->stack_array);
    free(stack);
    stack = NULL;
    stack = NULL;
}