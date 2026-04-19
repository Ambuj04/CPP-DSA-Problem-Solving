class Solution {
  public:
    int countBitsFlip(int a, int b) {
       int ans = a^b;
        //count no of set bit in ans
        int cnt = 0;
        for(int i = 0;i<32;i++){
            if(ans & (1<<i)) cnt++;
        }
        return cnt;
    }
};