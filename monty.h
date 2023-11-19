#ifndef BISKIT_MONTY_H
#define BISKIT_MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list rep of a stack and/or queues.
 * @n: integer
 * @prev: ptr to previous element of the stack and/or queue.
 * @next: ptr to next element of the stack and/or queue.
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


/*Fxn prototypes for file operations*/
void opener(char *file_name);
int parser(char *buffer, int line_number, int format);
void reader(FILE *);
void loc(char *, char *, int, int);

/* Fxn prototypes of stack operations*/
stack_t *creator(int n);
void free_mem(void);
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void enqueue(stack_t **, unsigned int);

void caller(op_func, char *, char *, int, int);

void pinto(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapn(stack_t **, unsigned int);

/* Fxn prototypes for Math operations with nodes*/
void addxn(stack_t **, unsigned int);
void subxn(stack_t **, unsigned int);
void divxn(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

/* Fxn prototypes for string operations*/
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Fxn prototype for hanlding all errors*/
void progErr(int error_num, ...);
void Errmes(int error_num, ...);
void stringer(int error_num, ...);
void rotr(stack_t **, unsigned int);

#endif /* BISKIT_MONTY_H */
