class Solution {
  public:
    int setBits(int n) {
        int cnt = 0;
        while(n>=1){
            cnt += n&1;
            n = n>>1;//remove last bit by rightshift
        }
        return cnt;
    }
};