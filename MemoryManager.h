//
// Created by andre on 10/20/2022.
//

#ifndef PROJECT2OS_MEMORYMANAGER_H
#define PROJECT2OS_MEMORYMANAGER_H

#include <functional>

using namespace std;
class MemoryManager {
private:
    unsigned int wordSize;

public:
MemoryManager(unsigned int wordSize, std::function<int(int, void *)> allocator);
void shutdown();
void initialize(size_t sizeInWords);
void *allocate(size_t sizeInBytes);
void free(void *address);
void setAllocator(std::function<int(int, void *)> allocator);
int dumpMemoryMap(char *filename);
void *getList();
void *getBitmap();
unsigned getWordSize();
void *getMemoryStart();
unsigned getMemoryLimit();

~MemoryManager();

};


#endif //PROJECT2OS_MEMORYMANAGER_H
