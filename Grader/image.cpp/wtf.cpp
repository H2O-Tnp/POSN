#include <iostream>
#include <vector>

using namespace std;

void printMat(const vector<vector<int>> &mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout<<mat[i][j]<<' ';
        }cout<<endl;
    }
}

int convert_image(const vector<vector<int>> &image)
{
    int n = image.size();
    cout<<"convert "<<n<<endl;
    printMat(image);
    // Check for all zeros or ones
    bool all = true;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if(image[i][j]!=image[0][0]){
                all=false;
                break;
            }
        }
        if(!all){
            break;
        }
    }

    // Handle special cases
    if (all){
        return 2;
    }

    // Divide and conquer
    // 1 is divide the mat symbol
    int length = 1;
    //  += n/2 means go to mid of mat every loop
    for (int i = 0; i < n; i += n / 2){
        for (int j = 0; j < n; j += n / 2){
            /// declare half of row and column vector
            vector<vector<int>> sub_image(n / 2, vector<int>(n / 2));
            // put data to to sub_image
            for (int k = 0; k < n / 2; ++k){
                for (int l = 0; l < n / 2; ++l){
                    sub_image[k][l] = image[i + k][j + l];
                }
            }
            // recusive sub image
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
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> image[i][j];
        }
    }
    cout << convert_image(image) << endl;
    return 0;
}

/*
8
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1


*/