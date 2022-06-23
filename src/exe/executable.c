#include <stdio.h>
#include <stack_adt.h>
#include <string.h>
#include <stdlib.h>

char * create_payload(const char * payload)
{
    return strdup(payload);
}

/*
 * Do not use this file to test if you code works. I would just comment out
 * this code in your cmake and USE YOUR UNIT TESTS! Then when your unit tests
 * all work this file should work first try because you put in the time to
 * create your unit tests
 */
int main(void)
{
    stack_adt_t  * stack = stack_init(5);
    int buff[5] = {6 ,7 ,8 ,9 ,10};

    // Notice how there is now heap address in your structure. How are  you
    // going to free them?
    for (int index = 0; index < 5; index++)
    {
        //snprintf(buff, 30, "Hello world: %d\n", index);
        //stack_push(stack, create_payload(buff));
        stack_push(stack, &buff[index]);
    }

    // This is how you can cast your payloads
    void * pop_payload = NULL;
    void * peek_payload = NULL;
    int index = 0;

    if (NULL != (pop_payload = stack_pop(stack)))
    {
        printf("data popped: %d\n\n", *(int*)pop_payload);
    }
    
    index = stack->items - 1;
    if (NULL != (peek_payload = stack_nth_peek(stack, index)))
    {
        printf("data at node %d: %d\n\n", index, *(int*)peek_payload);
    }

    stack_dump(stack);


    free(pop_payload);
    free(peek_payload);
    stack_destroy(stack);
}