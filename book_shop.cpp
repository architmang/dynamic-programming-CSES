#include<bits/stdc++.h>
using namespace std;

// int dp[1010][100100]; 
//1E8 Storage gives TLE
// if recursive gives TLE shift to terative

int x, n;
vector<int> h, s;

int main()
{
    // number, max_price
    cin >> n >> x;
    vector<vector<int> > dp(n+1, vector<int>(x+1, 0));
    h.resize(n);
    s.resize(n);    
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++) cin >> s[i];

    for(int i=1; i<=n; i++)                       
    {
        for(int price=0; price<=x; price++)   
        {
            dp[i][price] = dp[i-1][price]; // dont take last one
            int curr = price - h[i-1];
            if(curr >= 0)
                dp[i][price] = max(dp[i-1][price], dp[i-1][curr] + s[i-1]);
        }
    }
    cout << dp[n][x];
    return 0;
}