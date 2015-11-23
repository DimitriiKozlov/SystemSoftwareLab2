#include <iostream>
#include "allocator.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    mem_dump();
    mem_alloc(10);
    mem_dump();
    return 0;
}