class Solution {
  public:
  
  bool solve(string& s,int low,int high){
      int len = high-low+1;
      if(len == 0 || len == 1) return true;
      if(s[high]!=s[low]) return false;
      return  solve(s,low+1,high-1);
          
      
      
  }
    bool isPalindrome(string& s) {
       int low = 0;
       int high  = s.length() -1 ;
       return solve(s,low,high);
        
    }
};