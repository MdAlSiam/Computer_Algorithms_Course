#include <bits/stdc++.h>
using namespace std;

int weight[1010];
int profit[1010];
int number_of_items;
int capacity;

int knapsac(int i, int w){
    if(i >= number_of_items) return 0;

    int profit1 = 0, profit2 = 0;

    if(w + weight[i] <= capacity){
        profit1 = profit[i] + knapsac(i+1, w+weight[i]);
    }

    profit2 = knapsac(i+1, w);

    return max(profit1, profit2);
}

int main(){

    int n;
    cout << "How many data do you want to take? : ";
    cin >> number_of_items;

    int total = 0;

    cout << "Enter weights:\n";
    for(int i = 0; i < number_of_items; i++){
        scanf("%d", &weight[i]);
        total += weight[i];
    }

    cout << "Enter profits:\n";
    for(int i = 0; i < number_of_items; i++){
        scanf("%d", &profit[i]);
    }

    capacity = (total*70)/100;
    cout << capacity << endl;

    clock_t start = clock();

    int ans = knapsac(0, 0);

    clock_t stop = clock();
    double duration = (double)((stop - start) / 2.4e9);

    cout << "Time Required = " << setprecision(12) << ((stop - start) / 2.4e9) << endl;

    cout << "Maximum profit = " << ans << endl;

}
