#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define int long long
#define endl "\n"
#define vi vector<int>
#define pb push_back
#define size(a) (int)a.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define bp(x) __builtin_popcountll(x)
int const N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18;

int ax[] = {1, -1, 0, 0};
int ay[] = {0, 0, 1, -1};
 
void solve() {
    // freopen("input.txt", "r", stdin);
    
    ifstream input;
    input.open("input.txt");

    string s, ss = "";

    map<string, string> keywords;
    keywords["you"] = "my";
    keywords["your"] = "your";

    vector<string> sentences[103];
    int i1 = 0;
    while(input >> s) {
        int n = size(s);
        sentences[i1].pb(s);
        if(s[n-1] == '.')
            i1++;
    }

    // cin >> s;

    // while(1) {
        string s1;
        getline(cin, s1);
        cout << s1 << endl;   
    //     getline(cin, s1); 
    //     getline(cin, s1); 
    // // }

}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TestCase = 1;
    // cin >> TestCase;  
    while(TestCase--)
        solve();


    // string s; cin >> s;

    return 0;
}
