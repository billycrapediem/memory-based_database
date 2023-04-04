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
    printf("type the name(type \"quit\" to quit): ");
    fgets(Name,sizeof Name,stdin);
    if(strcmp(Name,"quit\n") == 0) return;
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
        if(strcmp("quit\n",Name) == 0) return;
        printf("type the Team (type \"quit\" to quit): ");
        fgets(Team,sizeof Team,stdin);
    }
}
//
// part two question 2
//
Nodes Find_GOAL_Date_Name(Relations PIB, Relations GHVD, Relations GPG, char* name, char* date){
    char* y[] = {"","","",date};
    Nodes Games = lookup(y,GHVD);
    if(Games == NULL) return NULL;
    Nodes Goals = new_Node(1);
    Nodes head = Goals;
    while(Games != NULL){
        Nodes curNode = Games;
        Tuples curT = Games->element;
        char* curString[] = {curT->elements[0],"",""};
        Nodes arrayNode = lookup(curString,GPG);
        head->next[0] = arrayNode;
        while(head->next[0] != NULL){
            head = head->next[0];
        }
        Games = Games->next[0];
        free_Nodes(curNode);
    }
    Nodes d = Goals;
    Goals = Goals->next[0];
    free_Nodes(d);
    char* x[] = {"",name,""};
    Nodes PlayerId = lookup(x,PIB);
    Nodes traverse, ans = new_Node(1);
    Nodes curAns = ans;
    while(Goals != NULL){
        traverse = PlayerId;
        Nodes curNode = Goals;
        while(traverse != NULL){
            char* id = traverse->element->elements[0];
            Tuples curT = curNode->element;
            if(strcmp(curT->elements[1],id) == 0){
                Tuples newT = new_Tuple(3);
                char* newString[] = {name,date,Goals->element->elements[2]};
                set_Tuple(newString,newT,3);
                curAns->next[0] = new_Node(1);
                curAns->next[0]->element = newT;
                break;
            }
            traverse = traverse->next[0];
        }
        Goals = Goals->next[0];
        free_Nodes(curNode);

    }
    while(PlayerId != NULL){
        Nodes curNode = PlayerId;
        PlayerId = PlayerId->next[0];
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

void Navigation_Two_test(Relations PIB, Relations GHVD, Relations GPG ){
    char Name[256];
    char Date[256];
    printf("type the name(type \"quit\" to quit): ");
    fgets(Name,sizeof Name,stdin);
    if(strcmp(Name,"quit\n") == 0) return;
    printf("type the Date (type \"quit\" to quit): ");
    fgets(Date,sizeof Date,stdin);
    while(strcmp("quit\n",Date) != 0){
        char* name = (char*) calloc(strlen(Date) - 1, sizeof(char));
        char* date = (char*) calloc(strlen(Date) - 1, sizeof(char));
        for(int i = 0; i < strlen(Name)-1; i++){
            name[i] = Name[i];
        }
        for(int i = 0; i < strlen(Date)-1; i++){
            date[i] = Date[i];
        }
        Nodes outcome = Find_GOAL_Date_Name(PIB, GHVD,GPG, name, date);
        if(outcome == NULL){
            printf("did not found correspond player playing on the date");
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
        free(date);
        printf("\n");
        printf("type the name (type \"quit\" to quit): ");
        fgets(Name,sizeof Name,stdin);
        if(strcmp("quit\n",Name) == 0) break;
        printf("type the Team (type \"quit\" to quit): ");
        fgets(Date,sizeof Date,stdin);
    }
}

//part three

//Intersection

Relations Intersection(Relations x, Relations y){
    Relations ans = new_Relation(x->size,x->name);
    char* z[x->size];
    for(int i = 0; i < x->size; i++){
        z[i] = "";
    }
    Nodes findNode = lookup(z,x);
    while(findNode != NULL){
        Nodes curNode = findNode;
        findNode = findNode->next[0];
        for(int i = 0; i < x->size; i++){
            z[i] = curNode->element->elements[i];
        }
        Nodes yNode = lookup(z,y);
        if(yNode != NULL){
            add(z,ans);
            free_Nodes(yNode);
        }
        free_Nodes(curNode);

    }
    return ans;
}

// Difference

Relations Difference(Relations x, Relations y){
    Relations ans = new_Relation(x->size,x->name);
    char* z[x->size];
    for(int i = 0; i < x->size; i++){
        z[i] = "";
    }
    Nodes xNode = lookup(z,x);
    while(xNode != NULL){
        Nodes curNode = xNode;
        xNode = xNode->next[0];
        for(int i = 0; i < x->size; i++){
            z[i] = curNode->element->elements[i];
        }
        Nodes yNode = lookup(z,y);
        if(yNode != NULL){
            free_Nodes(yNode);
        }
        else{
            add(z,ans);
        }
        free_Nodes(curNode);
    }
    return ans;
}

// selections
Relations  Selections(int pos, char* name, Relations r){
    char* a[r->size];
    for(int i = 0; i < r->size; i++){
        if(i == pos - 1){
            a[i] = name;
        }
        else{
            a[i] = "";
        }
    }
    Relations ans = new_Relation(r->size,r->name);
    Nodes find = lookup(a,r);
    while(find != NULL){
        Nodes curNode = find;
        find = find->next[0];
        char* curString[r->size];
        for(int i = 0; i < r->size; i++){
            curString[i] = curNode->element->elements[i];
        }
        add(curString,ans);
        free_Nodes(curNode);
    }
    return ans;
}

Relations Projections(const int* pos, Relations x,int size){
    char* name[size];
    for(int i = 0; i < size; i ++){
        name[i] = x->name[pos[i]-1];
    }
    Relations ans = new_Relation(size,name);
    HashTables tables = x->hashTables[0];
    for(int i = 0; i < tables->size; i++){
        Nodes arrayNode = tables->array[i];
        while(arrayNode != NULL){
            Tuples curT = arrayNode->element;
            char* tuples[size];
            for(int j = 0; j < size; j++){
                tuples[j] = curT->elements[pos[j]-1];
            }
            add(tuples,ans);
            arrayNode = arrayNode->next[0];
        }
    }
    return ans;
}
