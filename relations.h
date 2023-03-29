//
// Created by Bryan Zhang on 3/23/23.
//

#ifndef CSC173_PROJECT4_RELATIONS_H

typedef struct Tuple* Tuples;
typedef struct Node* Nodes;
typedef struct HashTable* HashTables;
typedef struct Relation* Relations;
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
extern Relations new_Relation(int size, char** name);
extern HashTables new_HashTable(int size);
extern Nodes new_Node(int x);
extern void free_Tuple(Tuples x);
extern void add(char* element[],Relations r);
extern Tuples new_Tuple(int x);
extern void set_Tuple(char* x[], Tuples t,int size);
extern void free_Nodes(Nodes x);
extern void print_Relation(Relations r);
extern Nodes lookup(char* element[],Relations r);
extern void print_Nodes(Nodes n,int x);
extern void free_Relations(Relations x);
extern void delete(char* elements[], Relations relations);
#define CSC173_PROJECT4_RELATIONS_H

#endif //CSC173_PROJECT4_RELATIONS_H
