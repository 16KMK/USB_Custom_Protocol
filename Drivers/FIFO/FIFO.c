#include "FIFO.h"

// Initialize the FIFO
void fifo_init(fifo_T *f) {
	f->head = 0;
	f->tail = 0;
	f->count = 0;
}

// Check if the FIFO is empty
int fifo_is_empty(const fifo_T *f) {
	return (f->count == 0);
}

// Enqueue data into the FIFO (overwrite oldest data if full)
void fifo_enqueue(fifo_T *f, uint8_t data) {
	f->FIFO_Buffer[f->head] = data;  // Store data
	f->head = (f->head + 1) % FIFO_SIZE;  // Circular wrap-around

	if (f->count == FIFO_SIZE) {
		// FIFO is full → Overwrite → Move tail forward
		f->tail = (f->tail + 1) % FIFO_SIZE;
	} else {
		f->count++;
	}
}

// Dequeue data from the FIFO
// Returns 0 on success, -1 if FIFO is empty
int fifo_dequeue(fifo_T *f, uint8_t *data) {
	if (fifo_is_empty(f)) {
		return -1;
	}
	*data = f->FIFO_Buffer[f->tail];  // Retrieve data
	f->tail = (f->tail + 1) % FIFO_SIZE;  // Circular wrap-around
	f->count--;
	return 0;
}
/*
 int main(void) {
 fifo_T fifo;
 fifo_init(&fifo);

 // Enqueue 10 elements (fills up FIFO with some data)

 for (uint8_t i = 1; i <= 100; i++) {
 fifo_enqueue(&fifo, i);
 }

 // Enqueue extra elements (oldest data will be overwritten if full)
 fifo_enqueue(&fifo, 110);
 fifo_enqueue(&fifo, 120);
 fifo_enqueue(&fifo, 130);

 printf("FIFO contents after overwriting:\n");
 uint8_t value;
 while (!fifo_is_empty(&fifo)) {
 fifo_dequeue(&fifo, &value);
 printf("Dequeued: %d\n", value);
 }

 return 0;
 }
 */
