/*------------------------------------------------------------
 * data.h
 * 
 *------------------------------------------------------------
 */
#ifndef	DATA_H
#define	DATA_H

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
