/*------------------------------------------------------------
 * selection.c
 *
 * # 選択ソートの練習
 *
 *------------------------------------------------------------
 */
#include <stdio.h>

#include "sort.h"


/*
 * selection_sort	- 数値配列(num_array)を昇順ソート
 */
void
selection_sort(int *num_array, int array_len)
{
	int	min_idx;
	int	i;

	for (i = 0; i < array_len - 1; i++)
	{
		int	j;

		min_idx = i;
		for (j = i + 1; j < array_len; j++)
		{
			if (num_array[min_idx] > num_array[j])
			{
				/* 最小値をもつ配列要素を更新 */
				min_idx = j;
			}
		}
		SwapArrayElement(num_array, i, min_idx);
	}
}
