#include <iostream>
#include <vector>

using namespace std;

int max(int num1, int num2)
{
    return (num1 > num2)? num1: num2;
}

/*
    Recursive Naive Approach ---- Time Complexity O(2^n)
*/
int knapSack(int maxWeight, vector<int> weights, vector<int> values, int n)
{
    if(n == 0 || maxWeight == 0)
        return 0; // You can not add anything in the knapsack if there are no elements to add or the maxWeight is 0.

    if(weights[n-1] > maxWeight)
        return knapSack(maxWeight, weights, values, n-1); //leave the last element if it's weight > maxWeight

    else
    {
        return max(
                    values[n-1] + knapSack(maxWeight - weights[n-1], weights, values, n-1), //nth item gets selected
                    knapSack(maxWeight, weights, values, n-1) //nth item does not get selected
                );
    }
}

/*
    Bottom-up Approach ---- Time Complexity O(n*weights)
*/

int knapSack_BU(int maxWeight, vector<int> weights, vector<int> values, int n)
{
    int T[n+1][maxWeight+1];

    for(int item = 0; item <= n; item++)
    {
        for(int weight = 0; weight <= maxWeight; weight++)
        {
            if(item == 0 || weight == 0)
                T[item][weight] = 0;

            else if(weights[item-1] <= weight)
                T[item][weight] = max(
                                      values[item-1] + T[item-1][weight - weights[item-1]],
                                      T[item-1][weight]
                                      );

            else
                T[item][weight] = T[item-1][weight];

        }
    }

    return T[n][maxWeight];
}

/*
    Top-down Memoization Technique ---- Time Complexity O(n*weights)
*/

int knapSack_MEMO(int maxWeight, vector<int> weights, vector<int> values, int n, int** dp)

{
    if(n == 0 || maxWeight == 0)
        return 0; // You can not add anything in the knapsack if there are no elements to add or the maxWeight is 0.

    if(dp[n][maxWeight] != -1)
        return dp[n][maxWeight];

    if(weights[n-1] > maxWeight)
        return dp[n][maxWeight] = knapSack(maxWeight, weights, values, n-1); //leave the last element if it's weight > maxWeight

    else
    {
        return dp[n][maxWeight] = max(
                                    values[n-1] + knapSack(maxWeight - weights[n-1], weights, values, n-1), //nth item gets selected
                                    knapSack(maxWeight, weights, values, n-1) //nth item does not get selected
                                );
    }
}



int main()
{
    vector<int> weights {10, 20, 30}; //These have to been in ascending order. If not, sort it and change values vector accordingly
    vector<int> values {60, 100, 120};

    int maxWeight = 50; // Capacity of knapsack
    int n = sizeof(weights) / sizeof(weights[0]); //number of elements

    cout << "Naive Approach: " << knapSack(maxWeight, weights, values, n) << endl;;

    cout << "Bottom Up DP Approach: " << knapSack_BU(maxWeight, weights, values, n) << endl;

    int** dp = new int*[n+1];

    for (int i = 0; i <= n; i++)
        dp[i] = new int[maxWeight + 1]; //note that d[i] itself is a pointer

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= maxWeight; j++)
            dp[i][j] = -1;


    cout << "Top Down DP Approach: " << knapSack_MEMO(maxWeight, weights, values, n, dp) << endl;

    return 0;
}
