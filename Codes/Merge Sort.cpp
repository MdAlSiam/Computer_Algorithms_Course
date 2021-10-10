#include <bits/stdc++.h>
using namespace std;

void merge_sort(int* num, int lo, int hi) {
    if(lo == hi) return;

    int mid = lo + (hi - lo) / 2;

    merge_sort(num, lo, mid);
    merge_sort(num, mid+1, hi);

    int i, j, k, kk;
    int temp[hi-lo+9];
    for (i = lo, j = mid+1, k = 0, kk = lo; kk <= hi; k++, kk++) {
        if(i == mid+1) temp[k] = num[j++];
        else if(j == hi+1) temp[k] = num[i++];
        else if(num[i] < num[j]) temp[k] = num[i++];
        else temp[k] = num[j++];
    }
    for (int xx = lo, yy = 0; xx <= hi; xx++, yy++) num[xx] = temp[yy];
}

int main(){
    int num[50005];
    int n;
    cout << "How many numbers do you want to process?: ";
    cin >> n;

    freopen("G:\Random Numbers.txt", "r", stdin);
    freopen("G:\Output for Merge Sort.txt", "w", stdout);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    clock_t start = clock();
    merge_sort(num, 0, n-1);
    clock_t stop = clock();

    double duration = (double) (stop - start);
    duration /= (CLOCKS_PER_SEC*1.00);

    for(int i = 0; i < n; i++){
        printf("%d\n", num[i]);
    }
    
    cout << "Time required for merge sort for " << n << " data: "
    << duration << " seconds." << endl;
}