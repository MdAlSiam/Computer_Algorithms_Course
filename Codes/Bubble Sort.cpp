
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int* num, int n) {
    bool isSwapped;

    for (int i = 0; i < n-1; i++) {
        isSwapped = false;
        for (int j = 0; j < n-1-i; j++) {
            if(num[j] > num[j+1]){
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
    }
}

int main() {
    int num[50005];
    int n;
    cout << "How many numbers do you want to process?: ";
    cin >> n;

    freopen("G:\Random Numbers.txt", "r", stdin);
    freopen("G:\Output for Bubble Sort.txt", "w", stdout);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    clock_t start = clock();

    bubble_sort(num, n);

    clock_t stop = clock();

    double duration = (double) (stop - start);
    duration /= (CLOCKS_PER_SEC*1.00);

    for (int i = 0; i < n; i++){
        printf("%d\n", num[i]);
    }

    cout << "Time required for bubble sort for " << n << " data: "
    << duration << " seconds." << endl;
}
