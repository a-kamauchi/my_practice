#include <stdio.h>
#include <stdlib.h>

#include "data.h"

/*
 * データ構造の初期化関数（init_function）、データ入力関数（write_function）
 * データ取得関数（read_function）、後始末関数（destroy_function）
 */
static init_function		InitFunctions[] = {initStack, initQueue};
static write_function		WriteFunctions[] = {push, enqueue};
static read_function		ReadFunctions[] = {pop, dequeue};
static destroy_function		DestroyFunction[] = {destroyStack, destroyQueue};

typedef struct
{
	DataStructure		data_struct;
	init_function		init;
	write_function		write;
	read_function		read;
	destroy_function	destroy;
} DataStructInfo;

static DataStructInfo	*data_struct_info;

/*
 * 初期化API
 */
void
InitDataStructure(DataStructure	ds, int data_size)
{
	/* 既に初期化済み */
	if (data_struct_info != NULL)
		return;

	data_struct_info = (DataStructInfo *) malloc(sizeof(DataStructInfo));
	data_struct_info->data_struct = ds;
	data_struct_info->init = (init_function) InitFunctions[ds];
	data_struct_info->write = (write_function) WriteFunctions[ds];
	data_struct_info->read = (read_function) ReadFunctions[ds];
	data_struct_info->destroy = (destroy_function) DestroyFunction[ds];

	/* データ構造初期化関数の呼び出し */
	data_struct_info->init(data_size);
}

/*
 * データ格納API
 */
void
write(int *data)
{
	data_struct_info->write(data);
}

/*
 * データ取得API
 */
void
read(int *data)
{
	data_struct_info->read(data);
}

/*
 * 後始末API
 */
void
destroy(void)
{
	data_struct_info->destroy();

	if (data_struct_info != NULL)
	{
		free(data_struct_info);
		data_struct_info = NULL;
	}
}

/*
 * エントリーポイント
 */
int
main(int argc, char *argv[])
{
	int	num_data = 4;
	int	data;
	int	i;

	InitDataStructure(STACK, num_data);

	data = 1;
	write(&data);
	data = 3;
	write(&data);
	data = 5;
	write(&data);

	for (i = 0; i < num_data; i++)
	{
		read(&data);
		printf("%d\n", data);
	}

	return 0;
}
