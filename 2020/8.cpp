#include <bits/stdc++.h>

using namespace std;

int main() {
    // instruction (0: nop, 1: jmp, 2: acc), argument
    vector<pair<int, int>> inst;

    string s;
    while (cin >> s) {
        int arg;
        cin >> arg;
        if (s == "nop") {
            inst.push_back(make_pair(0, arg));
        } else if (s == "jmp") {
            inst.push_back(make_pair(1, arg));
        } else if (s == "acc") {
            inst.push_back(make_pair(2, arg));
        }
    }

    vector<bool> vis(inst.size(), false);
    int pc = 0;
    int acc = 0;
    while (!vis[pc]) {
        vis[pc] = true;
        pair<int, int> i = inst[pc];
        if (i.first == 0) {
            pc++;
        } else if (i.first == 1) {
            pc += i.second;
        } else if (i.first == 2) {
            acc += i.second;
            pc++;
        }
    }

    cout << acc << endl;
}
