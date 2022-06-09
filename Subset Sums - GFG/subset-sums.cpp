// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
private:
    vector<int> helper(vector<int> arr, int k, int N) {
        if (k == N) {
            return {0};
        }
        vector<int> smallAns = helper(arr, k+1, N);
        vector<int> ans = smallAns;
        for (int i=0; i<smallAns.size(); i++) {
            ans.push_back(arr[k] + smallAns[i]);
        }
        return ans;
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        return helper(arr, 0, N);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends