//
// Created by andre on 10/20/2022.
//

#ifndef PROJECT2OS_MEMORYMANAGER_H
#define PROJECT2OS_MEMORYMANAGER_H

#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
int bestFit(int sizeInWords, void *list){

    uint16_t* holeList = static_cast<uint16_t*>(list);
    uint16_t holeListlength = *holeList++;
    uint16_t min = 999999;
    for(uint16_t i = 1; i < (holeListlength) * 2; i += 2){
        uint16_t j = i + 1;
        if(holeList[j] < min){
            min = holeList[j];
        }


    }
if(min == 99999){
    return -1;
}
return holeList[min-1];


}
int worstFit(int sizeInWords, void *list){

    uint16_t* holeList = static_cast<uint16_t*>(list);
    uint16_t holeListLength = *holeList++;
    uint16_t min = -1;
    for(uint16_t i = 1; i < (holeListLength) * 2; i += 2){
        uint16_t j = i + 1;
        if(holeList[j] > min){
            min = holeList[j];
        }

    }
    if(min == -1){
        return -1;
    }
    return holeList[min-1];



}


class MemoryManager {
private:
    unsigned int wordSize;
    function<int(int, void *)> allocator;
    vector<int> lists;
    char *charMap;
    int holes;
    int * arr;
public:
    struct Hole{
        size_t length;
        size_t position;
        struct Hole *next;

    };
MemoryManager(unsigned int wordSize, std::function<int(int, void *)> allocator);
void shutdown();
void initialize(size_t sizeInWords);

void *allocate(size_t sizeInBytes);
void free(void *address);
void setAllocator(std::function<int(int, void *)> allocator);
int dumpMemoryMap(char *filename);
void * getList();
void *getBitmap();
unsigned int getWordSize();
void *getMemoryStart();
unsigned getMemoryLimit();

~MemoryManager();

};


#endif //PROJECT2OS_MEMORYMANAGER_H
