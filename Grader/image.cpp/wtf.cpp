#include <iostream>
#include <vector>

using namespace std;

int convert_image(const vector<vector<int>> &image)
{
    int n = image.size();
    // Check for all zeros or ones
    bool all = true;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if(image[i][j]!=image[0][0]){
                all=false;
            }
        }
    }

    // Handle special cases
    if (all){
        return 2;
    }

    // Divide and conquer
    int length = 1;
    for (int i = 0; i < n; i += n / 2)
    {
        for (int j = 0; j < n; j += n / 2)
        {
            vector<vector<int>> sub_image(n / 2, vector<int>(n / 2));
            for (int k = 0; k < n / 2; ++k)
            {
                for (int l = 0; l < n / 2; ++l)
                {
                    sub_image[k][l] = image[i + k][j + l];
                }
            }
            length += convert_image(sub_image);
        }
    }

    return length;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> image(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> image[i][j];
        }
    }

    cout << convert_image(image) << endl;

    return 0;
}