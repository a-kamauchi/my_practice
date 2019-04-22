#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_struct.h"


/* スタック構造 */
typedef struct
{
	int *data_array;		/* a data array */
	int	 num_data;
	int	 current_index;		/* the latest position of this stack */
} StackData;

static StackData	*stack;


/*
 * 初期化
 */
void
initStack(int num_data)
{
	if (stack != NULL)
	{
		/* already initialized */
		return;
	}

	stack = (StackData *) malloc(sizeof(StackData));

	/* initialize the StackData */
	stack->data_array = (int *) malloc(sizeof(int) * num_data);
	stack->num_data = num_data;
	stack->current_index = 0;
}

/*
 * 後始末
 */
void
destroyStack(void)
{
	if (stack->data_array != NULL)
	{
		free(stack->data_array);
		stack->data_array = NULL;
	}
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}

/*
 * スタックへのデータ格納
 */
void
push(int *data)
{
	if (stack->current_index < stack->num_data)
	{
		stack->data_array[stack->current_index] = *data;
		stack->current_index++;
	}
}

/*
 * スタックからのデータ取得
 */
void
pop(int *data)
{
	if (stack->current_index > 0)
	{
		/* there are any data in this stack. */
		stack->current_index--;
		*data = stack->data_array[stack->current_index];
	}
}

