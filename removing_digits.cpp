#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[1001000];
int solve(int num)
{
    if(num < 0)
        return INT_MAX;
    if(num == 0)
        return 0;

    if(dp[num]!=-1) return dp[num];

    set<int> dig;
    int copy = num;
    while(copy!=0)
    {
        dig.insert(copy%10);
        copy = copy/10;
    }
    int steps = INT_MAX;
    for(auto k:dig)
    {
        if(k==0) continue;
        int curr = solve(num-k);
        if(curr!=INT_MAX)
            steps = min(steps, 1 + curr);
    }
    return dp[num] = steps;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
    return 0;
}