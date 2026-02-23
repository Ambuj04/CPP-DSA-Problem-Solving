class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int room = 0;
        int maxRoom = 0;
        int n = start.size();
        int checkIn = 0;//start index
        int checkOut = 0;//end index
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(checkIn < n && checkOut < n){
            if(start[checkIn] < end[checkOut]){
                room++;
                checkIn++;
                maxRoom = max(maxRoom,room);
            }else{
                room--;
                checkOut++;
            }
        }
        return maxRoom;
    }
};
