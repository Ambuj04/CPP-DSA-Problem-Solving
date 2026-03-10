class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>pq;//max heap
        //push first k elements in max Heap then if number larger than greatest number in heap then we replace that
        for(int i = 0 ;i<arr.size();i++){
            if(i < k){
            pq.push(arr[i]);
            continue;
            }
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};