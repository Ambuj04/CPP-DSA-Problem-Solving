class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>magFreq;
        for(auto c:magazine){
            magFreq[c]++;
        }
        for(auto c:ransomNote){
            magFreq[c]--;
            if(magFreq[c]<0){
                return false;
            }
        }
        return true;
    }
};