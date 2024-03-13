#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0, arr[5];
    for (int i = 0; i < 5; ++i)
    {
        cin >> arr[i];
    }
    for (auto i : arr)
    {
        sum += i;
    }
    cout << sum;
}