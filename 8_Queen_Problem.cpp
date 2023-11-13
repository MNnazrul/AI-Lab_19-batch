#include<bits/stdc++.h>
using namespace std;

int const N = 8, max_initaration = 200;
 
vector<int> genenrateNeighbor(vector<int> &state) {
    vector<int> neighbor = state;
    int id1 = rand() % N, id2 = rand() % N;
    swap(neighbor[id1], neighbor[id2]);
    return neighbor;
}

int conflict(vector<int> &state) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++)
            if(abs(i - j) == abs(state[i] - state[j])) count++;
    }
    return count;
}

vector<int> N_queen(vector<int>& state) {
    vector<int> current_state = state;
    int current_conflict = conflict(state);

    for (int i = 0; i < max_initaration; i++) {
        vector<int> neighbor = genenrateNeighbor(current_state);
        int neighbor_conflict = conflict(neighbor);
        if(neighbor_conflict <= current_conflict) {
            current_state = neighbor;
            current_conflict = neighbor_conflict; 
        }
    }
    
    return current_state;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    srand(time(0));

    vector<int> initial_state(N, 0);

    for (int i = 0; i < N; i++) initial_state[i] = i;

    vector<int> final_state = N_queen(initial_state);

    vector<vector<int>> board(N, vector<int> (N, 0));
    for (int i = 0; i < N; i++) board[i][final_state[i]] = 1;

    for (auto v : board) {
        for (int i : v) cout << i << ' '; 
        cout << endl;
    }

    cout << conflict(final_state) << endl;


    return 0;
}