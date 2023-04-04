//
// Created by Bryan Zhang on 3/23/23.
//
#include "relations.h"
#include "build_relation.h"

Relations new_PIB(){
    char *x[] = {"PlayerId","Name","BirthDate"};
    Relations PIB = new_Relation(3,x);
    char *y1[] = {"75196","A.Moore","28 AUG 1985"};
    char *y2[] = {"59797","G.Jones","26 Dec 1986"};
    char *y3[] = {"87977","U.Hughes","13 Feb 1990"};
    char *a1[] = {"20945","Q.Morgan","14 Feb 1998"};
    char *y6[] = {"70513","G.King","13 Apr 1993"};
    char *y7[] = {"51213","T.Sullivan","13 Apr 1993"};
    char *y4[] = {"61367","A.Moore","18 Mar 2000"};
    char *a2[] = {"55879","D.Hernandez","25 Jul 1997"};
    char *a3[] = {"47087","W.Stewart","5 Jan 1994"};
    char *y8[] = {"39468","G.Jones","5 Jan 1993"};
    add(y1,PIB);
    add(y2,PIB);
    add(y3,PIB);
    add(y4,PIB);
    add(y6,PIB);
    add(y7,PIB);
    add(y8,PIB);
    add(a1,PIB);
    add(a2,PIB);
    add(a3,PIB);
    return PIB;
}
Relations new_TPN(){
    char *x[] = {"Team","PlayerId","Number"};
    Relations TPN = new_Relation(3,x);
    char *z1[] = {"Americans","87977","11"};
    char *z2[] = {"Americans","75196","7"};
    char *z3[] = {"Americans","61367","99"};
    char *z4[] = {"Maple Leafs","75196","7"};
    char *z5[] = {"Maple Leafs","20945","24"};
    char *z6[] = {"Redwings","70513","10"};
    char *z10[] = {"Redwings","20945","10"};
    char *z7[] = {"Crunch","51213","1"};
    char *z8[] = {"Crunch","51213","9"};
    char *z9[] = {"Crunch","55870","13"};
    add(z10,TPN);
    add(z1,TPN);
    add(z2,TPN);
    add(z3,TPN);
    add(z4,TPN);
    add(z5,TPN);
    add(z6,TPN);
    add(z7,TPN);
    add(z8,TPN);
    add(z9,TPN);
    return TPN;
}

Relations new_TC(){
    char *x[] = {"Team","City"};
    Relations TC = new_Relation(2,x);
    char* a1[] = {"Americans","Rochester"};
    char* a2[] = {"Maple Leafs","Toronto"};
    char* a3[] = {"Redwings","Detroit"};
    char* a4[] = {"Crunch","Syracuse"};
    add(a1,TC);
    add(a2,TC);
    add(a3,TC);
    add(a4,TC);
    return TC;
}

Relations new_GHVD(){
    char *x[] = {"GameId","HomeTeam","VisitorTeam","Date"};
    Relations GHVD = new_Relation(4,x);
    char* a1[] = {"1","Americans","Maple Leafs","3 Jan 2023"};
    char* a2[] = {"2","Crunch","Redwings","3 Jan 2023"};
    char* a3[] = {"3","Americans","Crunch","6 Jan 2023"};
    char* a4[] = {"4", "Redwings","Maple Leafs","6 Jan 2023"};
    char* a5[] = {"5","Redwings","Americans","8 Jan 2023"};
    char* a6[] = {"6","Maple Leafs","Curnch","8 Jan 2023"};
    char* a7[] = {"7","Maple Leafs","Curnch","9 Jan 2023"};
    char* a8[] = {"8","Americans","Redwings","10 Jan 2023"};
    char* a9[] = {"9","Crunch","Americans","12 Jan 2023"};
    char* a10[] = {"10","Redwings","Maple Leafs","12 Jan 2023"};
    add(a1,GHVD);
    add(a2,GHVD);
    add(a3,GHVD);
    add(a4,GHVD);
    add(a5,GHVD);
    add(a6,GHVD);
    add(a7,GHVD);
    add(a8,GHVD);
    add(a9,GHVD);
    add(a10,GHVD);
    return GHVD;
}

Relations new_GPG(){
    char *x[] = {"GameId","PlayerId","Goals"};
    Relations GPG = new_Relation(3,x);
    char* a1[] = {"2","55870","1"};
    char* a2[] = {"2","70513","2"};
    char* a3[] = {"3","51213","1"};
    char* a4[] = {"5","20945","4"};
    char* a5[] = {"6","55870","2"};
    char* a6[] = {"7","75196","1"};
    char* a7[] = {"8","87977","1"};
    char* a8[] = {"8","75196","2"};
    char* a9[] = {"9","55870","3"};
    char* a10[] = {"9","61367","2"};
    add(a1,GPG);
    add(a2,GPG);
    add(a3,GPG);
    add(a4,GPG);
    add(a5,GPG);
    add(a6,GPG);
    add(a7,GPG);
    add(a8,GPG);
    add(a9,GPG);
    add(a10,GPG);
    return GPG;
}
