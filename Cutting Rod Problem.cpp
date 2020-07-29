#include <iostream>

using namespace std;

//DP Bottom Up Approach
int rodCutting(int lengths[], int profits[], int m, int actualLength)
{
    int dp[m][actualLength+1];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= actualLength; j++)
        {
            if(j == 0 || i == 0)
                dp[i][j] = 0;

            else if(j < lengths[i])
                dp[i][j] = dp[i-1][j];

            else
                dp[i][j] = max(dp[i-1][j], profits[i] + dp[i][j - lengths[i]]);

        }
    }

    return dp[m-1][actualLength];
}

int main()
{

    int lengths[] = {1,2,3,4};
    int profits[] = {2,5,7,8}; //corresponding profits
    int m = sizeof(lengths) / sizeof(lengths[0]);

    int actualLen = 5;

    cout << rodCutting(lengths, profits, m, actualLen);

    return 0;
}
