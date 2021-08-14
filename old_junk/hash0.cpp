#include <stdio.h>
#include <string>
#define IDLEN 20
#define INITIAL_SIZE 20

//will be user defined
struct hahsmap_content{
    std::string str;
};

struct hahsmap_ll{
    char* id[IDLEN];
    hahsmap_ll* next=NULL;
    hahsmap_content* content;
};

class hashmap{
    int arrlen=INITIAL_SIZE;
    hahsmap_ll* arr;
    int size;
    int FNV_PRIME = 16777619;
    int FNV_OFFSET = 2166136261;
    
    //methods
    void hashmap();
    void insert(char* idx, hahsmap_content content);
    void delete(char* idx);
    
    private:
    int hash_f(char* idx[HASHMAP_IDXLEN]);
    int hash_realloc(int arrlen1);
};

hashmap::hash_realloc(int arrlen1){
    hahsmap_ll** arr1=(hahsmap_ll**)malloc(arrlen1*sizeof(hahsmap_ll*));
    for(int i = 0; i < arrlen; i++){
        hahsmap_ll llitem = arr[i];
        while(llitem){
            int idx1 = hash_f(llitem.id,arrlen);
            llitem = llitem.next;
        }
    }
    arrlen = arrlen1;
    
    
    free(arr);//freeing the older shorter version
    
}


hashmap::hashmap(){
    arr=(hahsmap_ll**)malloc(INITIAL_SIZE*sizeof(hahsmap_ll*));
    hashmap::hash_realloc();
}

void hashmap::insert(){
    if(arrlen < size){//double the size
        int arrlen1 = arrlen*2;
        hashmap::hash_realloc();
    }
    arr=(hahsmap_ll*)malloc(INITIAL_SIZE);
}

