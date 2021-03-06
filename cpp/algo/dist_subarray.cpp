#include<bits/stdc++.h>
using namespace std;

// Function to calculate distinct sub-array
int countDistictSubarray(int arr[], int n)
{
    // Count distinct elements in whole array
    unordered_map<int, int>  vis;
    for (int i = 0; i < n; ++i)
        vis[arr[i]] = 1;
    int k = vis.size();
    cout << "k is " << k << endl;

    // Reset the container by removing all elements
    vis.clear();

    // Use sliding window concept to find
    // count of subarrays having k distinct
    // elements.
    int ans = 0, right = 0, window = 0; // 1 2 2 1 1 => 8
    for (int left = 0; left < n; ++left)
    {
        while (right < n && window < k) // n is 5 and k = 2
        {
            ++vis[ arr[right] ];   //vis[1] = 1 && vis[2] = 1

            if (vis[ arr[right] ] == 1)
                ++window;

            ++right;
        }

        // If window size equals to array distinct
        // element size, then update answer
        if (window == k)
            ans += (n - right + 1);

        // Decrease the frequency of previous element
        // for next sliding window
        --vis[ arr[left] ];

        // If frequency is zero then decrease the
        // window size
        if (vis[ arr[left] ] == 0)
                --window;
    }
    return ans;
}

// Driver code
int main()
{
    //int arr[] = {2, 1, 3, 2, 3};
    int arr[] = {1, 2, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countDistictSubarray(arr, n) <<" n";
    return 0;
}
