#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> numbers, all_numbers;
    for (int i = 0; i < 25; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
        all_numbers.push_back(a);
    }

    int index = 0, a, bad;
    while (cin >> a) {
        all_numbers.push_back(a);

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
            bad = a;
        }

        // beállít
        numbers[index++] = a;
        if (index == 25) index = 0;
    }

    cout << "Bad: " << bad << endl;

    long long sum = 0, l = 0;
    for (int i = 0; i < all_numbers.size(); i++) {
        sum += all_numbers[i];
        l++;

        while (sum > bad) {
            sum -= all_numbers[i - l + 1];
            l--;
        }
        
        if (sum == bad && l >= 2) {
            int min = *min_element(all_numbers.begin() + i - l + 1, all_numbers.begin() + i + 1);
            int max = *max_element(all_numbers.begin() + i - l + 1, all_numbers.begin() + i + 1);
            cout << (i - l + 1) << " " << i << endl;
            cout << min << " " << max << endl;
            cout << (min + max) << endl;
            break;
        }
    }
}
