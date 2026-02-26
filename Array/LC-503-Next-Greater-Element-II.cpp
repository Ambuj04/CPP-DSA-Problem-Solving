class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int tempNum;
        stack<int> st;
        vector<int>ans(n,-1);
        for (int i = n - 1; i >= 0; i--) {
            // n n-1 n-2 .... 0 (0 gain first chance )
            st.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (st.empty()){
                st.push(nums[i]); 
            }else{
                ans[i] = st.top();
        }
            st.push(nums[i]);
        }
        return ans;
    }
};