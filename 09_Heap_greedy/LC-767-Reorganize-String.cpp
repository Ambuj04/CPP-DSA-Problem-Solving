class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;//maxHeap
        unordered_map<char,int>freq;
        string res = "";
        int seat = 0;
        for(auto ch:s){
            freq[ch]++;
        }
        //push freq data into hashmap
         for(auto singlePair:freq){
            int frequency = singlePair.second;
            char ch = singlePair.first;
            pq.push({frequency,ch});
         }
         while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();

            if(seat == 0 || res[seat-1] != p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first > 0){
                    pq.push(p);
                }

            }else{

            if(pq.empty()) return "";
             pair<int,char> other_p = pq.top();
             pq.pop();
             res.push_back(other_p.second);
                seat++;
                other_p.first--;
                if(other_p.first > 0){
                    pq.push(other_p);
                }
             pq.push(p);

            }
         }
         return res;
    }
};