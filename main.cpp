#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include <map>
#include <random>
#include "circular_list.h"

using namespace std;

ofstream fout("out.txt");

vector<string> v, pers;
map<string, string>partner;

// read strings, input into list
// while circular list dim != 1, pick partners
// if we pick the person themselves, advance 1
// for the last one, just pick the last value left
// if the partner is the same as the person, swap with
// any previous person

int main()
{
    long long n, ok = 1, dim;
    cin >> n;
    
    if (n <= 1) {
        fout << "Invalid Size";
        return -1;
    }

    circularList *list = createList();
    pers.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pers[i];
        insertRear(list, pers[i]);
    }

    // random from hardware
    random_device rd;
    // seed the gen
    mt19937 gen(rd());
    listNode *current = list->last;

    for (long long i = 0; i < n - 1; i++) {
        // define range
        uniform_int_distribution<> distr(0, list->size - 1);
        long long steps = distr(gen);
        // select a random person
        advance_n_steps(current, steps);
        // if we select the person themselves, choose the next person
        if (current->value == pers[i])
            current = current->next;
        partner[pers[i]] = current->value;
        // remove the person from the list as they have been selected
        current = remove_get_next(list, current);
    }

    // attribute the last value without checking and free memory
    partner[pers[n - 1]] = current->value;
    freeList(list);

    // if the last value is the same as the last person
    if (partner[pers[n - 1]] == pers[n - 1]) {
        uniform_int_distribution<> distr(0, n - 1);
        long long random_person = distr(gen);
        swap(partner[pers[n - 1]], partner[pers[random_person]]);
    }

    for(auto it:partner)
        fout << it.first << ", your partner is " << it.second << '\n';

    return 0;
} 