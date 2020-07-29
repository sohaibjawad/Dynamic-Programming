#include <iostream>

using namespace std;

int subsetSum(int arr[], int n, int sum)
{
    bool DP[n+1][sum+1];

    for(int row = 0; row <= n; row++)
    {
        for(int col = 0; col <= sum; col++)
        {
            if(col == 0)
            {
                DP[row][col] = true;
            }

            else if(row == 0 && col > 0)
                DP[row][col] = false;

            else if(col < arr[row-1]) //if sum is less than the biggest value in subset
                DP[row][col] = DP[row-1][col];

            else
            {
                if(DP[row-1][col] == true)
                    DP[row][col] = true;

                else
                    DP[row][col] = DP[row - 1][col - arr[row-1]];
            }

        }
    }

    return DP[n][sum];
}

int main()
{

    int arr[] = {2,3,7,8,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 15;

    if(subsetSum(arr,n,sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
