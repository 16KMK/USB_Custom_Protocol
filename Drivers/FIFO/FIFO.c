#include "FIFO.h"
// Initialize the FIFO
void fifo_init(fifo_T *f) {
	f->head = f->UserHead = 0;
	f->tail = f->UserTail = 0;
	f->count = 0;
	f->Fifo_Size = 10;
	f->no_of_Cycles = 0;
}

// Check if the FIFO is empty
int8_t fifo_is_empty(const fifo_T *f) {
	return (f->count == 0);
}
// Enqueue data into the FIFO (overwrite oldest data if full)
int16_t fifo_enqueue(fifo_T *f) {
	f->UserHead = f->head;
	f->head = (f->head + 1) % f->Fifo_Size; // Circular wrap-around

	if (f->count == f->Fifo_Size) {
		// FIFO is full → Overwrite → Move tail forward
		f->tail = (f->tail + 1) % f->Fifo_Size;
		f->no_of_Cycles++;
	} else {
		f->count++;
	}
	return f->UserHead;
}

// Dequeue data from the FIFO
// Returns 0 on success, -1 if FIFO is empty
int16_t fifo_dequeue(fifo_T *f) {
	if (fifo_is_empty(f)) {
		printf("FIFO is empty\n");
		return -1;
	}
	f->UserTail = f->tail;
	f->tail = (f->tail + 1) % f->Fifo_Size; // Circular wrap-around
	f->count--;
	return f->UserTail;
}
