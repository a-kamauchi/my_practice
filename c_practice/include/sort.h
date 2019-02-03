/*------------------------------------------------------------
 * sort.h
 * 
 *------------------------------------------------------------
 */
#ifndef	SORT_H
#define	SORT_H


/* ソートアルゴリズム */
typedef enum
{
	BUBBLE = 0,
	SELECTION
} SortType1;

typedef enum
{
	QUICK = 0
} SortType2;

/* 配列の要素を入れ替える */
#define	SwapArrayElement(array, x, y) \
	do { \
		int		_tmp_; \
		_tmp_ = array[x]; \
		array[x] = array[y]; \
		array[y] = _tmp_; \
	} while (0)

/* ソート関数ポインタ */
typedef void (*sort_function1) (int *num_array, int array_len);
typedef	void (*sort_function2) (int *num_array, int left_idx, int right_idx);

/* ソート関数の関数ポインタ配列 */
extern sort_function1	SortFunction1[];
extern sort_function2	SortFunction2[];

/* ソート実行マクロ */
#define BubbleSort(array, len)			(SortFunction1[BUBBLE] (array, len))
#define	SelectionSort(array, len)		(SortFunction1[SELECTION] (array, len))
#define	QuickSort(array, left, right)	(SortFunction2[QUICK] (array, left, right))

/* 外部関数宣言 */
extern void bubble_sort(int *num_array, int array_len);
extern void selection_sort(int *num_array, int array_len);
extern void quick_sort(int *num_array, int left_idx, int right_idx);
extern void show_array(int *num_array, int array_len);


#endif	/* SORT_H */
