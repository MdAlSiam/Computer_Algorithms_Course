#include <bits/stdc++.h>
using namespace std;

typedef struct{int weight; int profit;} dataset;

bool compare(dataset a, dataset b){
    return a.profit > b.profit;
}

int main(){
    int n;
    cout << "How many data do you want to take? : ";
    cin >> n;

    dataset input[n+2];

    int total_wt = 0;

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++){
        scanf("%d", &input[i].weight);
        total_wt += input[i].weight;
    }

    int max_wt = (int) ((total_wt*70)/100);

    cout << "Enter profits:\n";
    for(int i = 0; i < n; i++){
        scanf("%d", &input[i].profit);
    }

    sort(input, input+n, compare);

    int total_profit = 0;
    dataset ans[n+2];
    int index = 0;

    clock_t start = clock();
    for(int i = 0; (i < n) && ((max_wt - input[i].weight) >= 0); i++){
        total_profit += input[i].profit;
        max_wt -= input[i].weight;
        ans[index].weight = input[i].weight;
        ans[index].profit = input[i].profit;
        index++;
    }
    clock_t stop = clock();
    double duration = (double)((stop - start) / 2.4e9);

    cout << "Time Required = " << setprecision(12) << ((stop - start) / 2.4e9) << endl;
    cout << "Maximum Profit: " << total_profit << endl;

    for(int i = 0; i < index; i++){
        cout << "Wt: " << ans[i].weight
        << " Profit: " << ans[i].profit << endl;
    }
}
