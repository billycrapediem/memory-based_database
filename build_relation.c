//
// Created by Bryan Zhang on 3/23/23.
//
#include "relations.h"

Relations new_PIB(){
    char *x[] = {"PlayerId","Name","BirthDate"};
    Relations PIB = new_Relation(3,x);
    return PIB;
}
