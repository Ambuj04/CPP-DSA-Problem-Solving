class Solution {
public:
    bool isValid(string s) {
        stack<char>st; //stack use because use of LIFO
        for(int i=0;i<s.size();i++){
            //Opening bracket push into stack
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
                continue;
            }
            //Closing bracker 
            if(st.empty()) return false;
            if(s[i] == ')' && st.top()=='('){
                st.pop();
                continue;
            }else if(s[i] == '}' && st.top()=='{'){
                st.pop();
                continue;
            }else if(s[i] == ']' && st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};