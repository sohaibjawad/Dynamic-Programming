#include <iostream>
#include <algorithm>

using namespace std;

//Dynamic Approach ---- Time Complexity is ~ O(n^2)
int lis_BU(int arr[], int n)
{
    int dp[n];
    for(int i = 0; i < n; i++)
        dp[i] = 1; //every element itself is a LIS of size 1

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int maximum = 0;
    for(int i = 0; i < n; i++)
    {
        if(dp[i] > maximum)
            maximum = dp[i];
    }

    return maximum;
}

int main()
{

    int arr[] = {50,3,10,7,40,80};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << lis_BU(arr,n);

    return 0;
}
