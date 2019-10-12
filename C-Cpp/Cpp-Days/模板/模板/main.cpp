#include <iostream>

int main() {
    using namespace std;
    
    int n = 0;
    int max = 0, min = 0;
    int *p_arr = new int[n];

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        cin >> p_arr[i];
        min += p_arr[i];
    }


    for (int i = 0; i < n; ++i) {
        max += i;
    }

    cout << (max-min) << endl;

    return 0;
}