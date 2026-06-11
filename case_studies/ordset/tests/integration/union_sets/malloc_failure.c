#include "malloc_failure.h"
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

// Global variables
int use_test_malloc = 0;
int malloc_fail_threshold = 0;
int malloc_call_count = 0;

// Pointer to the real malloc function
static void* (*real_malloc)(size_t) = NULL;

// Custom malloc function
void* malloc(size_t size) {
    if (!real_malloc) {
        // Initialize real_malloc using dlsym if it hasn't been done yet
        real_malloc = (void* (*)(size_t))dlsym(RTLD_NEXT, "malloc");
        if (!real_malloc) {
            // Handle the error if dlsym fails
            fprintf(stderr, "Error: unable to find real malloc function\n");
            exit(1);
        }
    }

    if (use_test_malloc) {
        malloc_call_count++;
        if (malloc_call_count >= malloc_fail_threshold) {
            // Simulate malloc failure
            printf("Simulating malloc failure on call #%d\n", malloc_call_count);
            return NULL;
        }
    }

    // Call the real malloc function
    return real_malloc(size);
}

// Function to enable/disable the custom malloc behavior
void enable_test_malloc(int enable, int threshold) {
    use_test_malloc = enable;
    malloc_fail_threshold = threshold;
    malloc_call_count = 0; // Reset call count each time we enable/disable
}
