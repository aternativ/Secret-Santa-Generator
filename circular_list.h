#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H
#include <string>
using namespace std;

struct listNode {
    string value;
    listNode *prev, *next;
};

struct circularList {
    listNode *last;
    long long size;
};

// creates an empty list
circularList *createList();
// inserts an element at the end of the list
void insertRear(circularList *list, string value);
// removes the specified node and retrieves the node after it
listNode *remove_get_next(circularList *list, listNode *current);
// retrieves the node "n" steps after the specified node
listNode *advance_n_steps(listNode *current, long long steps);
// frees each node
void freeNodes(listNode *current);
// frees the list itself
void freeList(circularList *list);

#endif