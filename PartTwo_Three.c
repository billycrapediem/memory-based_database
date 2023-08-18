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
            printf("did not find correspond player");
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
            printf("did not find correspond player playing on the date");
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
            Nodes z = lookup(cur->element->elements,y);
            if(z==NULL){
                add(cur->element->elements,new);
            }
            else{
                while(z != NULL){
                    Nodes curNode = z;
                    z = z->next[0];
                    free_Nodes(curNode);
                }
            }

            cur = cur->next[0];
        }
    }
    return new;
}

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
Relations Selections(int pos, char* name, Relations x) {
    Relations result = new_Relation(x->size,x->name);
    // create a new array to store the positions of the selected columns
    char** selPos = (char**)malloc((x->size ) * sizeof(char*));
    //char* condition[x->size];
    for (int i = 0; i < x->size; i++) {
        selPos[i] = "";
    }
    selPos[pos] = name;
    // iterate over the tuples in the original relation
    Nodes tuples = lookup(selPos, x);
    while (tuples != NULL) {
        Nodes curNode = tuples;
        Tuples tuple = tuples->element;
        // add the tuple to the resulting relation
        add(tuple->elements, result);
        tuples = tuples->next[0];
        free_Nodes(curNode);
    }
    // free memory and return the resulting relation
    free(selPos);
    return result;
}

Relations Projections(const int* pos, Relations x,int size) {
    char** name = (char**) calloc(size, sizeof(char*));
    for(int i = 0; i < size; i++){
        char* z = x->name[pos[i]];
        name[i] = z;
    }
    Relations result = new_Relation(size,name);

    // create a new array to store the positions of the projected columns
    char* projPos[x->size];
    for (int i = 0; i < x->size; i++) {
        projPos[i] = "";
    }
    // iterate over the tuples in the original relation
    Nodes tuples = lookup(projPos, x);
    while (tuples != NULL) {
        Tuples tuple = tuples->element;
        Nodes curNode = tuples;

        // create a new tuple with only the projected columns
        char* newChar[size];
        for (int i = 0; i < size; i++) {
            newChar[i]= tuple->elements[pos[i]];
        }
        // add the new tuple to the resulting relation
        add(newChar, result);
        tuples = tuples->next[0];
        free_Nodes(curNode);
    }
    free(name);
    // free memory and return the resulting relation
    return result;
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
                 Nodes curNode = lookupNode;
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
                free_Nodes(curNode);
            }
            cur = cur->next[0];
        }
    }
    free(element);
    free(forLookup);
    free(newName);
    return new;
}
