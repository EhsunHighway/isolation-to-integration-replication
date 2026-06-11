#include "realloc_failure.h"
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

// Global variables
int use_test_realloc = 0;
int realloc_fail_threshold = 0;
int realloc_call_count = 0;

// Pointer to the real realloc function
static void* (*real_realloc)(void*, size_t) = NULL;

// Custom realloc function
void* realloc(void* ptr, size_t size) {
    if (!real_realloc) {
        // Initialize real_realloc using dlsym if it hasn't been done yet
        real_realloc = (void* (*)(void*, size_t))dlsym(RTLD_NEXT, "realloc");
        if (!real_realloc) {
            // Handle the error if dlsym fails
            fprintf(stderr, "Error: unable to find real realloc function\n");
            exit(1);
        }
    }

    if (use_test_realloc) {
        realloc_call_count++;
        if (realloc_call_count >= realloc_fail_threshold) {
            // Simulate realloc failure
            printf("Simulating realloc failure on call #%d\n", realloc_call_count);
            return NULL;
        }
    }

    // Call the real realloc function
    return real_realloc(ptr, size);
}

// Function to enable/disable the custom realloc behavior
void enable_test_realloc(int enable, int threshold) {
    use_test_realloc = enable;
    realloc_fail_threshold = threshold;
    realloc_call_count = 0; // Reset call count each time we enable/disable
}
