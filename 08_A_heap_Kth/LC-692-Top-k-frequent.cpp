struct cmp{
    bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first == b.first){
             return a.second < b.second;
        }
            return a.first > b.first;
     
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        vector<string>res;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto str:words){
            freq[str]++;
        }
        for(auto singlePair:freq){
            string str = singlePair.first;
            int frequency = singlePair.second;

            if(pq.size() < k){
                pq.push({frequency,str});
                continue;
            }
           if( frequency > pq.top().first || 
   (frequency == pq.top().first && str < pq.top().second)){
    pq.pop();
    pq.push({frequency,str});
}
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};