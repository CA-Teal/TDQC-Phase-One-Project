#include <stdlib.h>
#include <stack_adt.h>
#include <stdio.h>


stack_adt_t * stack_init(uint32_t stack_size){
    stack_adt_t * new_stack = (stack_adt_t *)calloc(1, sizeof(stack_adt_t));
    if (NULL == new_stack)
    {
        fprintf(stderr, "Error: Memory could not be allocated for the stack\n\n");
        return NULL;
    }

    new_stack->size = stack_size;
    new_stack->items = 0;

    new_stack->stack_array = (node_t*)calloc(stack_size, sizeof(*(new_stack->stack_array)));
    if (NULL == new_stack->stack_array)
    {
        fprintf(stderr, "Error: Memory could not be allocated for the node array\n\n");
        return NULL;
    }

    return new_stack;
}


void stack_push(stack_adt_t * stack, void * data){
    if (stack->items == stack->size)
    {
        fprintf(stderr, "No more items can currently be pushed to the stack\n\n");
        return;
    }
    
    uint current = stack->items;
    stack->stack_array[current].data = calloc(1, sizeof(void*));
    if (NULL == stack->stack_array[current].data)
    {
        fprintf(stderr, "Error: Memory could not be allocated for the node's data\n\n\n");
        return;
    }
    

    memcpy(stack->stack_array[current].data, data, sizeof(void*));
    stack->items++;
}

void * stack_pop(stack_adt_t * stack){
    if (NULL == stack)
    {
        fprintf(stderr, "Error: The stack contains no more items\n\n");
        return NULL;
    }

    int top_node = stack->items - 1;
    void * pop_data = calloc(1, sizeof(void*));
    if (NULL == pop_data)
    {
        fprintf(stderr, "Error: Memory could not be allocated for the variable\n\n");
        return NULL;
    }

    memcpy(pop_data, stack->stack_array[top_node].data, sizeof(void*));
    free(stack->stack_array[top_node].data);

    printf("node %d data popped\n\n", top_node);
    stack->items--;
    return pop_data;
}

void * stack_nth_peek(stack_adt_t * stack, uint32_t index){
    if (NULL == stack)
    {
        fprintf(stderr, "Error: The stack contains no items\n\n");
        return NULL;
    }else if (index > (stack->items - 1))
    {
        fprintf(stderr, "Error: The position is outside of the stacks range\n\n");
        return NULL;
    }
    
    
    void * peek_data = calloc(1, sizeof(void*));
    if (NULL == peek_data)
    {
        fprintf(stderr, "Error: Memory could not be allocated for the variable\n\n");
        return NULL;
    }

    memcpy(peek_data, stack->stack_array[index].data, sizeof(void*));

    return peek_data;

}


void stack_dump(stack_adt_t * stack){
    if (NULL == stack)
    {
        fprintf(stderr, "Error: The stack contains no items\n\n");
        return;
    }

    printf("Dumping...\n");
    for (size_t i = 0; i < stack->items; i++)
    {
        printf("node %ld data: %d...\n", i, *(int*)stack->stack_array[i].data);
        free(stack->stack_array[i].data);
        stack->stack_array[i].data = NULL;
    }

    stack->items = 0;    
}

void stack_destroy(stack_adt_t * stack){
    if (NULL == stack)
    {
        return;
    }
    for (size_t i = 0; i < stack->items; i++)
    {
        if (NULL == stack->stack_array[i].data)
        {
            continue;
        }
        
        free(stack->stack_array[i].data);
    }
    
    free(stack->stack_array);
    free(stack);
    stack = NULL;
}