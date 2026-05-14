class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi,heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi,heights[element] * (nse - pse - 1));
        }
        return maxi;
    }
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;
        vector<int>dp(m,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==1){
                    dp[j]++;
                }else{
                    dp[j] = 0;
                }
                
            }
            maxi = max(maxi,largestRectangleArea(dp));
        }
        return maxi;
    }
};