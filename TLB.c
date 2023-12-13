#include <stdio.h>
#include "PhysicalStorage.c"
#include "PageTable.c"

#define entries 16
#define frameSize 256


// Completed by Lillie Hunter

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

// Define Table
void* initialize_TLB(){
    TLBtable.table = (TLB_struct*)malloc(sizeof(TLB_struct)*frameSize);
    TLBtable.length = entries;

    for (int entry = 0; entry < TLBtable.length; entry++){
        TLBtable.table[entry].valid = 0;
    }

    TLBtable.nextUpdateIndex = 0;
    
}

// Verifies if page number is in TLB

int check_TLB(int* page){

    for(int index = 0; index < TLBtable.length; index++){
        if (TLBtable.table[index].page == page && TLBtable.table[index].valid == 1){
            return TLBtable.table[index].frame; // Returns frame (TLB Hit)
        }
        
        
    }

    return -1; // TLB Miss
}

void update_TLB(unsigned char page, unsigned char frame){
    TLBtable.table[TLBtable.nextUpdateIndex].page = page;
    TLBtable.table[TLBtable.nextUpdateIndex].frame = frame;
    TLBtable.table[TLBtable.nextUpdateIndex].valid = 1;
    

    TLBtable.nextUpdateIndex = (TLBtable.nextUpdateIndex + 1) % TLBtable.length;

    

}
