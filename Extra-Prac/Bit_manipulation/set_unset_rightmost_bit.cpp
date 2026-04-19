class Solution {
  public:
    void solve(int n) {
       int set = (n | (n+1));
       int unset = (n & (n-1));
       cout<<set<<" "<<unset;
    }
};