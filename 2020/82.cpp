#include <bits/stdc++.h>

using namespace std;

#define nop 0
#define jmp 1
#define acc 2

int main() {
    // instruction (0: nop, 1: jmp, 2: acc), argument
    vector<pair<int, int>> inst;

    string s;
    while (cin >> s) {
        int arg;
        cin >> arg;
        if (s == "nop") {
            inst.push_back(make_pair(nop, arg));
        } else if (s == "jmp") {
            inst.push_back(make_pair(jmp, arg));
        } else if (s == "acc") {
            inst.push_back(make_pair(acc, arg));
        }
    }

    // Modify code
    vector<bool> vis(inst.size(), false);
    int pc;
    int a;
    int changed = -1;
    do {
        vis.assign(inst.size(), false);

        if (changed != -1) {
            if (inst[changed].first == nop) {
                inst[changed].first = jmp;
            } else if (inst[changed].first == jmp) {
                inst[changed].first = nop;
            }
        }

        int i = changed + 1;
        changed = -1;

        for (; i < inst.size(); i++) {
            if (inst[i].first == jmp) {
                inst[i].first = nop;
                changed = i;
                break;
            } else if (inst[i].first == nop) {
                inst[i].first = jmp;
                changed = i;
                break;
            }
        }

        a = 0;
        pc = 0;
        while (!vis[pc] && pc < inst.size()) {
            vis[pc] = true;
            pair<int, int> i = inst[pc];
            if (i.first == nop) {
                pc++;
            } else if (i.first == jmp) {
                pc += i.second;
            } else if (i.first == acc) {
                a += i.second;
                pc++;
            }
        }

        cout << pc << " " << changed << endl;
    } while (pc < inst.size() && changed != -1);

    cout << changed << " " << pc << " " << a << endl;
}
