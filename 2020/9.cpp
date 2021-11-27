#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> numbers;
    for (int i = 0; i < 25; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    int index = 0, a;
    while (cin >> a) {
        // kiszámít
        bool good = false;
        for (int i = 0; i < 24 && !good; i++) {
            for (int j = i + 1; j < 25; j++) {
                if (a == numbers[i] + numbers[j]) {
                    good = true;
                    break;
                }
            }
        }

        if (!good) {
            cout << a << endl;
        }

        // beállít
        numbers[index++] = a;
        if (index == 25) index = 0;
    }
}
