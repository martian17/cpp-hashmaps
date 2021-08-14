#include <stdio.h>
#include <string>
#define IDLEN 20
#define INITIAL_SIZE 20


struct hashmap_content{
    std::string str;
};

struct hashmap_node{
    char id[IDLEN];
    hashmap_node* next;//initialize to null
    hashmap_content* content;//could allocate it directly inside, but pointer for now
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
    int generate_hash(char* idx[HASHMAP_IDXLEN]);
    void hashmap_resize(int new_arrlen);
    void insert_routine(hashmap_node* node, hashmap_node** some_arr);
};

int generate_hash(char* idx, int len){
    int hash = FNV_OFFSET;
    for(int i = 0; i < IDLEN; i++){
        hash ^= (int)id[i];
        hash *= FNV_PRIME;
    }
    return hash%len;
}

void hashmap::hashmap(){
    //initialize all the variables
    arrlen = INITIAL_SIZE;
    arr = malloc(sizeof(hashmap_node*)*arrlen);
    size = 0;
}

void hashmap::insert_routine(hashmap_node* node, hashmap_node** some_arr){
    int hash = generate_hash(node->id);
    hashmap_node** node_ptr = &some_arr[hash];
    while(*node_ptr != NULL){
        node_ptr = &(*node_ptr->next);
    }
    *node_ptr = node;
    node->next = NULL;
}

coid hashmap::hashmap_resize(int new_arrlen){
    new_arr = malloc(sizeof(hashmap_node*)*new_arrlen);
    for(int i = 0; i < arrlen; i++){
        hashmap_node* node = arr[i];
        while(node != NULL){
            insert_routine(,new_arr);
            node = node->next;
        }
    }
}

void hashmap::insert(){
    
}

void hashmap::hashmap(){
    
}

void hashmap::hashmap(){
    
}

void hashmap::hashmap(){
    
}

void hashmap::hashmap(){
    
}








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


