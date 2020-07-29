#include <iostream>

using namespace std;

int minimum(int a, int b, int c)
{
    return min(min(a,b),c);
}

//Bottom Up DP Approach ---- Time Complexity O(m * n)
int minEdit(string a, string b)
{
    int m = a.length();
    int n = b.length();

    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = j;

            else if(j == 0)
                dp[i][j] = i;

            else if(a[i-1] != b[j-1])
                dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j-1], dp[i-1][j]);

            else
                dp[i][j] = dp[i-1][j-1];
        }
    }

    return dp[m][n];
}


int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << minEdit(str1, str2);

    return 0;
}
