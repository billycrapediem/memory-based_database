//
// Created by Bryan Zhang on 3/28/23.
//
#include "relations.h"
#ifndef CSC173_PROJECT4_PARTTWO_THREE_H
extern void Navigation_One_test(Relations x, Relations y);
extern void Navigation_Two_test(Relations x, Relations y);
extern Relations Union(Relations x, Relations y);
extern Relations Intersection(Relations x, Relations y);
extern Relations Difference(Relations x, Relations y);
extern Relations Join(Relations x, Relations y, int pos1, int pos2);
extern Relations Selections(int pos, char* name, Relations x);
extern Relations Projections(int* pos, Relations x);
#define CSC173_PROJECT4_PARTTWO_THREE_H

#endif //CSC173_PROJECT4_PARTTWO_THREE_H
