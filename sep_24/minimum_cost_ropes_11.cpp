//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to return the minimum cost of connecting the ropes.
  long long minCost(vector<long long> &arr)
  {
    // Your code here
    // Using priority_queue data structure
    // within O(log N) time complexity

    // defining the priority_queue in a min_heap order
    priority_queue<long long,
                   vector<long long>,
                   greater<long long>>
        memo(arr.begin(), arr.end());

    long long total_cost = 0;

    while (memo.size() > 1)
    {
      // accessing the first smallest ll
      long long first = memo.top();
      memo.pop(); // removing it from the min_heap

      // accessing the second smallest ll
      long long second = memo.top();
      memo.pop(); // removing it from the min_heal

      // taking summation each iteration
      long long current_summation = first + second;
      total_cost += current_summation;

      // pushing the total_cost into the min_heap to
      // access it again
      memo.push(current_summation);
    }

    return total_cost;
  }
};

//{ Driver Code Starts.

int main()
{
  long long t;
  cin >> t;
  cin.ignore();
  while (t--)
  {
    string input;
    long long num;
    vector<long long> a;

    getline(cin, input);
    stringstream s2(input);
    while (s2 >> num)
    {
      a.push_back(num);
    }
    Solution ob;
    cout << ob.minCost(a) << endl;
  }
  return 0;
}

// } Driver Code Ends