#include <stdio.h>

static void op_a(void)
{
    printf("A\n");
}

static void op_b(void)
{
    printf("B\n");
}

/*
 * Main entry point
 *
 * This program demonstrates the use of an array of function pointers.
 *
 * 'ops' is an array where each element is a pointer to a function
 * that takes no arguments and returns void.
 *
 * The array is initialized with two functions: op_a and op_b.
 * Calling ops[1]() will invoke op_b().
 */
int main(void)
{
    void (*ops[])(void) = {op_a, op_b};

    ops[1]();

    return 0;
}