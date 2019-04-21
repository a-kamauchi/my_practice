/*------------------------------------------------------------
 * sort.c
 *
 *------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"


/* ソート関数 */
sort_function1	SortFunction1[] = {bubble_sort,
								  selection_sort};
sort_function2	SortFunction2[] = {quick_sort};


/* オプション情報 */
typedef struct SortOptions
{
	SortType1	sort_type1;
	SortType2	sort_type2;

	int		   *num_array;
	int			array_len;
} SortOptions;


/* ヘルパー関数の定義 */
static int *get_num_array(unsigned int array_len, unsigned int digit);
static void free_options(SortOptions *sort_opt);


/*
 * Sort		- ソート処理
 */
void
Sort(SortOptions *sort_opt)
{
	printf("[Before] ");
	show_array(sort_opt->num_array, sort_opt->array_len);

	QuickSort(sort_opt->num_array, 0, sort_opt->array_len - 1);

	printf("[After ] ");
	show_array(sort_opt->num_array, sort_opt->array_len);
}

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
 * get_num_array	- ランダムな数値を生成
 */
static int *
get_num_array(unsigned int array_len, unsigned int digit)
{
	int	*num_array;
	int	 digit_num = 1;
	int	 i;

	num_array = (int *) malloc(sizeof(int) * array_len);

	for (i = 0; i < digit; i++)
		digit_num *= 10;

	srand((unsigned) time(NULL));
	for (i = 0; i < array_len; i++)
		num_array[i] = rand() % digit_num;

	return num_array;
}

/*
 * free_options		- SortOptions構造体の解放
 */
static void
free_options(SortOptions *sort_opt)
{
	if (sort_opt == NULL)
		return;

	if (sort_opt->num_array != NULL)
	{
		free(sort_opt->num_array);
		sort_opt->num_array = NULL;
	}

	free(sort_opt);
	sort_opt = NULL;
}

/*
 * エントリーポイント
 */
int
main(int argc, char *argv[])
{
	SortOptions	*sort_opt;

	sort_opt = (SortOptions *) malloc(sizeof(SortOptions));
	sort_opt->array_len = 10;
	sort_opt->num_array = get_num_array(sort_opt->array_len, 3);

	/* ソート */
	Sort(sort_opt);

	/* 後始末 */
	free_options(sort_opt);

	return 0;
}

