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
    // testing for part One
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

    print_Relation(TPN);


    printf("\n testing for part two\n");

    // testing for part Two
    //Navigation_One_test(PIB, TPN);
    //Navigation_Two_test(PIB,GHVD,GPG);


    // testing for part Three
    Relations PIB2 = new_PIB();
    char* zz[] = {"1111","2222","3333"};
    add(zz,PIB2);
    char *y1[] = {"75196","A.Moore","28 AUG 1985"};
    delete(y1,PIB2);
    Relations test = Intersection(PIB,PIB2);
    Relations difference = Difference(PIB2, PIB);


    print_Relation(difference);
    free_Relations(difference);
    print_Relation(test);
    free_Relations(PIB2);
    free_Relations(test);
    free_Relations(PIB);
    free_Relations(TPN);
    free_Relations(GHVD);
    free_Relations(TC);
    free_Relations(GPG);
}


