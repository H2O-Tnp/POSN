#include <iostream> 
#include <vector>
using namespace std;

void print(vector <long long> &A, int i, int N) {
    if (i == N) return;
    cout << A[i] << ' ';
    print(A, i + 1, N);
}

long long get_sum(vector <long long> &A, int l, int r) {
    if (l - 1 == r) return 0;
    return A[l] + get_sum(A, l + 1, r);
}

void solve(vector <long long> &A, int N, int K) {
    print(A, 0, N);
    cout << '\n';
    if (N > 1) {
        A[max(0, N - K - 1)] += get_sum(A, max(1, N - K), N - 1);
        solve(A, max(1, N - K), K);
    }
}
 
int main() 
{ 
    vector <long long> A; //ตัวแปรสําหรับเก็บชุดตัวเลข 
    int K; 
    cin >> K; 
    int input = 0; 
    while (true){ 
        cin >> input; 
        if (input == -1) 
            break; 
        else 
            A.push_back(input);
    }
    solve(A, A.size(), K);
    return 0; 
} 