#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

ofstream fout("out.txt");

vector<string> v, pers;
map<string, string>pereche;

int main()
{
    int n, ok = 1, dim;
    cin >> n;
    v.resize(n);
    pers.resize(n);
    dim = n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pers[i] = v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        ok = 1;
        while(ok) {
            srand(time(NULL));
            int random = rand() % dim;
            if (v[random] != pers[i]) {
                pereche[pers[i]] = v[random];
                ok = 0;
                v.erase(v.begin()+random);
                dim--;
            }
        }
    }
    pereche[pers[n-1]] = v[0];
    while(pereche[pers[n-1]] == pers[n-1])
    {
        srand(time(NULL));
        int random = rand() % n;
        if(pers[random] != pers[n-1])
            swap(pereche[pers[n-1]], pereche[pers[random]]);
    }
    for(auto it:pereche)
        fout << it.first << ", your partner is " << it.second << '\n';
} 