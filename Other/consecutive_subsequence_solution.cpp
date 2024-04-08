#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    //const vector<int> nums = {5, 100, 4, 200, 1, 3, 2, 7, 55, 9, 5, 5 , 7, 100, 99};
  //  const vector<int> nums = {4, -3, 3, 11 ,17, 10 ,5 ,16, 27, 25, 32, 1, 27, 11, 36, -29, -8, -1, -21, 21, -27,
  //  -44, -47 ,-12, -36 ,-14, -34, -29 ,-23, -30,-23, 38, 46 ,31, 0, 22, 23, -15 ,-29, 26, -2 ,3 ,39, 12 ,18, 29,
  //  0 ,-44 ,-24, -35, -11,-16 ,-21 ,-13, -44 ,20, 47, -3, -7, -43 ,-38, 38,-7 ,-32, -26, 20, 7, -11 ,-17 ,-12,};
    //-7 ,-21 ,-6 ,44, 6 ,47, 6 ,-11, -21, 34, 20, -13, 9, -33 ,-43 ,22, 38 ,-28 ,-33, 34, 13, 24, 2, -40, -22 ,-38, -14 ,-29 ,-9 ,-17};

    vector<int> nums;
    int num;

    while (cin >> num) {
        nums.push_back(num);
    }

    map<int, int> counts;
    for (auto num : nums) {
        counts[num]++;
    }
    /*
     for (auto elem : counts) {
          //  cout << "{" << elem.first << ":" << elem.second << "} ";
        }*/
    int max_len = 0;
    int start_num = 0;
    for (auto num_count : counts) {
        int num = num_count.first;
        if (counts.find(num-1) == counts.end()) {
            int len = 0;
            while (counts.find(num) != counts.end()) {
                num++;
                len++;
            }
            if (len > max_len) {
                max_len = len;
                start_num = num - max_len;
                //cout << start_num << " ";
            }
        }
    }
   // cout << endl;

    for (int i = start_num; i < start_num + max_len; i++) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
