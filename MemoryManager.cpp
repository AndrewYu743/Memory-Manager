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
    if (charMap !=0 ){
      free(charMap);
      wordVector.clear();
    }

    charMap = (char*) malloc( sizeInWords *  wordSize );
     wordVector[sizeInWords]={0};
    holes = 1;

}
void * MemoryManager::allocate(size_t sizeInBytes){
   int number =  allocator(sizeInBytes, getList());
   delete [] arr;

   if(number = -1) {
       return nullptr;
   }


       findHoles();
   return ;

}
void MemoryManager::free(void *address){

}
void MemoryManager::setAllocator(std::function<int(int, void *)> allocator){
allocator = this->allocator;

}
int MemoryManager::dumpMemoryMap(char *filename){
    ofstream myFile;
    myFile.open (filename);
//add things
    myFile.close();

}
void * MemoryManager::getList(){

    arr = new int[(holes * 2) + 1]();
    findHoles();
    arr[0] = holes;
    for(int x = 1; x < holeVector.size(); x +=2 ){
        arr[x] = holeVector[x-1];
        arr[x+1] = holeVector[x];


    }

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
void MemoryManager::findHoles(){
    int x = 1;
    int tempholes = 0;
    int offset = 0;
    int collecting = 0;

    for(int c = 0; c < wordVector.size(); c++){
        if(wordVector[c] == 0){
            if(collecting ==0){
                offset = c;
            }
            collecting = 1;
            continue;
        }
        else if(wordVector[c] == 1 && collecting == 0){
            continue;
        }
        else{
            //wordVector[c] == 1 && collecting != 0
            holeVector.push_back(offset);
            holeVector.push_back(c - offset);
            holes = 0;
            collecting = 0;
        }

    }

}