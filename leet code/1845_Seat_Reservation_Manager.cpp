// 1845. Seat Reservation Manager link https://leetcode.com/problems/seat-reservation-manager/description/

#include<bits/stdc++.h>
using namespace std;
class SeatManager {
public:
    map<int,int>seatsData;
    SeatManager(int n) {
        for(int i = 0; i < n; i++)
            seatsData[i] = i+1;
    }
    
    int reserve() {
        int value = seatsData.begin()->second;
        seatsData.erase(seatsData.begin());
        return value;
    }
    
    void unreserve(int seatNumber) {
        seatsData[seatNumber-1] = seatNumber;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
int main()
{
    
}