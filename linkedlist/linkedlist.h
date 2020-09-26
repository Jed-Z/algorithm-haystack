#pragma once
enum sex { MALE, FEMALE };
typedef struct person {
    char name[10];
    int sex;
} Item;
typedef struct node {
    Item data;
    struct node *next;
} Node;
typedef Node *List;

void init(List *list);
void intro(void);
bool isempty(List *list);
bool insert(List *list, int pos, char name[], int sex);
bool deletenode(List *list, int pos);
void print(List *list);
