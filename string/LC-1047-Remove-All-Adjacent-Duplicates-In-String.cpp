class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>answer;
        string res;
        char letter,first;
        for(int i = 0 ;i < s.size();i++){
            letter = s[i];
            if(answer.size() == 0){
                answer.push(letter);
                continue;
            } 
            first = answer.top();
            if(first == letter){
                answer.pop();
                continue;
            }
                answer.push(letter);
        }
        while(!answer.empty()){
            res.push_back(answer.top());
            answer.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
