#include <bits/stdc++.h>
using namespace std;

int find_correct_position(int* ara, int target_pos, int last_pos){
    int pivot = ara[target_pos];
    int curr = last_pos+1;

    for(int i = last_pos; i >= 0; i--){
        if(ara[i] > pivot){
            curr--;
            swap(ara[i], ara[curr]);
        }
    }
    curr--;
    swap(ara[curr], ara[target_pos]);
    return curr;
}

void my_sort(int* ara, int lo, int hi){
    if(lo >= hi) return;
    int curr_pos = find_correct_position(ara, lo, hi);
    my_sort(ara, lo, curr_pos-1);
    my_sort(ara, curr_pos+1, hi);
}

int main(){
    int n;
    cin >> n; ///Number of data

    ///Entering elements:
    int ara[n+1];
    for(int i = 0; i < n; i++)
        cin >> ara[i];

    my_sort(ara, 0, n-1);

    for(int i = 0; i < n; i++)
        cout << ara[i] << " ";
    cout << endl;
}
