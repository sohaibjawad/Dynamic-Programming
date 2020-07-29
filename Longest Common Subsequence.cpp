#include <iostream>
#include <math.h>

using namespace std;

//Dynamic Programming Approach
int lcs_BU(string a, string b, int size_a, int size_b)
{
    int dp[size_a+1][size_b+1];

    /*dp[i][j] contains length of LCS of a[0..i-1] and b[0..j-1] */

    for(int i = 0; i < size_a+1; i++)
    {
        for(int j = 0; j < size_b+1; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[size_a][size_b];
}

int main()
{
    string a = "AGGTAB";
    string b = "GXTXAYB";
    int size_a = a.length();
    int size_b = b.length();

    cout << lcs_BU(a,b,size_a,size_b) << endl;

    return 0;
}
