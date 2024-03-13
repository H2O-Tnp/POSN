#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "How Many Numbers You Want to Enter?" << endl;
    int N;
    cin >> N;
    int arr[N];
    cout << "Enter " << N << " Numbers:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << "Arithnetic Mean " << arr[N / 2 - 1];
}