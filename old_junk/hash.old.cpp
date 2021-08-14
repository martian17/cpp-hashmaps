#include <stdio.h>
#include <string>
#define HASHMAP_IDXLEN 20


class hashmap{
    public:
    int arrlen;
    int* arr;
    int size;
    int FNV_PRIME = 16777619;
    int FNV_OFFSET = 2166136261;
    
    void hashmap();
    void insert(hahsmap_content content);
    void delete(char* idx[20]);
    
    private:
    int hash_f(char* idx[HASHMAP_IDXLEN]);
};

int hashmap::hash_f(char* idx[HASHMAP_IDXLEN]){//fnv1a
    int hash = FNV_OFFSET;
    for(int i = 0; i < HASHMAP_IDXLEN; i++){
        hash ^= (int)idx[i];
        hash *= FNV_PRIME
    }
    return hash;
}

struct hahsmap_content{
    char* idx[HASHMAP_IDXLEN];//max idx length: 20
    //didn't use std:string because I wanted everything to be on the heap
    std::string content;
}

void hashmap::hashmap(){
    //initialization
    arrlen = 10;
    arr = (int*)malloc(sizeof(int)*arrlen);
    size = 0;
}

void hashmap::insert(hahsmap_content content){
    hashmap.hash_f(content.idx);
}
