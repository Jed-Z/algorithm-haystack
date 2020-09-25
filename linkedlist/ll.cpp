#define _CRT_SECURE_NO_WARNINGS
#include "ll.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init(List *list) {
    *list = (Node *)malloc(sizeof(Node));
    (*list)->next = NULL;
}
bool isempty(List *list) {
    bool result = 0;
    if ((*list)->next == NULL) {
        result = 1;
    }
    return result;
}
bool insert(List *list, int pos, char name[], int sex) {
    bool result;
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        return 0;
    } else {
        char str[10];
        strncpy(temp->data.name, name, 10);
        temp->data.sex = sex;
        temp->next = NULL;  // temp is ready now.

        Node *crtPtr = *list;
        for (int i = 1; i < pos; i++) {
            crtPtr = crtPtr->next;
            if (crtPtr == NULL) {
                return 0;
            }
        }
        temp->next = crtPtr->next;
        crtPtr->next = temp;
    }

    return 1;
}
bool deletenode(List *list, int pos) {
    bool result = 1;
    if (isempty(list)) {
        return 0;
    }
    Node *pvsPtr = *list, *crtPtr;
    for (int i = 1; i < pos; i++) {
        pvsPtr = pvsPtr->next;
        if (pvsPtr->next == NULL) {
            return 0;
        }
    }
    crtPtr = pvsPtr->next;
    pvsPtr->next = crtPtr->next;
    free(crtPtr);

    return result;
}
void print(List *list) {
    if (isempty(list)) {
        printf("Empty!\n");
    } else {
        int count = 1;
        Node *crtPtr = (*list)->next;
        while (crtPtr) {
            printf("%d: %-10s, %-6s\n", count++, crtPtr->data.name, (crtPtr->data.sex) ? "Female" : "Male");
            crtPtr = crtPtr->next;
        }
    }
}