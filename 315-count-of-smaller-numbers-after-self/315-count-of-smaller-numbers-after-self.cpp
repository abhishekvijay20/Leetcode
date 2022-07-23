class Solution {
private:
    void merge(vector<pair<int, int>>&v, vector<int>& counts, int l, int m, int r) {
        vector<pair<int, int>> temp(r-l+1);
        int i = l, j = m+1, k = 0;
        
        while (i <= m && j <= r) {
            if (v[i].first <= v[j].first) {
                temp[k++] = v[j++];
            } else {
                counts[v[i].second] += r-j+1;
                temp[k++] =  v[i++];
            }
        }
        
        while (i <= m) {
            temp[k++] = v[i++];
        }
        while (j <= r) {
            temp[k++] = v[j++];
        }
        
        for (int i=l; i<=r; i++) {
            v[i] = temp[i-l];
        }
    }
    void mergeSort(vector<int>& counts, vector<pair<int, int>>& v, int l, int r) {
        if (l < r) {
            int mid = l + (r-l)/2;
            mergeSort(counts, v, l, mid);
            mergeSort(counts, v, mid+1, r);
            merge(v, counts, l, mid, r);            
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i=0; i<n; i++) {
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        vector<int> counts(n, 0);
        mergeSort(counts, v, 0, n-1);
        return counts;
    }
};