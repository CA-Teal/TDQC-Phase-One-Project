#ifndef TDQC_PHASE_ONE_SRC_STACK_STACK_ADT_H_
#define TDQC_PHASE_ONE_SRC_STACK_STACK_ADT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
typedef struct node_t node_t;
typedef struct stack_adt_t stack_adt_t;

stack_adt_t * stack_init(uint32_t stack_size);
void stack_destroy(stack_adt_t * stack);
void * stack_nth_peek(stack_adt_t * stack, uint32_t index);
void stack_push(stack_adt_t * stack, void * node);
void * stack_pop(stack_adt_t * stack);
void stack_dump(stack_adt_t * stack);

#ifdef __cplusplus
}
#endif
#endif //TDQC_PHASE_ONE_SRC_STACK_STACK_ADT_H_
