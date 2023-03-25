//
// Created by Bryan Zhang on 3/23/23.
//
#include "relations.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "stdio.h"
struct Tuple{
    char** elements;
};

struct Node{
    Tuples element;
    Nodes* next;
};

struct HashTable{
    Nodes* array;
    int size;
};
struct Relation{
    int size;
    char** name;
    HashTables* hashTables;
    int tupleNum;
};

Tuples new_Tuple(){
    Tuples new = (Tuples) malloc(sizeof(struct Tuple));
    new->elements = NULL;
    return new;
}


void free_Tuple(Tuples x){
    free(x);
}

Nodes new_Node(int size){
    Nodes new = (Nodes) malloc(sizeof(struct Node));
    new->element = NULL;
    new->next = (Nodes*) calloc(size, sizeof(Nodes));
    return new;
}

void free_Nodes(Nodes x){
    free(x->next);
    free(x);
}

HashTables new_HashTable(int size){
    HashTables new = (HashTables) malloc(sizeof(struct HashTable));
    new->array = (Nodes*) calloc(size, sizeof(Nodes));
    new->size = size;
    return new;
}

void free_HashTables(HashTables x,int time){
    if(time == 0){
        // to ensure every Nodes are just free for just one times
        for(int i = 0; i < x->size; i++){
            Nodes curNode = x->array[i];
            while(curNode != NULL){
                Nodes tmp = curNode;
                curNode = tmp->next[time];
                free_Tuple(tmp->element);
                free_Nodes(tmp);
            }
        }
    }
    free(x->array);
    free(x);
}


int getNum(char* string){
    // the integer value of string is the sum of each char's ascii value
    int num = 0;
    for(int i = 0; i < strlen(string); i++){
        num += (int)(string[i]);
    }
    return num;
}

void set_Tuple(char* x[], Tuples t){
    t->elements = x;
}

// adding the node into hashtables
void add_Node(Nodes node, int pos, HashTables hashTables){
    int num = getNum(node->element->elements[pos]);
    num %= hashTables->size;
    if(hashTables->array[num] == NULL){
        hashTables->array[num] = node;
        return;
    }
    Nodes curNode = hashTables->array[num];
    while(curNode->next[pos] != NULL){
        curNode = curNode->next[pos];
    }
    curNode->next[pos] = node;
}

// generate a new relations
Relations new_Relation(int size, char* name[]){
    Relations new = (Relations) malloc((sizeof(struct Relation)));
    new->size = size;
    new->name = name;
    new->hashTables = (HashTables*) calloc(size, sizeof(HashTables));
    for(int i = 0; i < size; i ++){
        new->hashTables[i] = new_HashTable(99);
    }
    new->tupleNum = 0;
    return new;
}

// free the memories of relations
void free_Relations(Relations x){
    for(int i = 0; i < x->size; i++){
        free_HashTables(x->hashTables[i],i);
    }
    free(x->hashTables);
    free(x);
}

//adding funciton
void add(char* elements[], Relations relations){
    Nodes search = lookup(elements,relations);
    if( search == NULL){
        Tuples new = new_Tuple();
        set_Tuple(elements,new);
        Nodes node = new_Node(relations->size);
        node->element = new;
        for(int i = 0; i < relations->size; i++){
            add_Node(node,i,relations->hashTables[i]);
        }
        relations->tupleNum ++;
        return;
    }
    // free the memories of finding Nodes's memory
    else{
        while(search != NULL){
            Nodes curNode = search;
            search = curNode->next[0];
            free_Nodes(curNode);
        }
    }
}
// given two tuples check if they are the same in every index
bool isSameTuple(Tuples x, Tuples y, int size){
    for(int i = 0; i < size ; i++){
        char* strX = x->elements[i];
        char* strY = y->elements[i];
        if(strX != strY){ return false;}
    }
    return true;
}

// delete specific tuples given the elements in the relations
void delete(char* elements[], Relations relations){
    Nodes container = lookup(elements,relations);
    // using lookup function we get a list of tuples that fits our requirement, and delete them in teh fucntion
    if( container == NULL) return;
    while(container != NULL){
        Nodes curNode = container;
        Tuples curT = curNode->element;
        container = container->next[0];
        Nodes finding;
        for(int i = 0; i < relations->size; i++){
            HashTables tables = relations->hashTables[i];
            int pos = getNum(curT->elements[i]) % tables->size;
            Nodes arrayNode = tables->array[pos];
            if(isSameTuple(curT,arrayNode->element,relations->size)){
                tables->array[pos] = arrayNode->next[i];
                finding = arrayNode;
            }
            else{
                Nodes father = arrayNode;
                arrayNode = arrayNode->next[i];
                while(arrayNode != NULL){
                    if(isSameTuple(curT,arrayNode->element,relations->size)){
                        father->next[i] = arrayNode->next[i];
                        break;
                    }
                    father = arrayNode;
                    arrayNode = arrayNode->next[0];
                }
            }
        }
        free_Nodes(finding);
        free_Nodes(curNode);
        free_Tuple(curT);
        relations->tupleNum --;
    }
    print_Relation(relations);
}


// search the tuples given elements, return the list of tuples
Nodes lookup(char* elements[], Relations relations){
    // if tuples is empty, then nothing is their
    if(relations->tupleNum == 0) return NULL;
    bool sequence[relations->size];
    int start = -1;
    for(int i = 0; i < relations->size; i++){
        if(strlen(elements[i]) != 0) {
            if(start == -1){
                start = i;
            }
            sequence[i] = true;
        }
        else{
            sequence[i] = false;
        }
    }
    Nodes ans = new_Node(1);
    // start = -1 means elements has no requirement, we need to return every tuples in the relation
    if(start == -1){
        Nodes cur = ans;
        HashTables tables = relations->hashTables[0];
        for(int j = 0; j < tables->size; j ++){
            Nodes arrayNode = tables->array[j];
            while(arrayNode != NULL){
                cur->next[0] = new_Node(1);
                cur = cur->next[0];
                cur->element = arrayNode->element;
                arrayNode = arrayNode->next[0];
            }
        }
        cur = ans->next[0];
        free_Nodes(ans);
        return cur;
    }
    else{

        Nodes curNode = ans;
        HashTables tables = relations->hashTables[start];
        int pos = getNum(elements[start]);
        pos = pos % tables->size;
        Nodes arrayNode = tables->array[pos];
        // get into the hasharray's position and check in the array that which tupples fits the requirement
        while(arrayNode != NULL){
            int flag = true;
            Tuples t = arrayNode->element;
            for(int i = start; i < relations->size; i++){
                if(strlen(elements[i]) != 0){
                    char* x = elements[i];
                    char* y = t->elements[i];
                    if(x != y){
                        flag = false;
                        break;
                    }
                }
            }
            // flag is true means requirement is attained, and push the tupples into the list
            if(flag){
                curNode->next[0] = new_Node(1);
                curNode = curNode->next[0];
                curNode->element = t;
            }
            arrayNode = arrayNode->next[start];
        }
        Nodes val = ans->next[0];
        free_Nodes(ans);
        if(val == NULL){
            return NULL;
        }
        return val;
    }
}

// print out the relations
void print_Relation(Relations r){
    for(int i = 0; i < r->size; i ++){
        printf("%s      ",r->name[i]);
    }
    printf("\n");
    HashTables y = r->hashTables[0];
    for(int i = 0; i <y->size;  i++){
        Nodes cur = y->array[i];
        while(cur != NULL){
            for(int j = 0; j < r->size; j++){
                printf("%s      ",cur->element->elements[j]);
            }
            printf("\n");
            cur = cur->next[0];
        }
    }
}

// print out the nodes
void print_Nodes(Nodes s, int size){
    while(s != NULL){
        Tuples t = s->element;
        for(int i = 0; i < size; i ++){
            printf("%s      ",t->elements[i]);
        }
        printf("\n");
        s = s->next[0];
    }
}
