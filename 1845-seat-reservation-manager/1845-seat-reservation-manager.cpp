class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> AvaiSeats;
    SeatManager(int n) {
        for(int i=1; i<=n; ++i){
            AvaiSeats.push(i);
        }
    }
    
    int reserve() {
        int seatNumber = AvaiSeats.top();
        AvaiSeats.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        AvaiSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */