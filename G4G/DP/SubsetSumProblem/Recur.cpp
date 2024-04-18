// A recursive solution for subset sum problem
#include <iostream>
using namespace std;


// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum, int dep)
{
    // int set[] = { 3, 34, 4, 12, 5, 2 };
    cerr<<"depth "<<dep<<"\n";
    cerr<<"("<<n<<", "<<sum<<")\n";
    dep++;
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    //
    // for tabulation
    //   set[i-1]  >  j
    if (set[n - 1] > sum){
        cerr<<"greater -> ignore\n";
        // skip
        return isSubsetSum(set, n - 1, sum, dep);
    }

    /* else, check if sum can be obtained by any 
       of the following:
       (a) including the last element
       (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum, dep)
           || isSubsetSum(set, n - 1, sum - set[n - 1], dep);
}

// Driver code
int main()
{
    int dep = 1;

    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum, dep) == true)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}

// This code is contributed by shivanisinghss2110