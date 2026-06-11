// ord_set.h
#ifndef ORD_SET_H
#define ORD_SET_H

#include <sys/types.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MIN_SET_SIZE 4
#define MAX_SET_SIZE 16
#define MAX_ACCEPTED_RESIZES 2

typedef struct {
    int _set_size;
    int *_set_elements;
    int _last;
    int _resized_times;
    bool _overflow;
} ord_set;

#endif 