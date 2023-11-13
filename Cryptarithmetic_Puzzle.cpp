#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;

int main()
{
    cin >> s1 >> s2 >> s3;
    set<char> st;
    vector<int> pos(30, 0);
    for (char ch : s1)
        st.insert(ch);
    for (char ch : s2)
        st.insert(ch);
    for (char ch : s3)
        st.insert(ch);
    int i1 = 0;
    for (char ch : st)
        pos[ch - 'a'] = i1++;
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (char ch : st)
        cout << ch;
    cout << endl;

    do
    {
        int c = 0;
        bool f = true;
        int n1 = 0, n2 = 0, n3 = 0;
        for (char ch : s1)
            n1 = n1 * 10 + a[pos[ch - 'a']];
        for (char ch : s2)
            n2 = n2 * 10 + a[pos[ch - 'a']];
        for (char ch : s3)
            n3 = n3 * 10 + a[pos[ch - 'a']];

        if (n1 + n2 == n3)
        {
            for (char ch : st)
            {
                cout << ch << " " << a[pos[ch - 'a']] << endl;
            }
            for (char ch : s1)
                cout << a[pos[ch - 'a']];
            cout << endl;
            for (char ch : s2)
                cout << a[pos[ch - 'a']];
            cout << endl;
            for (char ch : s3)
                cout << a[pos[ch - 'a']];
            cout << endl;
            break;
        }

    } while (next_permutation(a.begin(), a.end()));

    return 0;
}