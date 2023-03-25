//
// Created by Bryan Zhang on 3/23/23.
//

#ifndef CSC173_PROJECT4_RELATIONS_H
typedef struct Tuple* Tuples;
typedef struct Node* Nodes;
typedef struct HashTable* HashTables;
typedef struct Relation* Relations;
extern Relations new_Relation(int size, char** name);
extern HashTables new_HashTable(int size);
extern Nodes new_Node(int x);
extern void add(char* element[],Relations r);
extern void set_Node_Tuples(Tuples x, Nodes y);
extern char** name(Relations x);
extern void print_Relation(Relations r);
extern Nodes lookup(char* element[],Relations r);
extern void print_Nodes(Nodes n,int x);
extern void free_Relations(Relations x);
extern void delete(char* elements[], Relations relations);
#define CSC173_PROJECT4_RELATIONS_H

#endif //CSC173_PROJECT4_RELATIONS_H
