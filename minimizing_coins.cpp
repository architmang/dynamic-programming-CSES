#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1000100];
vector<int> c;
int x, n;

ll cnt(int sum)
{
    if(sum < 0) return INT_MAX;
    if(sum == 0) return 0;
    if(dp[sum]!=-1) return dp[sum];
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
    {
        // for this case: 1 + cnt(sum-c[i]);
        int curr = cnt(sum-c[i]);
        if(curr!=INT_MAX) curr++;
        ans = min(ans, curr);
    }
    return dp[sum] = ans;
}

int main()
{
    cin >> n >> x;
    c.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> c[i];
    }
    memset(dp, -1, sizeof(dp));
    if(cnt(x) == INT_MAX)
        cout << "-1";
    else 
        cout << cnt(x);
    return 0;
}