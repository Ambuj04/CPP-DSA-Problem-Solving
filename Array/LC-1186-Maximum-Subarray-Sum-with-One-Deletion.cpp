class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = arr[0];
        int nodelete = arr[0];
        int onedelete=INT_MIN; //it denote that first element of array is deleted
        int prevnodelete,prevonedelete,temp;
        for( int i = 1;i<arr.size();i++){
            prevnodelete = nodelete;
            prevonedelete = onedelete;
            nodelete = max(arr[i],prevnodelete+arr[i]);
            if(prevonedelete == INT_MIN){
                temp = arr[i];
            }else{
                temp = prevonedelete+arr[i];
            }
            onedelete = max(temp,prevnodelete);
            res = max(res,max(onedelete,nodelete));
        }
    return res;
    }
}; 