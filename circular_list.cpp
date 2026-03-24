#include <iostream>
using namespace std;
#include "circular_list.h"

circularList *createList()
{
    circularList *myList = new circularList;
    myList->last = NULL;
    myList->size = 0;
    return myList;
}

void insertRear(circularList *list, string value) 
{
    if (!list) {
        cout << "List is not allocated.";
        return;
    }
    listNode *node = new listNode;
    node->value = value;
    // inserting the first node
    if (!list->last) {
        list->last = node;
        node->next = node;
        node->prev = node;
        list->size++;
        return;
    }
    // inserting after last
    node->next = list->last->next;
    node->next->prev = node;
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
    list->size++;
}

listNode *remove_get_next(circularList *list, listNode *current)
{
    if (!list || !list->last)
        return NULL;
    if (current == list->last) {
        list->last = current->next;
    }
    listNode *temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    current = current->next;
    delete temp;
    return current;
}

listNode *advance_n_steps(listNode *current, long long steps)
{
    while (steps) {
        current = current->next;
        steps--;
    }
    return current;
}

void freeNodes(listNode *current)
{
    listNode *first = current;
    if (!first)
        return;
    current = current->next;
    while (current != first) {
        listNode *temp = current;
        current = current->next;
        delete temp;
    }
}

void freeList(circularList *list)
{
    if (!list)
        return;
    freeNodes(list->last);
    delete list;
}
