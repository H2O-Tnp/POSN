#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Number {
public:
    int val;
    int pos;

    Number(int val, int pos) {
        this->val = val;
        this->pos = pos;
    }
};

struct Comparator {
    bool operator()(const Number& n1, const Number& n2) {
        return n1.val < n2.val;
    }
};

void printData(vector<Number>& vec);

int main() {
    //printf("%d %d %d %d\n", abs(5), abs(1 - 7), max(-1, 2), max(2, -1));
    int N, val;
    scanf("%d", &N);
    vector<Number> vec;
    vec.reserve(N+10);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &val);
        vec.push_back(Number(val, i));
    }

    std::sort(vec.begin(), vec.end(), Comparator());
    // printData(vec);
    vec.push_back(Number(-2, -1)); // This is a 'sentinel' to make last element handling easier.

    int current = -1;
    int max_i = -1;
    int min_i = INT_MAX;
    int max_pos = -1;
    int min_pos = INT_MAX;
    for(int i = 0; i < N; ++i) {
        Number num = vec.at(i);
        if(num.val != current) {
            current = num.val;
            min_i = max_i = i;
            min_pos = max_pos = num.pos;
        } else {
            max_i = i;
            min_pos = min(num.pos, min_pos);
            max_pos = max(num.pos, max_pos);
        }

        if(vec.at(i+1).val != current) { // summarize disposition
            int diff1 = abs(min_i - max_pos);
            int diff2 = abs(max_i - min_pos);
            printf("%d %d\n", current, max(diff1, diff2));
        }
    }
}

void printData(vector<Number>& vec) {
    for(Number& n: vec)
        printf("%d ", n.val);
    printf("\n");
}

/**
12
4 3 2 1 5 1 2 1 3 6 5 4

1 7
2 3
3 5
4 8
5 6
6 2

================
10
1 1 1 1 3 3 2 2 2 2

1 3
2 5
3 5

================
9
9 8 7 6 5 4 3 2 1

1 8
2 6
3 4
4 2
5 0
6 2
7 4
8 6
9 8
*/
