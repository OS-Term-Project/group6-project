#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>

// Definitions for reading address.txt, finding page number, and finding offset

/** 
 
 * read_address() - Reads logical address from address.txt and returns pointer to address


 * find_page() - extracts page number from logical address and returns page number



 * find_offset() - extracts offset from logical address and returns offset

*/

// Completed by Lillie Hunter


int* read_address(char* filename){
    FILE * file = NULL;
    int addresses[1000];

    file = fopen(filename, "r");

    for (int line = 0; line < 1000; line++){
      	fscanf(file, "%d", &(addresses[line]));
        // printf("%d\n",addresses[line]);
    }
  
  	fclose(file);
  
  	return addresses;

}
int * find_page(int* address){
    int pageNumber;

    // casts pointer to an integer
    uintptr_t add = (uintptr_t)address;

    pageNumber = (add >> 8) & 0x00FF;

    return pageNumber;
    
}

int * find_offset(int* address){

    int offset;

    uintptr_t add = (uintptr_t)address;

    offset = (logical_addresses & 0x00FF);
 
    return offset
}



