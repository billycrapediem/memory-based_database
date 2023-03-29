//
// Created by Bryan Zhang on 3/23/23.
//
#include "relations.h"
#include "build_relation.h"

Relations new_PIB(){
    char *x[] = {"PlayerId","Name","BirthDate"};
    Relations new = new_Relation(3,x);
    return new;
}
Relations new_TPN(){
    char *x[] = {"Team","PlayerId","Number"};
    Relations new = new_Relation(3,x);;
    return new;
}

Relations new_TC(){
    char *x[] = {"Team","City"};
    Relations new = new_Relation(2,x);;
    return new;
}

Relations new_GHVD(){
    char *x[] = {"GameId","HomeTeam","VisitorTeam","Date"};
    Relations new = new_Relation(4,x);;
    return new;
}

Relations new_GPG(){
    char *x[] = {"GameId","PlayerId","Goals"};
    Relations new = new_Relation(3,x);;
    return new;
}
