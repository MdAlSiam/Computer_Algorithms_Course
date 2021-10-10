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

int main(){
    int n;
    cin >> n; ///Number of data
    
    ///Entering elements:
    int ara[n+1];
    for(int i = 0; i < n; i++)
        cin >> ara[i];

    int target_pos;
    cin >> target_pos; ///Position of the element
                        ///that's to be placed correctly

    int temp = ara[target_pos];

    int ans = find_correct_position(ara, target_pos, n-1);

    cout << "The correct position for " << temp
        << " is " << ans << endl;

}
