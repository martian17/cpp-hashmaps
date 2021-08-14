#include <stdio.h>
#include <string>
#define IDLEN 20
#define INITIAL_SIZE 20

//will be user defined
struct hahsmap_content{
    std::string str;
};

struct hahsmap_node{
    char* id[IDLEN];
    hahsmap_node* next=NULL;
    hahsmap_content* content;
};

class hashmap{
    int arrlen;
    hahsmap_node** arr;
    int size;
    int FNV_PRIME = 16777619;
    int FNV_OFFSET = 2166136261;
    
    //methods
    void hashmap();
    void insert(char* id, hahsmap_content content);
    void delete(char* id);
    
    private:
    int hash_id(char* idx[HASHMAP_IDXLEN]);
    int hash_realloc(int arrlen1);
};

void hashmap::hashmap(){//initialization
    arrlen = INITIAL_SIZE;
    arr = (hahsmap_node**)malloc(INITIAL_SIZE*sizeof(hahsmap_node*));
    size = 0;
    //initialize the array
    for(int i = 0; i < arrlen; i++){
        //initialize everything to NULL
        arr[i] = NULL;
    }
}

int hashmap::hash_id(char* id, int range){
    int hash = FNV_OFFSET;
    for(int i = 0; i < IDLEN; i++){
        hash ^= (int)id[i];
        hash *= FNV_PRIME;
    }
    return hash%range;
}

void hashmap::insert_kernel(char* id, hahsmap_node* node, hahsmap_node** arrn){
    int hash = hash_id(id,arrlen);
    //gotta know where the pointer is in order to replace it
    hahsmap_node** ptr = &arrn[hash];
    while(*ptr != NULL){//do it until it's a null popinter
        ptr = &(*ptr->next);
    }
    //replacing the null pointer with the new node
    *ptr = node;
    node->next = NULL;
}


void hashmap::hash_realloc(int arrlen1){
    hahsmap_node** arr1=(hahsmap_node**)malloc(arrlen1*sizeof(hahsmap_node*));
    for(int i = 0; i < arrlen; i++){
        hahsmap_node* node = arr[i];
        while(node != NULL){
            insert_kernel(node->id, node, arr);
            int idx1 = hash_f(llitem.id,arrlen);
            llitem = llitem.next;
        }
    }
    arrlen = arrlen1;
    
    free(arr);//freeing the older shorter version
    arr = arr1;
    arrlen = arrlen1;
}

void hashmap::insert(char* id, hashmap_content* content){
    if(arrlen < size){
        int arrlen1 = arrlen*2;
        hash_realloc(arrlen);
    }
    //generate a new node
    hahsmap_node* node = (hahsmap_node*)malloc(sizeof(hahsmap_node));
    
    insert_kernel(id, node, arr);
}


