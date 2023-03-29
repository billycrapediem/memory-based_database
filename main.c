#include <stdio.h>
#include "string.h"
#include "relations.h"
#include "build_relation.h"
#include "PartTwo_Three.h"
void printS(char *x[]){
    for(int i = 0; i < 3 ; i++){
        if(strlen(x[i]) == 0) printf("here");
    }
}

int main() {
    Relations PIB = new_PIB();
    Relations TPN = new_TPN();
    char *y1[] = {"75196","A.Moore","28 AUG 1985"};
    char *y2[] = {"59797","G.Jones","26 Dec 1986"};
    char *y3[] = {"87977","U.Hughes","13 Feb 1990"};
    char *y4[] = {"61367","A.Moore","18 Mar 2000"};
    char *y6[] = {"70513","G.King","13 Apr 1993"};
    char *y7[] = {"51213","G.King","13 Apr 1993"};
    char *y8[] = {"39468","G.Jones","5 Jan 1993"};
    char *y5[] = {"","","26 Dec 1986"};
    char *z[] = {"","A.Moore",""};
    char *z1[] = {"Americans","87977","11"};
    char *z2[] = {"Americans","75196","7"};
    char *z3[] = {"Americans","61367","99"};
    char *z4[] = {"Maple Leafs","75196","7"};
    add(z1,TPN);
    add(z2,TPN);
    add(z3,TPN);
    add(z4,TPN);
    print_Relation(TPN);
    add(y1,PIB);
    add(y2,PIB);
    add(y3,PIB);
    add(y4,PIB);
    add(y6,PIB);
    add(y7,PIB);
    //delete(y5,PIB);
    //delete(z,PIB);
    add(y8,PIB);
    //delete(z,PIB);
    print_Relation(PIB);

    Navigation_One_test(PIB,TPN);
    free_Relations(PIB);
    free_Relations(TPN);
}


