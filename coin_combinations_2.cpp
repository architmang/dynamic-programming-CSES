#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int x, n;
    cin >> n >> x;
    vector<int> c(n);

    ll mod = 1e9+7;
    vector<vector<ll>> dp(n+1, vector<ll>(x+1, 0));
    for(int i=0; i<n; i++)
    {
        cin >> c[i];
    }
    for(int i=0; i<=n; i++)
            dp[i][0] = 1;   // sum 0 means exactly one way

    for(int i=1; i<=n; i++)
    {
        for(int sum=0; sum<=x; sum++)
        {
            // dont take
            dp[i][sum] = dp[i-1][sum];

            //take, can repeat
            int new_sum = sum - c[i-1];
            if(new_sum >= 0)
                (dp[i][sum] += dp[i][new_sum] ) %= mod;
        }
    }

    cout << dp[n][x];
    return 0;
}