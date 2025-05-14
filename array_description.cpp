#include<bits/stdc++.h>
using namespace std;

vector<int> x;
int n, m;
int dp[100100][110];
int mod = 1e9 +7;

int solve(int  i, int last)
{
    if(i == n)
        return 1;
    
    if(dp[i][last]!=-1) 
        return dp[i][last];
    
    int ans = 0;
    if(x[i] == 0)
    {
        for(int j=max(1, last-1); j<=min(m, last+1); j++)
        {
            (ans+=solve(i+1, j)) %= mod;
        }
    }
    // x[i] is non zero but it should be compatible with last
    else if(abs(x[i] - last) <= 1)
        (ans+=solve(i+1, x[i])) %= mod;
    
    return dp[i][last] = ans;
}

int main()
{
    cin >> n >> m;
    x.resize(n);

    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }

    if(n == 1 && x[0]!=0)
    {
        cout << "1";
        return 0;
    }
    if(n == 1 && x[0]==0)
    {
        cout << m;
        return 0;
    }
    // all 0's can be together too
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    if(x[0]!=0)
        cout << solve(1, x[0]);
    else
    {
        for(int i=1; i<=m; i++)
        {
            x[0] = i;
            (ans+=solve(1, i)) %= mod;
        }
        cout << ans;
    }
    return 0;
}