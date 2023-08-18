//
// Created by Bryan Zhang on 3/28/23.
//
#include "relations.h"
#ifndef MEMORY_BASE_DATABASE_THREE_H
extern void Navigation_One_test(Relations x, Relations y);
extern void Navigation_Two_test(Relations x, Relations y, Relations z);
extern Relations Union(Relations x, Relations y);
extern Relations Intersection(Relations x, Relations y);
extern Relations Difference(Relations x, Relations y);
extern Relations Join(Relations x, Relations y, int pos1, int pos2);
extern Relations Selections(int pos, char* name, Relations x);
extern Relations Projections(const int* pos, Relations x,int size);
#define MEMORY_BASE_DATABASE_PARTTWO_THREE_H

#endif //MEMORY_BASE_DATABASE_THREE_H
