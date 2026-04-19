class Solution {
  public:
    void bitManipulation(int num, int i) {
        //for get
        int get;
        if(num & (1<<i-1)){
            get = 1;
        }else{
            get = 0;
        };
        //for set
        int set = num | (1<<i-1);
        //for clear
        int clear = num & ~(1<<i-1);
        cout<<get<<" "<<set<<" "<<clear;
    }
};