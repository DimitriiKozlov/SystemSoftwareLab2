//
// Created by dimirtii on 11.11.15.
//

#include <vector>
#include "allocator.h"


using namespace std;


const int pageSize = 32;

const int totalPage = 8;

const int totalMemory = totalPage * pageSize;


//int *memory = new int[totalMemory];
vector<int> memory = vector<int>((unsigned long) totalMemory, 0);
void *memAddress = &memory;

vector<lowPage> lowMemory = vector<lowPage>(0);


void mem_dump() {
    cout << "Memory status:" << endl;
    for (size_t i = 0; i < totalMemory; i++) {
        for (size_t j = 0; j < pageSize; j++, i++) {
            for (size_t k = 0; k < 4; k++)
                cout << memory[i];
            cout << " ";
        }
        cout << endl;
        i--;
    }
    cout << endl;
}

void *mem_allocByte(size_t size) {
    size_t i = 0;
    size_t freeSize = 0;

    size = (size % 4)? size + 4 - size % 4 : size;

    while (i < totalMemory) {
        if (!memory[i])
            freeSize++;
        else
            freeSize = 0;

        if (freeSize >= size) {
            size_t j;
            for (j = i - freeSize + 1; j < i + 1; j++)
                memory[j] = 1;
            memory[j - 1] = 5;
            return getAddressOfMemory(i - freeSize + 1);
        }
        i++;
    }
    return NULL;
}

size_t getIndexOfMemory(void *addr) {
    return ((size_t) (addr) - (size_t) (memAddress)) / sizeof(u_short);
}

void *getAddressOfMemory(size_t index) {
    return (memAddress + index * sizeof(u_short));
}

void mem_allocByAddress(void *addr, size_t size) {
    size_t i = getIndexOfMemory(addr);
    for (size_t j = 0; j < size - 1; j++)
        memory[i + j] = 1;
    memory[i + size - 1] = 5;
}


void *mem_alloc(size_t size){
    size = (size % 4) ? size + 4 - size % 4 : size;
    if (size > pageSize / 2)
        return mem_allocByte((size % pageSize)? size + pageSize - size % pageSize : size);

    for (int i = 0; i < lowMemory.size(); i++)
        if (lowMemory[i].size >= size)
            mem_allocByAddress(lowMemory[i].address, lowMemory[i].size);


}
