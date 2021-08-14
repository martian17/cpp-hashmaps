#include <stdio.h>
#include <string>
#define IDLEN 5
//#define INITIAL_SIZE 20
//#define (uint8_t*) (uint8_t*)


//utility function
bool bytes_equal(uint8_t* str1, uint8_t* str2, int len){
    for(int i = 0; i < len; i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}

struct hashmap_content{
    int n;
};

struct hashmap_node{
    uint8_t id[IDLEN];
    hashmap_node* next;//initialize to null
    hashmap_content* content;//could allocate it directly inside, but pointer for now
};

//hashmap will be a wrapper clcass for sized_hashmap
class sized_hashmap{
    public:
    size_t size;
    
    //methods
    sized_hashmap(size_t length);
    hashmap_content* insert(uint8_t* id, hashmap_content* content);
    hashmap_content* remove(uint8_t* id);
    hashmap_content* get(uint8_t* id);
    
    private:
    size_t generate_hash(uint8_t* id);
    size_t arrlen;
    hashmap_node** arr;
    size_t FNV_PRIME = 16777619;
    size_t FNV_OFFSET = 2166136261;
};

size_t sized_hashmap::generate_hash(uint8_t* id){
    size_t hash = FNV_OFFSET;
    for(int i = 0; i < IDLEN; i++){
        hash ^= (size_t)id[i];
        hash *= FNV_PRIME;
    }
    //fprintf(stderr,"id: %s hashbefore: %zu arrlen: %zu hash: %zu\n",id,hash,arrlen,hash%arrlen);
    return hash%arrlen;
}

sized_hashmap::sized_hashmap(size_t length){
    //initialize all the variables
    arrlen = length;
    arr = new hashmap_node*[arrlen];
    size = 0;
}


hashmap_content* sized_hashmap::insert(uint8_t* id, hashmap_content* content){
    //looking for a match inside the linked list
    size_t hash = generate_hash(id);
    fprintf(stderr,"inserting %s\n",id);
    fprintf(stderr,"generated hash: %zu\n",hash);
    hashmap_node* node = arr[hash];
    hashmap_node** node_ptr = &arr[hash];
    while(node != NULL){
        fprintf(stderr,"hash collision: %s and %s\n",node->id,id);
        fprintf(stderr,"traversing the linked list bucket to find the spot\n");
        if(bytes_equal(node->id, id, IDLEN)){
            //found a match name
            hashmap_content* old_content = node->content;
            node->content = content;
            return old_content;
        }
        node_ptr = &(node->next);
        node = node->next;
    }
    //no matching node, creating a new one
    //now node should be null
    //fprintf(stderr,"!!new node!!\n");
    hashmap_node* new_node = new hashmap_node;
    for(int i = 0; i < IDLEN; i++){
        new_node->id[i] = id[i];
    }
    new_node->next = NULL;
    new_node->content = content;
    *node_ptr = new_node;
    return NULL;
}

hashmap_content* sized_hashmap::remove(uint8_t* id){
    size_t hash = generate_hash(id);
    hashmap_node* node = arr[hash];
    hashmap_node** node_ptr = &arr[hash];
    while(node != NULL){
        if(bytes_equal(node->id, id, IDLEN)){
            //found the match
            //removing
            *node_ptr = node->next;
            hashmap_content* content = node->content;
            delete node;
            return content;//returns the deleted content
        }
        node_ptr = &(node->next);
        node = node->next;
    }
    return NULL;//nothing deleted
}

hashmap_content* sized_hashmap::get(uint8_t* id){
    fprintf(stderr,"getting the content associated with the id: %s\n",id);
    size_t hash = generate_hash(id);
    fprintf(stderr,"whose hashed value is: %zu\n",hash);
    hashmap_node* node = arr[hash];
    while(node != NULL){
        fprintf(stderr,"looking inside the linked list bucket. current id: %s, object id: %s\n",node->id,id);
        if(bytes_equal(node->id, id, IDLEN)){
            fprintf(stderr,"found the linked list node with matching id. returning.\n");
            return node->content;
        }
        node = node->next;
    }
    return NULL;//nothing found
}




int main(){
    sized_hashmap table(10);
    
    hashmap_content dog;
    dog.n = 123;
    table.insert((uint8_t*)"dog\0",&dog);
    
    hashmap_content cat;
    cat.n = 234;
    table.insert((uint8_t*)"cat\0",&cat);
    
    hashmap_content fish;
    fish.n = 345;
    table.insert((uint8_t*)"fish",&fish);
    
    
    hashmap_content default1;
    default1.n = 999;
    table.insert((uint8_t*)"dhxh",&default1);
    table.insert((uint8_t*)"8ahw",&default1);
    table.insert((uint8_t*)"akxh",&default1);
    table.insert((uint8_t*)"ocpa",&default1);
    table.insert((uint8_t*)"9djv",&default1);
    table.insert((uint8_t*)"sjxk",&default1);
    table.insert((uint8_t*)"ndxk",&default1);
    table.insert((uint8_t*)"oakx",&default1);
    table.insert((uint8_t*)"mxks",&default1);
    table.insert((uint8_t*)"osax",&default1);
    table.insert((uint8_t*)"qxlc",&default1);
    table.insert((uint8_t*)"ttxb",&default1);
    table.insert((uint8_t*)"kkld",&default1);
    fprintf(stderr,"\n");
    
    hashmap_content* result = table.get((uint8_t*)"akxh");
    fprintf(stderr,"akxh's content is: %d\n",result->n);
}

