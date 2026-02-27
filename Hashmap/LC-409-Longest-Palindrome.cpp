class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        int len = 0;
        bool oddIncluded = false;
        for(char c:s){
            freq[c]++;
        }
        for(auto p:freq){
            if(p.second%2 == 0){
                //even frequency (all even freq used in palindrome)
               len += p.second;
            }else{
                //odd frequency (we also make palindrome from odd with freq-1)
                len += p.second-1;
                oddIncluded = true;
            }
        }
        //if odd number included then we also add the 1 in lenght because of middle charachter by odd number frequency
        return oddIncluded == true ? len+1 : len;
    }
};