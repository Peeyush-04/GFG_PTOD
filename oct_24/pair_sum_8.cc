//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  int pairsum(vector<int> &arr)
  {
    // code here
    int largest = INT_MIN, second_largest = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
    {
      if (arr[i] > largest)
      {
        second_largest = largest;
        largest = arr[i];
      }
      else if (arr[i] > second_largest && arr[i] != largest)
      {
        second_largest = arr[i];
      }
    }
    return largest + second_largest;
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
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
      arr.push_back(number);
    }
    int n = arr.size();
    Solution ob;
    int r = ob.pairsum(arr);
    cout << r << endl;
  }
  return 0;
}
// } Driver Code Ends