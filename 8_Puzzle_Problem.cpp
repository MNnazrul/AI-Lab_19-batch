#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vvi vector<vector<int>> 

vvi initial_state, final_state;

int ax[] = {0, 0, 1, -1};
int ay[] = {1, -1, 0, 0};

int heuristic(vvi& state) {
    int cnt = 0;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cnt += (state[i][j] != final_state[i][j]);

    return cnt;
}

pair<int, int> currentPos(vvi &state) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if(state[i][j] == 0) return make_pair(i, j);
}

bool is_valid(int x, int y) {
    return (x < 3 and y < 3 and x >= 0 and y >= 0);
}

void printS(vvi &ss) {
    for (auto v : ss) {
        for (int  i: v) cout << i << ' '; cout << endl;
    }
}

void solvePuzzle() {
    
    map<vvi, bool> vis;
    map<vvi, vvi> parent;
    vis[initial_state] = true;
    set<pair<int, vvi>> st;
    st.insert({heuristic(initial_state), initial_state});

    while(!st.empty()) {
        auto[cur_cost, cur_state] = *st.begin();
        st.erase(st.begin());

        auto[x, y] = currentPos(cur_state);

        vis[cur_state] = true;

        bool f = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                if(cur_state[i][j] != final_state[i][j]) f = false;
        }
        if(f) {
            cout << "found" << endl;
            break;
        }


        for (int i = 0; i < 4; i++) {
            int x1 = x + ax[i], y1 = y + ay[i];
            if(is_valid(x1, y1)) {
                vvi state = cur_state;
                swap(state[x][y], state[x1][y1]);
                if(!vis[state])  {
                    vis[state] = true;
                    parent[state] = cur_state;
                    st.insert({heuristic(state), state});
                }
            }
        }
    }


    vector<vvi> path;
    vvi state = final_state;
    while(state != initial_state) {
        path.push_back(state);
        state = parent[state];
    }


    path.push_back(initial_state);

    cout << path.size() << endl;

    reverse(path.begin(), path.end());

    for (auto v : path) {
        printS(v);
        cout << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    initial_state.assign(3, vector<int> (3, 0));
    final_state.assign(3, vector<int> (3, 0));

    initial_state =  {{1, 2, 3},{5, 6, 0},{7, 8, 4}};
    // final_state = {{1, 2, 3},{4, 5, 6},{7, 0, 8}};
    final_state = {{1, 2, 3},{4, 5, 6},{7, 8, 0}};

    // for (int i = 0; i < 3; i++)
    //     for (int j = 0; j < 3; j++)
    //         cin >> final_state[i][j];


    solvePuzzle();


    return 0;
}

// Define the goal state for the 8-puzzle
// const vector<vector<int>> GOAL_STATE = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
//     vector<vector<int>> initial = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}; // Initial state (example)
// vector<vector<int>> initial = {{1, 2, 3}, {4, 6, 0}, {7, 5, 8}};
