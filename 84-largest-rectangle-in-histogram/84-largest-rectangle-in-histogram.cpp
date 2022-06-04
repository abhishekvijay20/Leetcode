class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i=n-1; i>=0; i--) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i=0; i<n; i++) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = prevSmallerElement(heights);
        
        int maxArea = INT_MIN;
        for (int i=0; i<n; i++) {
            if (next[i] == -1) next[i] = n;
            int w = next[i] - prev[i] - 1;
            int area = heights[i]*w;
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
};