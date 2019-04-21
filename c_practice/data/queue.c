#include <stdio.h>
#include <stdlib.h>


/* キュー構造 */
typedef struct
{
	int	*data_array;
	int	 num_data;
	int	 first_index;
	int	 last_index;
} QueueData;

static QueueData	*queue;


/*
 * 初期化
 */
void
initQueue(int num_data)
{
	if (queue != NULL)
	{
		/* 初期化済み */
		return;
	}

	queue = (QueueData *) malloc(sizeof(QueueData));
	queue->data_array = (int *) malloc(sizeof(int) * num_data);
	queue->num_data = num_data;
	queue->first_index = 0;
	queue->last_index = 0;
}

/*
 * 後始末
 */
void
destroyQueue(void)
{
	if (queue->data_array != NULL)
	{
		free(queue->data_array);
		queue->data_array = NULL;
	}
	if (queue != NULL)
	{
		free(queue);
		queue = NULL;
	}
}

/*
 * キューへのデータ格納
 */
void
enqueue(int *data)
{
	/* キューが満杯（lastの次がfirst）だったらデータを格納しない */
	if ((queue->last_index + 1) % queue->num_data == queue->first_index)
	{
		printf("this queue has been full of data\n");
		return;
	}

	/*データ格納 */
	queue->data_array[queue->last_index] = *data;

	/* 最末位置を１つ後ろにずらす.既に最末の場合は、再び先頭を指す */
	queue->last_index = (queue->last_index + 1) % queue->num_data;
}

/*
 * キューからのデータ取り出し
 */
void
dequeue(int *data)
{
	/* キューは空の状態 */
	if (queue->first_index == queue->last_index)
	{
		printf("this queue is empty\n");
		return;
	}

	/* 先頭のデータを返す */
	*data = queue->data_array[queue->first_index];

	/* 先頭位置を１つ後ろにずらす */
	queue->first_index = (queue->first_index + 1) % queue->num_data;
}

