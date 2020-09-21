#include <iostream>
#include <vector>
using namespace std;
int maxIndexDiff(vector<int> v1, vector<int> v2)
{
    int n = 0;
    int maxDiff = -1;
    int i, j;
    n = v1.size();
    cout << n << endl;
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (v2[j] > v1[i])
            {
              cout << "j : " << j << " : v2[j] " << v2[j] << endl;
              cout << "i : " << i << " : v1[i] " << v1[i] <<endl;
            }


            if (v2[j] > v1[i] && maxDiff < (j - i))
                maxDiff = j - i;
                cout << "maxidff  " << maxDiff << endl;
        }
    }

    return maxDiff;
}

int main()
{
    vector<int> v1;
    vector<int> v2;
    v1.push_back(7);
    v1.push_back(7);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(1);

    v2.push_back(8);
    v2.push_back(8);
    v2.push_back(7);
    v2.push_back(7);
    v2.push_back(5);
    v2.push_back(5);
    v2.push_back(4);
    v2.push_back(3);
    v2.push_back(2);


    //int arr[] = { 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = maxIndexDiff(v1, v2);
    cout << "\n"
         << maxDiff;
    return 0;
}
