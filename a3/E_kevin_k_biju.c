#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


// An implementation of stack in C, using realloc() tied to a struct.
struct stack
{
    int64_t* arrayptr;
    int64_t element_count;
};

struct stack stack_create()
{
    struct stack temp =  { .arrayptr = NULL, .element_count = 0 };
    return temp;
}

void stack_push(struct stack* stack, int64_t element)
{
    stack->element_count = stack->element_count + 1;   
    stack->arrayptr = realloc(stack->arrayptr, sizeof(int64_t) * stack->element_count);
    for(int64_t i = 0; i < stack->element_count - 1; i++)
    {
        (stack->arrayptr)[i + 1] = (stack->arrayptr)[i];
    }
    (stack->arrayptr)[0] = element;    
}

void stack_pop(struct stack* stack)
{
    for(int64_t i = 1; i < stack->element_count; i++)
    {
        (stack->arrayptr)[i - 1] = (stack->arrayptr)[i];
    }
    stack->element_count = stack->element_count - 1;
    stack->arrayptr = realloc(stack->arrayptr, sizeof(int64_t) * stack->element_count);    
}

void stack_free(struct stack* stack)
{
  if(stack->arrayptr != NULL)
  {
    free(stack->arrayptr);
    stack->arrayptr = NULL;
  }  
}

// The main issue the parser faces is to account for nested loops, since an outer loop depends on the 
// complete processing of an inner loop to evaluate correctly. The main elements to note of is:
//
//  loop_count_stack -> stores the number of times each loop has to be repeated.
//  loop_store_stack -> stores the "offset" of the turtle for each iteration of the loop.
//      After a loop finishes evaluating, the offset is multiplied with the loop count and added
//      to either the next level of loop or directly to the turtle's position.
//  
//  When the parser finds an "END" instruction, one level of loop has ended. So the corresponding values
//  are popped from the stack. If the stack only has one element, it is the outermost level of loop and we
//  can now operate directly on the turtle's current position. The in_loop boolean tracks this.

int main(void)
{
// int64_t is guaranteed to be a 64-bit signed integer, is an alias for long on most 64-bit x86 machines.    
    int64_t line_count;
    scanf("%ld\n", &line_count);
    char instruction[33];
    bool in_loop = false;
    int64_t current_position = 0;
    struct stack loop_count_stack = stack_create();
    struct stack loop_store_stack = stack_create();
    int64_t withdrawn_loop_count;
    int64_t withdrawn_loop_store;

    for(int64_t i = 0; i < line_count; i++)
    {
// we use fgets() instead of the traditional scanf() here because scanf() stops reading 
// when it encounters a space.     
// We use the first letter of the instruction to distinguish if it is a "FD", "LOOP" or "END"
// instruction. strtoll() is used for passing the integer part of the integer.   
        fgets(instruction, 33, stdin);
        if(instruction[0] == 'F')
        {
            if(in_loop == true)
            {
                (loop_store_stack.arrayptr)[0] = (loop_store_stack.arrayptr)[0]
                 + strtoll(instruction + 3, NULL, 10);
            }
            else if(in_loop == false)
            {
                current_position = current_position + strtoll(instruction + 3, NULL, 10);
            }
        }
        else if(instruction[0] == 'L')
        {
            stack_push(&loop_count_stack, strtoll(instruction + 5, NULL, 10));
            stack_push(&loop_store_stack, 0);
            in_loop = true;
        }
        else if(instruction[0] == 'E')
        {
            withdrawn_loop_count = (loop_count_stack.arrayptr)[0];
            withdrawn_loop_store = (loop_store_stack.arrayptr)[0];
            stack_pop(&loop_count_stack);
            stack_pop(&loop_store_stack);
            if(loop_count_stack.element_count == 0)
            {
                current_position = current_position + (withdrawn_loop_count * withdrawn_loop_store);
                in_loop = false;
            }
            else if(loop_count_stack.element_count != 0)
            {
                (loop_store_stack.arrayptr)[0] = (loop_store_stack.arrayptr)[0]
                 + (withdrawn_loop_count * withdrawn_loop_store);
            }       
        }
    }

    printf("%ld", current_position);
    fflush(stdout);
    stack_free(&loop_count_stack);
    stack_free(&loop_store_stack);
    return 0;
}