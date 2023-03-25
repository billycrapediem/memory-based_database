#include <stdio.h>
#include "string.h"
#include "relations.h"
void printS(char *x[]){
    for(int i = 0; i < 3 ; i++){
        if(strlen(x[i]) == 0) printf("here");
    }
}

int main() {
    char *x[] = {"PlayerId","Name","BirthDate"};
    Relations PIB = new_Relation(3,x);
    char *y1[] = {"75196","A.Moore","28 AUG 1985"};
    char *y2[] = {"59797","G.Jones","26 Dec 1986"};
    char *y3[] = {"87977","U.Hughes","13 Feb 1990"};
    char *y4[] = {"61367","A.Moore","18Mar20000"};
    char *y5[] = {"","",""};
    add(y1,PIB);
    add(y2,PIB);
    add(y3,PIB);
    add(y4,PIB);
    print_Relation(PIB);
    delete(y5,PIB);
    free_Relations(PIB);
}


