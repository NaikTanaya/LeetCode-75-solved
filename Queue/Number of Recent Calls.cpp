class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        requests.push(t);

        // Remove requests that are outside the time frame [t - 3000, t]
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // Return the number of requests within the time frame
        return requests.size();
    }

private:
    queue<int> requests;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

// Example 1:

// Input
// ["RecentCounter", "ping", "ping", "ping", "ping"]
// [[], [1], [100], [3001], [3002]]
// Output
// [null, 1, 2, 3, 3]

// Explanation
// RecentCounter recentCounter = new RecentCounter();
// recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
// recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
// recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
// recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
