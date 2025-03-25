#ifndef FIFO_FIFO_H_
#define FIFO_FIFO_H_

#include <stdint.h>
#include <stdlib.h>

#define Frame_SIZE 10 //Size of each frame
#define num_frames 10  // Define FIFO buffer size
#define FIFO_SIZE (num_frames * Frame_SIZE)

typedef struct {
	uint16_t FIFO_Buffer[FIFO_SIZE];
	uint16_t head;   // Next write index
	uint16_t tail;   // Next read index
	uint16_t count;  // Number of elements in FIFO
} fifo_T;

void fifo_init(fifo_T *f);

int fifo_is_empty(const fifo_T *f);

void fifo_enqueue(fifo_T *f, uint8_t data);

int fifo_dequeue(fifo_T *f, uint8_t *data);

#endif /* FIFO_FIFO_H_ */
