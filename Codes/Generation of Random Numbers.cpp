#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "How many numbers do you generate? : ";
    cin >> n;
    freopen("G:\Random Numbers.txt", "w", stdout);
    srand(time(0));
    for(int i = 0; i < n; i++){
        int temp = (rand() % 10001) * 10000;
        temp += 10000+(rand() % 1000);
        if(i & 1) temp *= -1;
        cout << temp << endl;
    }
}
