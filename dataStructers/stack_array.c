#include <stdio.h>

#define STACK_LENGHT 7

int	push(int stack[], int value, int *top)
{
	int	flag = 1;

	if (*top >= STACK_LENGHT - 1)
		flag = 0;

	if (flag)
		stack[++(*top)] = value;

	return (flag);
}

int	pop(int stack[], int *top)
{
	int result = 1;

	if (*top < 0) result = 0xffffffff/2 + 1;

	if (result == 1)
		result = stack[(*top)--];

	return (result);
}

int	main()
{
	int	stack[STACK_LENGHT], top;
	top = -1;

	printf("pop -> %d\n", pop(stack, &top));
	printf("push -> %d\n", push(stack, 31, &top));
	printf("push -> %d\n", push(stack, 69, &top));
	printf("pop -> %d\n", pop(stack, &top));
	printf("push -> %d\n", push(stack, 52, &top));
	printf("push -> %d\n", push(stack, 79, &top));
	printf("push -> %d\n", push(stack, 89, &top));
	printf("pop -> %d\n", pop(stack, &top));
	printf("push -> %d\n", push(stack, 109, &top));
	printf("push -> %d\n", push(stack, 1000, &top));
	printf("push -> %d\n", push(stack, 32, &top));
	printf("push -> %d\n", push(stack, 31, &top));
	printf("pop -> %d\n", pop(stack, &top));
	printf("push -> %d\n", push(stack, 69, &top));
	printf("push -> %d\n", push(stack, 52, &top));
	printf("pop -> %d\n", pop(stack, &top));

	return (0);
}