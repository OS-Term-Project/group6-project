#include "PhysicalStorage.c"
#include "PageTable.c"

PageTableEntry pageTable[PAGE_TABLE_SIZE];
int currentPage = 0;

void initializePageTable() {
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        pageTable[i].isValid = 0;
    }
}

void addPageToTable(int pageNumber, int frameNumber) {
    pageTable[currentPage].pageNumber = pageNumber;
    pageTable[currentPage].frameNumber = frameNumber;
    pageTable[currentPage].isValid = 1;

    currentPage = (currentPage + 1) % PAGE_TABLE_SIZE;
}

int lookupPageInTable(int pageNumber) {
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        if (pageTable[i].isValid && pageTable[i].pageNumber == pageNumber) {
            return pageTable[i].frameNumber;
        }
    }
    return -1;
}
