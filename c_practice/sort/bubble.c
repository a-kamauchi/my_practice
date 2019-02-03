/*------------------------------------------------------------
 * bubble.c
 *
 * # バブルソートの練習
 *
 *------------------------------------------------------------
 */
#include <stdio.h>

#include <sort.h>


/*
 * bubble_sort	- 数値配列(num_array)を昇順ソート
 */
void 
bubble_sort(int *num_array, int array_len)
{
	int		i;

	for (i = 1; i < array_len; i++)
	{
		int	j;

		/* 終端値を決める */
		for (j = 0; j < array_len - i; j++)
		{
			if (num_array[j] > num_array[j + 1])
				SwapArrayElement(num_array, j, j + 1);
		}
	}
}
