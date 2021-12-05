#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<vector<int>>>& tables, int table, int i, int j) {
    bool good = true;
    for (int i = 0; i < 5; i++) {
        if (tables[table][i][j] >= 0) {
            good = false;
            break;
        }
    }
    if (good) return true;

    good = true;
    for (int j = 0; j < 5; j++) {
        if (tables[table][i][j] >= 0) {
            good = false;
            break;
        }
    }

    return good;
}

int sum_f(vector<vector<int>>& table) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (table[i][j] >= 0) {
                sum += table[i][j];
            }
        }
    }
    return sum;
}

int main() {
    vector<int> order;
    string orderLine;
    getline(cin, orderLine);

    stringstream ssin(orderLine);
    int o;
    char comma;
    do {
        ssin >> o;
        order.push_back(o);
    } while (ssin >> comma);

    cin >> ws;
    vector<vector<vector<int>>> tables;
    int table = 0;
    do {
        tables.push_back(vector<vector<int>>(5, vector<int>(5)));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int a;
                cin >> a;
                tables[table][i][j] = a;
            }
        }
        table++;
        cin >> ws;
    } while (cin.peek() != EOF);

    vector<bool> won(tables.size(), false);
    int last = -1, sum = -1, lastTable = -1, winCount = 0;
    for (int i = 0; i < order.size(); i++) {
        int a = order[i];
        for (int table = 0; table < tables.size(); table++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (tables[table][i][j] == a) {
                        tables[table][i][j] = -(a + 1);
                        if (!won[table] && check(tables, table, i, j)) {
                            winCount++;
                            last = a;
                            lastTable = table;
                            won[table] = true;
                            sum = sum_f(tables[table]);
                        }
                    }
                }
            }
        }
    }

    cout << winCount << endl;
    cout << lastTable << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (tables[lastTable][i][j] >= 0) {
                cout << tables[lastTable][i][j] << "\t";
            } else {
                cout << "-" << -(tables[lastTable][i][j] + 1) << "\t";
            }
        }
        cout << endl;
    }
    cout << last << " " << sum << endl;
    cout << (last * sum) << endl;
}
