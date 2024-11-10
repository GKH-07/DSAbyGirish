//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findSubArraySum(int k, vector<int> &arr) {
        int prefix_sum = 0;
        unordered_map<int,int> freq;
        freq[0]++;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            prefix_sum += arr[i];
            int needed = prefix_sum - k;
            if(freq.find(needed) != freq.end()){
                count+=freq[needed];
            }
            freq[prefix_sum]++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.findSubArraySum(k, arr);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends