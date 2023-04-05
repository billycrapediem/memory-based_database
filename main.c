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
    // testing for part One
    printf("testing for function in part One: \n");

    printf("lookup(⟨“Americans”,61367,99⟩,Team-PlayerId-Number)\n");
    char* a[] = {"Americans","61367","99"};
    print_Nodes(lookup(a,TPN),TPN->size);
    printf("lookup(⟨“Crunch”,51213,∗⟩,Team-PlayerId-Number)\n");
    char* b[] = {"Crunch","51213",""};
    print_Nodes(lookup(b,TPN),TPN->size);
    printf("lookup (⟨“Americans”, “Toronto”⟩, Team-City)\n");
    char* c[] = {"Americans","Toronto",};
    print_Nodes(lookup(c,TC),TC->size);
    printf("delete (⟨“Redwings”, “Maple Leafs”, “6 Jan 2023”⟩, GameId-HomeTeam-AwayTeam-Date)\n");
    char* d[] = {"","Redwings","Maple Leafs","6 Jan 2023"};
    delete(d,GHVD);
    print_Relation(GHVD);
    printf("delete (⟨“Redwings”, “Crunch”, ∗⟩, GameId-HomeTeam-AwayTeam-Date)e\n");
    char* e[] = {"","Redwings","Crunch",""};
    delete(e,GHVD);
    print_Relation(GHVD);
    printf("delete (⟨“Americans”, ∗, ∗⟩, GameId-HomeTeam-AwayTeam-Date) f\n");
    char* f[] = {"","Americans","",""};
    delete(f,GHVD);
    print_Relation(GHVD);
    printf("insert(⟨“Ice Pilots”,“Pensacola”⟩,Team-City)\n");
    char* g[] = {"Ice Pilots","Pensacola"};
    add(g,TC);
    print_Relation(TC);
    printf("insert(⟨“Crunch”,“Syracuse”⟩,Team-City)\n");
    char* h[] = {"Crunch","Syracuse"};
    add(h,TC);
    print_Relation(TC);


    printf("\n testing for part two\n");
    // creating new relations
    Relations PIB1 = new_PIB();
    Relations TPN1 = new_TPN();
    Relations GHVD1 = new_GHVD();
    Relations GPG1 = new_GPG();
    // testing for part Two
    printf("What number did Name wear when play- ing for Team?\n");
    Navigation_One_test(PIB1, TPN1);
    printf("How many goals did Name score on Date?\n");
    Navigation_Two_test(PIB1,GHVD1,GPG1);

    // testing for part Three
    printf("\ntesting for part three\n");
    Relations PIB2 = new_PIB();
    char* zz[] = {"1111","B Zhang","7 Jan 2001"};
    add(zz,PIB2);
    char *y1[] = {"75196","A.Moore","28 AUG 1985"};
    delete(y1,PIB2);
    Relations intersection = Intersection(PIB,PIB2);
    printf("testing for itersection\n");
    print_Relation(intersection);
    Relations difference = Difference(PIB2, PIB);
    printf("testing for Difference\n");
    print_Relation(difference);
    Relations combine = Union(PIB2, PIB);
    printf("testing for Union\n");
    print_Relation(combine);

    printf("testing for Selection\n");
    Relations selection = Selections(0,"51213",PIB1);
    int array[] = {0};
    print_Relation(selection);
    printf("testing for projection\n");
    Relations projection = Projections(array,selection,1);
    print_Relation(projection);

    Relations join = Join(GHVD1,GPG1,0,0);
    printf("testing for Join \n");
    print_Relation(join);
    // 4
    printf("all three combine\n");
    int arrayx[] = {4,5};
    Relations test_selection = Selections(3,"8 Jan 2023", join);
    Relations test = Projections(arrayx,test_selection ,2);
    print_Relation(test);

    //free created relations
    free_Relations(test_selection);
    free_Relations(test);
    free_Relations(combine);
    free_Relations(join);
    free_Relations(selection);
    free_Relations(projection);
    free_Relations(difference);
    free_Relations(PIB2);
    free_Relations(intersection);
    free_Relations(PIB);
    free_Relations(TPN);
    free_Relations(GHVD);
    free_Relations(TC);
    free_Relations(GPG);
    free_Relations(PIB1);
    free_Relations(TPN1);
    free_Relations(GPG1);
    free_Relations(GHVD1);
}


