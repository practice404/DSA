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
    unordered_map<char,int> mp = {{'[',-1},{'{',-2},{'(',-3},{'|',-4},{']',1},{'}',2},{')',3}};
    stack<int> st;
    vector<int> v;

    for(auto c : s)
        v.push_back(mp[c]);


    for(auto i : v)
    {
        if ( i < 0 && i != -4)
            st.push(i);
        else if (i < 0 && i == -4)
        {
            if(st.empty())
                st.push(i);
            else
            {
                int top = st.top();
                if (top == -4)
                    st.pop();
                else
                {
                    st.push(i);
                }
            }
        }
        else
        {
            if (st.empty())
                return false;
            int top = st.top();
            if(top + i != 0)
                return false;
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
