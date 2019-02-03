/*------------------------------------------------------------
 * sort.c
 *
 *------------------------------------------------------------
 */
#include <stdio.h>

#include "sort.h"


/* ソート関数 */
sort_function1	SortFunction1[] = {bubble_sort,
								  selection_sort};
sort_function2	SortFunction2[] = {quick_sort};


/*
 * show_array   - num_array配列をカンマ区切りで表示
 */
void
show_array(int *num_array, int array_len)
{
	int		i;
	char	*separator = ", ";

	if (array_len < 0)
	{
		fprintf(stderr, "invalid array length is specified:\"%d\"\n",
						array_len);
		return;
	}

	for (i = 0; i < array_len; i++)
		printf("%d%s", num_array[i], (i < array_len - 1) ? separator : "\n");
}

/*
 * エントリーポイント
 */
int
main(int argc, char *argv[])
{
	int			target_array[] = {9, 4, 6, 2, 1, 8, 0, -3, 7, 5, 1, 3};
	int			array_len = 12;

	printf("[Before] ");
	show_array(target_array, array_len);

	QuickSort(target_array, 0, array_len - 1);

	printf("[After ] ");
	show_array(target_array, array_len);

	return 0;
}
