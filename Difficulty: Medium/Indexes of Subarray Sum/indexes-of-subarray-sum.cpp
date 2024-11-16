//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int s) {
    long long sum = 0;
    int start = 0;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {
        // Add the current element to the sum.
        sum += arr[i];

        // Shrink the window from the left as long as the sum is greater than s.
        while (sum > s && start <= i) {
            sum -= arr[start];
            start++;
        }

        // Check if we found the subarray with the desired sum.
        if (sum == s) {
            ans.push_back(start + 1); // +1 for 1-based indexing
            ans.push_back(i + 1);    // +1 for 1-based indexing
            return ans;
        }
    }

    // If no subarray is found, return {-1}.
    return {-1};
}


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends