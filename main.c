#include <stdio.h>
#include "relations.h"
#include "build_relation.h"
#include "PartTwo_Three.h"

int main() {
    Relations PIB = new_PIB();
    Relations TPN = new_TPN();
    Relations GHVD = new_GHVD();
    Relations TC = new_TC();
    Relations GPG = new_GPG();
    /*
    print_Relation(TPN);
    print_Relation(GHVD);
    print_Relation(PIB);
    print_Relation(TC);
    print_Relation(GPG);
     */
    printf("testing for function in part One: \n");
    char* a[] = {"Americans","61367","99"};
    print_Nodes(lookup(a,TPN),TPN->size);
    char* d[] = {"","Redwings","Maple Leafs","6 Jan 2023"};
    delete(d,GHVD);
    print_Relation(GHVD);
    char* e[] = {"","Redwings","Crunch",""};
    delete(e,GHVD);
    print_Relation(GHVD);
    char* f[] = {"","Americans","",""};
    delete(f,GHVD);
    print_Relation(GHVD);
    char* g[] = {"Ice Pilots","Pensacola"};
    add(g,TC);
    print_Relation(TC);
    char* h[] = {"Crunch","Syracuse"};
    add(h,TC);
    print_Relation(TC);
    free_Relations(PIB);
    free_Relations(TPN);
    free_Relations(GHVD);
    free_Relations(TC);
    free_Relations(GPG);
}


