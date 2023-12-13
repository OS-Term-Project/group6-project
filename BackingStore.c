#include "TLB.c"
#include "PageTable.c"
#include "PhysicalStorage.c"

#include <stdio.h>

#define PAGE_SIZE 256
#define NUM_FRAMES 256

// TLB
int tlb[16][2]; // Assuming a 16-entry TLB

// Page table
int page_table[256];

int main() {
    // Create a backing store file
    FILE *backing_store = fopen("BACKING_STORE.bin", "wb");
    // Write the page data to the backing store
    // For this specific task, writing the page data to the backing store is not required as the focus is on reading from the backing store.
    fclose(backing_store);

    // Load page 251 into Frame 0
    backing_store = fopen("BACKING_STORE.bin", "rb");
    fseek(backing_store, 251 * PAGE_SIZE, SEEK_SET);
    char frame[PAGE_SIZE];
    fread(frame, sizeof(char), PAGE_SIZE, backing_store);
    fclose(backing_store);

    // Update the TLB and page table
    tlb[0][0] = 251; // Page number
    tlb[0][1] = 0;   // Frame number
    page_table[251] = 0; // Update the page table with the frame number

    // Fill the frame from 0 to 255
    for (int i = 0; i < PAGE_SIZE; i++) {
        printf("%d ", frame[i]); // Output the contents of the frame
    }

    return 0;
}