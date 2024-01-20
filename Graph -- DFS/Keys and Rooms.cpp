class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(),0);
        stack<int> keys;
        int roomVisited=0;

        for(int i=0;i<rooms[0].size();i++)
        {
            // store all keys into stk
            keys.push(rooms[0][i]);
        }
        // also mark the room[0] as entered
        visited[0] = 1;

        if(keys.empty()) 
        {
            return false;
        }
        while(!keys.empty())
        {
            // pop from stk and mark as visited 
            int temp=keys.top();
            keys.pop();

            // if the key was for a room that wasn't visited
            if(visited[temp] == 0){
                roomVisited++;
                // mark that room as visited
                visited[temp] = 1;
                // push all the keys in that room into keys stack
                for(int i=0; i<rooms[temp].size(); i++){
                    keys.push(rooms[temp][i]);
                }
        }

    }
    // because we skip the room 0 so if we unlock rooms.size()-1 return true
        if(roomVisited == rooms.size()-1) return true;
        else return false;
    }

};

// Example 1:

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation: 
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.

// Example 2:

// Input: rooms = [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
