class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        string res = "";
        stack<pair<char,int>>st;
        for(int i = 0 ; i<n;i++){
            char c = s[i];
            if(st.empty()){
                //if stack is empty then push (char,1) char occurs 1 time continue
                st.push(make_pair(c,1));
                continue;
            }
            if(s[i] == st.top().first){
              if(st.top().second == k-1){
                st.pop();
                continue;
              }
              st.top().second++;
            }else{
                st.push(make_pair(c,1));
            }
        }
        //iterate stacks pair into string
        while(!st.empty()){
            char ch = st.top().first;
            int freq = st.top().second;
            res.append(freq,ch);//push ch freq times
            st.pop();
        }
        //reverse the sting
        reverse(res.begin(),res.end());
        return res;
    }
};