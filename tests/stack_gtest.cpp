#include <gtest/gtest.h>
#include <stack_adt.h>


TEST(BaseTest, CreateStack)
{
    stack_adt_t * new_stack = stack_init(5);
    EXPECT_NE(new_stack, nullptr);
    stack_destroy(new_stack);
}

TEST(BaseTest, PushNode)
{
    stack_adt_t * new_stack = stack_init(5);
    int data = 67;
    int data2 = 89;
    stack_push(new_stack, &data);
    stack_push(new_stack, &data2);
    EXPECT_EQ(new_stack->items , 2);
    EXPECT_EQ(*(int*)new_stack->stack_array[0].data, data);
    stack_destroy(new_stack);
}

TEST(BaseTest, PopNode)
{
    stack_adt_t * new_stack = stack_init(5);
    int data = 67;
    stack_push(new_stack, &data);
    void * data_catch = stack_pop(new_stack);
    EXPECT_EQ(*(int*)data_catch, data);
    stack_destroy(new_stack);
    free(data_catch);
}

TEST(BaseTest, SeekNode)
{
    stack_adt_t * new_stack = stack_init(5);
    int data = 67;
    int data1 = 58; 
    int data2 = 3;
    stack_push(new_stack, &data);
    stack_push(new_stack, &data1);
    stack_push(new_stack, &data2);
    void * peek_info = stack_nth_peek(new_stack, 2);
    if(NULL != peek_info){
        EXPECT_EQ(*(int*)peek_info, data2);
    }else{
        EXPECT_EQ(peek_info, nullptr);
    }
    stack_destroy(new_stack);
    free(peek_info);
}