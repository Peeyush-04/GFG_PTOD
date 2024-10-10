//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int maxDistance(vector<int> &arr)
  {
    int size = arr.size();
    map<int, vector<int>> memo;

    for (int i = 0; i < size; ++i)
    {
      memo[arr[i]].push_back(i);
    }

    int max_distance = INT_MIN;

    for (auto &i : memo)
    {
      int diff = i.second.back() - i.second.front();
      max_distance = max(max_distance, diff);
    }

    return max_distance;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  cin.ignore();
  while (t--)
  {
    vector<int> arr;
    string input;
    getline(cin, input);

    stringstream s1(input);
    int num;
    while (s1 >> num)
    {
      arr.push_back(num);
    }

    Solution ob;
    cout << ob.maxDistance(arr) << endl;
  }
  return 0;
}
// } Driver Code Ends