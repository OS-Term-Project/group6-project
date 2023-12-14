#define physicalMemory frames*sizeof(frames)
#include <stdio.h>
#include <stdlib.h>
#include "PageTable.c"

#define entries 16
#define frameSize 256

// Structures
typedef struct {
    unsigned char page;
    unsigned char frame;
    unsigned char valid;
} TLB_struct;

typedef struct {
    TLB_struct* table;
    int length;
    int nextUpdateIndex;
} TLB;

// Variables
TLB TLBtable;

// Memory management code (from the previous response)

// Function to access a specific memory location within a frame using TLB
char accessMemoryInFrame(int pageNumber, int offset) {
    // Perform a TLB lookup
    int frameNumber = check_TLB(&pageNumber);

    if (frameNumber == -1) {
        // TLB miss, load the page into memory and update TLB
        frameNumber = pageNumber % NUM_FRAMES; // For simplicity, use the page number as frame number
        loadPageIntoFrame(pageNumber, frameNumber);
        update_TLB(pageNumber, frameNumber);
    }

    // Return the value at the specified location in the given physical memory frame
    return physicalMemory[frameNumber][offset];
}

// Rest of the memory management code remains the same

// Main function
int main() {
    // Example: Accessing memory within Frame 0 at offset 25 using TLB
    int pageNumber = 251;
    int offset = 25;
    char value#include <stdio.h>
#include <stdlib.h>

#define NUM_FRAMES 256
#define PAGE_SIZE 256
#define TLB_SIZE 16

// Simulated physical memory
char physicalMemory[NUM_FRAMES][PAGE_SIZE];

// Simulated backing store
char backingStore[NUM_FRAMES][PAGE_SIZE];

// Struct to represent a Page Table Entry (PTE)
typedef struct {
    int pageNumber;
    int frameNumber;
} PageTableEntry;

// Simulated TLB
PageTableEntry tlb[TLB_SIZE];
int tlbIndex = 0;

// Function to perform a TLB lookup
int tlbLookup(int pageNumber) {
    for (int i = 0; i < TLB_SIZE; ++i) {
        if (tlb[i].pageNumber == pageNumber) {
            return tlb[i].frameNumber; // TLB hit
        }
    }
    return -1; // TLB miss
}

// Function to update the TLB
void updateTLB(int pageNumber, int frameNumber) {
    tlb[tlbIndex].pageNumber = pageNumber;
    tlb[tlbIndex].frameNumber = frameNumber;
    tlbIndex = (tlbIndex + 1) % TLB_SIZE; // Update the index using modulo TLB_SIZE
}

// Function to load a page into a specific frame
void loadPageIntoFrame(int pageNumber, int frameNumber) {
    // Simulating loading the page from backing store to physical memory
    for (int i = 0; i < PAGE_SIZE; ++i) {
        physicalMemory[frameNumber][i] = backingStore[pageNumber][i];
    }

    // Update the TLB
    updateTLB(pageNumber, frameNumber);

    printf("Page %d loaded into Frame %d.\n", pageNumber, frameNumber);
}

// Function to access a specific memory location within a frame using TLB
char accessMemoryInFrame(int pageNumber, int offset) {
    // Perform a TLB lookup
    int frameNumber = tlbLookup(pageNumber);

    if (frameNumber == -1) {
        // TLB miss, load the page into memory and update TLB
        frameNumber = pageNumber % NUM_FRAMES; // For simplicity, use the page number as frame number
        loadPageIntoFrame(pageNumber, frameNumber);
    }

    // Return the value at the specified location in the given physical memory frame
    return physicalMemory[frameNumber][offset];
}

int main() {
    // Example: Accessing memory within Frame 0 at offset 25 using TLB
    int pageNumber = 251;
    int offset = 25;
    char value = accessMemoryInFrame(pageNumber, offset);
    printf("Value at physical address (Page %d, Offset %d): %c\n", pageNumber, offset, value);

    return 0;
}
 = accessMemoryInFrame(pageNumber, offset);
    printf("Value at physical address (Page %d, Offset %d): %c\n", pageNumber, offset, value);

    return 0;
}
