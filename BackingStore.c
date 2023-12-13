#include "TLB.c"
#include "PageTable.c"
#include "PhysicalStorage.c"

#include <stdio.h>

#define PAGE_SIZE 256
#define NUM_FRAMES 256
#define NUM_PAGES 256
#define TLB_SIZE 16

// TLB entry structure
typedef struct {
    int page_number;
    int frame_number;
} tlb_entry;

// page table
int page_table[NUM_PAGES];
// physical memory
char physical_memory[NUM_FRAMES][PAGE_SIZE];
// TLB
tlb_entry tlb[TLB_SIZE];

int next_available_frame = 0; // activatesthe next available frame

// function to handle page fault
void handle_page_fault(int page_number, FILE *backing_store) {
    // read the page from the backing store and store it in the next available frame
    fseek(backing_store, page_number * PAGE_SIZE, SEEK_SET);
    fread(physical_memory[next_available_frame], sizeof(char), PAGE_SIZE, backing_store);
    // update the page table with the new frame number
    page_table[page_number] = next_available_frame;
    // update the TLB
    tlb[next_available_frame % TLB_SIZE].page_number = page_number;
    tlb[next_available_frame % TLB_SIZE].frame_number = next_available_frame;
    // increment the next available frame
    next_available_frame++;
}

int main() {
    // open the backing store file
    FILE *backing_store = fopen("BACKING_STORE.bin", "rb");

    // handle page fault for page 251
    handle_page_fault(251, backing_store);

    // access the memory located at frame 0 and offset 25 
    printf("the value at physical address: %d\n", physical_memory[0][25]);

    // close the backing store file
    fclose(backing_store);

    return 0;
}