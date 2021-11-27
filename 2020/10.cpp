#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> numbers;

    int a;
    while (cin >> a) {
        numbers.push_back(a);
    }

    sort(numbers.begin(), numbers.end());

    int e = 1, h = 1;
    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i + 1] - numbers[i] == 1) {
            e++;
        } else if (numbers[i + 1] - numbers[i] == 3) {
            h++;
        }
    }

    cout << e << " " << h << endl;

    cout << (e * h) << endl;
}
