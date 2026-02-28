class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
       stack<int>st;
       int latestElem;
       for(int i=0;i<arr.size();i++){
           //smaller element from arr[i] is removed because in future answer will be arr[i]
           while(!st.empty() && st.top()<=arr[i]){
               st.pop();
           }
           if(st.empty()){
           st.push(arr[i]);
           arr[i] = -1;
           }else{
               latestElem = arr[i];
               arr[i] = st.top();
               st.push(latestElem);
           }
       }
        return arr;
    }
};