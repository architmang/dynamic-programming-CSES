#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int mod  = 1e9+7;
ll dp[1000100];

ll cnt(int n)
{
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n]!=-1) return dp[n];
    ll ans = 0;
    for(int k=1; k<=6; k++)
    {
        ans+=cnt(n-k);
        ans=ans%mod;
    }
    return dp[n] = ans%mod;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << cnt(n) % mod;
    return 0;
}