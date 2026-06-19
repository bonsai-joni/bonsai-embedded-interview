#include <stdint.h>   // uint8_t
#include <stddef.h>   // size_t
#include <pthread.h>  // pthread_mutex_t, pthread_mutex_lock/unlock

#define MAX_ELEMENTS 1000U

typedef struct {
    uint8_t elements[MAX];
    size_t front, back, space_used;
    pthread_mutex_t mutex;
} rb_t;

int rb_enqueue(rb_t *rb, uint8_t val) {
    pthread_mutex_lock(&rb->mutex);
    if (rb->space_used >= MAX) return 1;        /* (a) */
    rb->elements[rb->back] = val;
    rb->back = (rb->back + 1) % MAX;
    rb->space_used++;
    pthread_mutex_unlock(&rb->mutex);
    return 0;
}

int rb_dequeue(rb_t *rb, uint8_t *val) {
    pthread_mutex_lock(&rb->mutex);
    if (rb->space_used == 0) return 1;          /* (b) */
    *val = rb->elements[rb->front];
    rb->front = (rb->front + 1) % MAX;
    rb->space_used--;
    pthread_mutex_unlock(&rb->mutex);
    return 0;
}
