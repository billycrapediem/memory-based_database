//
// Created by Bryan Zhang on 3/28/23.
//
#include "relations.h"
#include "PartTwo_Three.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//
// partwo two question One
//
Nodes Find_Number_Name_Team(char* Name, char* Team, Relations PIB, Relations TPN){
    char* y[] = {"",Name,""};
    // Using index on the PIB relations, that has name component
    Nodes Player = lookup(y,PIB);
    if(Player == NULL) return NULL;
    Nodes ans = new_Node(1);
    Nodes curAns = ans;
    // for each tuple found in the upper part,
    while(Player != NULL){
        Nodes curNode = Player;
        Player = Player->next[0];
        char* findChar[] = {Team,curNode->element->elements[0],""};
        // using index on the on the TPN relations find tuple with playerID and Team name
        Nodes findNum = lookup(findChar,TPN);
        while(findNum != NULL){
            Nodes innerC = findNum;
            findNum = findNum->next[0];
            char* ansChar[] = {Team,Name,innerC->element->elements[2]};
            Tuples ansT = new_Tuple(3);
            set_Tuple(ansChar,ansT,3);
            curAns->next[0] = new_Node(1);
            curAns->next[0]->element = ansT;
            curAns = curAns->next[0];
            free_Nodes(innerC);
        }
        free_Nodes(curNode);
    }
    if(ans->next == NULL){
        free_Nodes(ans);
        return NULL;
    }
    Nodes next = ans->next[0];
    free_Nodes(ans);
    return next;
}

void Navigation_One_test(Relations PIB, Relations TPN){
    char Name[256];
    char Team[256];
    printf("type the name: ");
    fgets(Name,sizeof Name,stdin);
    printf("type the Team (type \"quit\" to quit): ");
    fgets(Team,sizeof Team,stdin);
    while(strcmp("quit\n",Team) != 0){
        char* name = (char*) calloc(strlen(Team) - 1, sizeof(char));
        char* team = (char*) calloc(strlen(Team) - 1, sizeof(char));
        for(int i = 0; i < strlen(Name)-1; i++){
            name[i] = Name[i];
        }
        for(int i = 0; i < strlen(Team)-1; i++){
            team[i] = Team[i];
        }
        Nodes outcome = Find_Number_Name_Team(name, team, PIB, TPN);
        if(outcome == NULL){
            printf("did not found correspond player");
        }
        while(outcome != NULL){
            Nodes curNode = outcome;
            outcome = outcome->next[0];
            for(int i = 0; i < 3; i++){
                printf("%s     ",curNode->element->elements[i]);
            }
            printf("\n");
            free_Tuple(curNode->element);
            free_Nodes(curNode);
        }
        free(name);
        free(team);
        printf("\n");
        printf("type the name (type \"quit\" to quit): ");
        fgets(Name,sizeof Name,stdin);
        printf("type the Team (type \"quit\" to quit): ");
        fgets(Team,sizeof Team,stdin);
    }
}
//
// part two question 2
//

//part three
Relations Union(Relations x, Relations y){
    if(x->size != y->size){
        printf("Different lengths cannot union.");
        return NULL;
    }
    for(int i = 0; i < x->size; i++){
        if(strcmp(x->name[i],y->name[i]) != 0){
            printf("Different schemas cannot union");
            return NULL;
        }
    }
    Relations new = new_Relation(x->size,x->name);
    HashTables htx = x->hashTables[0];
    HashTables hty = y->hashTables[0];
    for(int i = 0; i < hty->size; i++){
        Nodes cur = hty->array[i];
        while(cur != NULL){
            add(hty->array[i]->element->elements, new);
            cur = cur->next[0];
        }
    }
    for(int i = 0; i < htx->size; i++){
        Nodes cur = htx->array[i];
        while(cur != NULL){
            if(lookup(cur->element->elements,y)==NULL){
                add(cur->element->elements,new);
            }
            cur = cur->next[0];
        }
    }
    return new;
}

Relations Join(Relations x, Relations y, int pos1, int pos2){
    char** newName = calloc(x->size+y->size-1,sizeof (char*));
    int count = 0;
    for(int i = 0; i < x->size; i++){
        newName[i] = x->name[i];
    }
    for(int j = 0; j < y->size; j++){
        if(j != pos2){
            newName[j+x->size-count] = y->name[j];
        }
        else{
            count++;
        }
    }
    Relations new = new_Relation(x->size+y->size-1, newName);
    char** element = calloc(x->size+y->size-1, sizeof (char*));
    char** forLookup = calloc(y->size,sizeof (char*));
    for(int i = 0; i < x->hashTables[0]->size; i++){
        Nodes cur = x->hashTables[0]->array[i];
        while(cur != NULL){
            for(int j = 0; j < y->size; j++){
                if(j != pos2){
                    forLookup[j] = "";
                }
                else{
                    forLookup[j] = cur->element->elements[pos1];
                }
            }
            Nodes lookupNode = lookup(forLookup,y);
            while(lookupNode != NULL){
                for (int h = 0; h < x->size; h++) {
                    element[h] = cur->element->elements[h];
                }
                int temp = 0;
                for(int l = 0; l < y->size; l++){
                    if(l != pos2) {
                        element[l - temp + x->size] = lookupNode->element->elements[l];
                    }
                    else{
                        temp++;
                    }
                }
                add(element,new);
                lookupNode = lookupNode->next[0];
            }
            cur = cur->next[0];
        }
    }
    return new;
}
