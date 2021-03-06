#include <bits/stdc++.h>
using namespace std;

int adj[6][6];

int visited[6] = {0};

void makematrix(){
    memset(adj, 0, sizeof (adj));
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = adj[2][4] = adj[2][5] = 1;
    adj[3][0] = 1;
    adj[5][0] = 1;
}

void printmatrix(){
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            printf(j == 5 ? "%d\n" : "%d ", adj[i][j]);
}

void checkfrom(int source){

    stack <int> st;

    st.push(source);

    visited[source] = 1;

    while(!st.empty()){
        int u = st.top();
        st.pop();

        for(int i = 0; i < 6; i++){
            if(adj[u][i] == 1){
                cout << u << "->" << i << "\n";
                visited[i]++;
                if(visited[i] <= 1) st.push(i);
            }
        }
    }
    
    cout << endl;
}

int main(){
    makematrix();
    printmatrix();

    int n;

    cout << "Enter source: ";
    cin >> n;

    checkfrom(n);

    cout << "Visit Status:\n";
    for(int i = 0; i < 6; i++)
        printf(i == 5 ? "%d\n" : "%d ", visited[i]);

    if(visited[n] > 1) printf("Possible to get back\n");
    else printf("Not Possible to get back\n");

}
