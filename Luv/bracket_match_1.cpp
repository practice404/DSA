#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define PRIME           1000000007
#define w(t)            int t; cin>>t; while(t--)


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

bool check_valid(string s)
{
    unordered_map<char,int> mp = {{'(',-1}, {'[',-2}, {'{',-3},{')',1},{']',2},{'}',3}};
    stack<char> st;

    for(auto c : s)
    {
        if (mp[c] < 0)
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            char top_char = st.top();
            int top = mp[top_char];
            if (top + mp[c] != 0)
                return false;
            else
                st.pop();
        }
    }

    if(st.empty())
        return true;
    else
        return false;

}

int main()
{
    c_p_c();

    w(t)
    {
        string s;
        cin >> s;
        cout << check_valid(s)<<endl;
    }
    
}
