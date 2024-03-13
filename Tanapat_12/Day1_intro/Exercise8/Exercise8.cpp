#include <iostream>
using namespace std;
int main()
{
    cout << "How Many Elements You Want to Store into an Array?" << endl;
    int N;
    cin >> N;
    int arr[N];
    cout << "Enter " << N << " Elements to Store into an Array :" << endl;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << "The Elements in the Array are :" << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
}