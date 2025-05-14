#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9+7;

ll dp[1000100];
vector<int> c;
int x, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    c.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> c[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int sum;
    for(sum=1; sum<=x; sum++)
    {
        for(int i=0; i<n; i++)
        {
            if(sum - c[i] >= 0)
                dp[sum] += dp[sum - c[i]];
        }
        dp[sum] %= mod;
    }

    cout << dp[x];
    return 0;
}