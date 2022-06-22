#include <stdlib.h>
#include <stack_adt.h>
#include <stdio.h>

typedef struct node_t {
    void * data;
}node_t;

typedef struct stack_adt_t{
    uint size;
    uint items;
    node_t ** stack_array;
}stack_adt_t;


stack_adt_t * stack_init(uint32_t stack_size){
    stack_adt_t * new_stack = (stack_adt_t *)calloc(1, sizeof(stack_adt_t));
    new_stack->size = stack_size;
    new_stack->items = 0;
    new_stack->stack_array = (node_t **)calloc(stack_size, sizeof(*(new_stack->stack_array)));
    return new_stack;
}


void stack_push(stack_adt_t * stack, void * node){
    if (stack->items == stack->size)
    {
        fprint(stderr, "No more items can currently be pushed to the stack");
        return;
    }

    uint current = stack->items;
    stack->stack_array[current] = node;
    stack->items++;
}

void * stack_nth_peek(stack_adt_t * stack, uint32_t index){
    void * ptr = (void *)3;
    return ptr;

}

void * stack_pop(stack_adt_t * stack){
    void * ptr = (void *)3;
    return ptr;

}

void stack_dump(stack_adt_t * stack){

}

void stack_destroy(stack_adt_t * stack){
    if (NULL == stack)
    {
        return;
    }
    
    for(int i = 0; i < stack->items; i++){
        free(stack->stack_array[i]);
    }
    free(stack);
    stack = NULL;
}