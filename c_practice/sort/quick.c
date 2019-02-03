/*------------------------------------------------------------
 * quick.c
 *
 * # クイックソートの練習
 *
 *------------------------------------------------------------
 */
#include <stdio.h>

#include <sort.h>


/*
 * quick_sort	- 数値配列(num_array)を昇順ソート
 */
void 
quick_sort(int *num_array, int left_idx, int right_idx)
{
	int		pivot;	/* 基準値 */
	int		i,		/* 基準値より左側のインデックス */
			j;		/* 基準値より右側のインデックス */

	i = left_idx;
	j = right_idx;

	/* 配列の中央の値を基準値とする */
	pivot = num_array[(left_idx + right_idx) / 2];

	while (1)
	{
		/* 基準値よりも大きな値を持つ要素を配列の左側から探索 */
		while (num_array[i] < pivot)
			i++;

		/* 基準値よりも小きな値を持つ要素を配列の右側から探索 */
		while (pivot < num_array[j])
			j--;

		/* 2つのインデックスが交差すればループを抜ける */
		if (i >= j)
			break;

		/* 2つの要素を交換する */
		SwapArrayElement(num_array, i, j);

		/* 次の要素へ進む */
		i++;
		j--;
	}

	/* 基準値の左側に2つ以上の要素があれば左側だけでクイックソート */
	if (left_idx < i - 1)
		quick_sort(num_array, left_idx, i - 1);

	/* 基準値の左側に2つ以上の要素があれば右側だけでクイックソート */
	if (j + 1 < right_idx)
		quick_sort(num_array, j + 1, right_idx);
}
