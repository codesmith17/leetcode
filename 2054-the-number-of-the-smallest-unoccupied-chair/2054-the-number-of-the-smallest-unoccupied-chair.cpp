class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        int n = times.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({times[i][0], i}); 
        }
        
        sort(arr.begin(), arr.end());  
        set<int> availableChairs;    
        for (int i = 0; i < n; i++) availableChairs.insert(i);  
        for (int i = 0; i < n; i++) {
            int arrivalTime = arr[i].first;
            int friendIndex = arr[i].second;
            
            while (!pq.empty() && pq.top().first <= arrivalTime) {
                availableChairs.insert(pq.top().second);  
                pq.pop();
            }
            
            int assignedChair = *availableChairs.begin(); 
            availableChairs.erase(availableChairs.begin()); 
            
            pq.push({times[friendIndex][1], assignedChair}); 
            
            if (friendIndex == targetFriend) {
                return assignedChair;
            }
        }

        return -1; 
    }
};
