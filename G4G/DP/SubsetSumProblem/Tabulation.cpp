// A Dynamic Programming solution
// for subset sum problem
#include <bits/stdc++.h>
using namespace std;
 
// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool dp[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    // Fill the subset table in bottom up manner
    // i represent the "index of set"
    // j represent the "current sum"
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            cerr<<"i "<<i<<" | j "<<j<<"\n";
            cerr<<"set[i-1] = "<<set[i-1]<<"\n";

            if (j < set[i - 1]){
                cerr<<j<<" < "<<set[i - 1]<<"\n";
                //            copy up
                dp[i][j] = dp[i - 1][j];
            }

            // else
            if (j >= set[i - 1])
                dp[i][j]
                    = dp[i - 1][j]
                      || dp[i - 1][j - set[i - 1]];
        }
        cerr<<"\n";
    }
    // deb
    {
        cerr<<"    ";
        for (int j = 0; j <= sum; j++) {
            cerr<<j<<" ";
        }
        cerr<<"\n";
        for (int i = 0; i <= n; i++) {
            if(i==0){
                cerr<<i<<' '<<"- ";
            }
            else cerr<<i<<' '<<set[i-1]<<' ';
            for (int j = 0; j <= sum; j++) {
                cerr<<dp[i][j]<<" ";
            }
            cerr<<"\n";
        }
    }
    // end deb
    return dp[n][sum];
}
 
// Driver code
int main()
{
    // int set[] = { 3, 34, 4, 12, 5, 2 };
    // int sum = 9;
    // int set[] = { 3, 4, 5, 2 };
    int set[] = { 3, 1, 5, 2 };

    int sum = 9;
    
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}
// This code is contributed by shivanisinghss2110

/*
    0 1 2 3 4 5 6 7 8 9
0 - 1 0 0 0 0 0 0 0 0 0
1 3 1 0 0 1 0 0 0 0 0 0 
2 4 1 0 0 1 1 0 0 1 0 0
3 5 1 0 0 1 1 1 0 1 1 1
4 2 1 0 1 1 1 1 1 1 1 1

    0 1 2 3 4 5 6 7 8 9
0 - 1 0 0 0 0 0 0 0 0 0
1 3 1 0 0 1 0 0 0 0 0 0
2 1 1 1 0 1 1 0 0 0 0 0 
3 5 1 1 0 1 1 1 1 0 1 1
4 2 1 1 1 1 1 1 1 1 1 1
*/