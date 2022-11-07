//
// Created by andre on 10/20/2022.
//

#include "MemoryManager.h"
MemoryManager::MemoryManager(unsigned int wordSize, std::function<int(int, void *)> allocator){
    wordSize = this->wordSize;
     allocator = this->allocator;
}
void MemoryManager::shutdown(){}
void MemoryManager::initialize(size_t sizeInWords){
    charMap = (char*) calloc( sizeInWords, wordSize );
    holes = 1;
    lists.push_back(holes);
}
void * MemoryManager::allocate(size_t sizeInBytes){
   int number =  allocator(sizeInBytes, getList());
   delete [] arr;

   if(number = -1) {
       return nullptr;
   }

}
void MemoryManager::free(void *address){}
void MemoryManager::setAllocator(std::function<int(int, void *)> allocator){
allocator = this->allocator;

}
int MemoryManager::dumpMemoryMap(char *filename){}
void * MemoryManager::getList(){

    arr = new int[(holes * 2) + 1]();
    arr[0] = holes;

    return arr;
}
void * MemoryManager::getBitmap(){

}
unsigned int MemoryManager::getWordSize(){
    return wordSize;
}
void * MemoryManager::getMemoryStart(){
    return charMap;
}
unsigned MemoryManager::getMemoryLimit(){}
MemoryManager::~MemoryManager(){
    free(charMap);
    holes = 0;
}
