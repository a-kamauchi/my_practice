/*------------------------------------------------------------
 * data.h
 * 
 *------------------------------------------------------------
 */
#ifndef	DATA_H
#define	DATA_H

typedef enum
{
	STACK = 0,
	QUEUE
} DataStructure;

typedef void (*init_function) (int num_data);
typedef void (*write_function) (int *data);
typedef void (*read_function) (int *data);
typedef void (*destroy_function) (void);


/* API */
extern void InitDataStructure(DataStructure ds, int data_size);
extern void write(int *data);
extern void read(int *data);
extern void destroy(void);

/* スタックの外部関数 */
extern void initStack(int num_data);
extern void destroyStack(void);
extern void push(int *data);
extern void pop(int *data);

/* キューの外部関数宣言 */
extern void initQueue(int num_data);
extern void destroyQueue(void);
extern void enqueue(int *data);
extern void dequeue(int *data);

#endif	/* DATA_H */
