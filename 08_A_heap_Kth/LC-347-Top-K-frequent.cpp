struct cmp{
bool operator()(pair<int,int>&a,pair<int,int>&b){
    if(a.second != b.second){
        //second strore frequency
        return a.second > b.second;
    }
    if(a.first != b.first){
        return a.first > b.first;
    }
    return false;
}

};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq; //frequency table
        vector<int>res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(auto num:nums){
            freq[num]++;
        }
        //make pairs for frequency table
        for(auto singlePair:freq){
            if(pq.size() < k){
                pq.push(singlePair);
                continue;
            }
            if(singlePair.second > pq.top().second){
                pq.pop();
                pq.push(singlePair);
            }

        }
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
    return res;
    }
};