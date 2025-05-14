#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
int dp[1001][1001];
int n;

bool valid(vector<vector<char>> &grid, int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<n)
    {
        if(grid[i][j] == '.')
            return true;
        else return false;
    }
    else return false;
}

int solve(vector<vector<char>> &grid, int i, int j)
{
    if(i==0 && j==0 && valid(grid, i, j)) return 1;
    if(i==0 && j==0 && !valid(grid, i, j)) return 0;

    if(!valid(grid, i, j))
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans = 0;
    if(valid(grid, i-1, j)) ans+=solve(grid, i-1, j);
    if(valid(grid, i, j-1)) (ans+=solve(grid, i, j-1)) %= mod;

    return dp[i][j] = ans % mod;
}

int main()
{
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(grid, n-1, n-1);
    return 0;
}