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


