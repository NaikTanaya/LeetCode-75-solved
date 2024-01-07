class Solution {
public:
    string predictPartyVictory(string senate) {
        const int n = senate.length();
    queue<int> qR;
    queue<int> qD;

    for (int i = 0; i < n; ++i)
      if (senate[i] == 'R')
        qR.push(i);
      else
        qD.push(i);

    while (!qR.empty() && !qD.empty()) {
      const int indexR = qR.front();
      qR.pop();
      const int indexD = qD.front();
      qD.pop();
      if (indexR < indexD)
        qR.push(indexR + n);
      else
        qD.push(indexD + n);
    }

    return qR.empty() ? "Dire" : "Radiant";
    }
};

// Example 1:

// Input: senate = "RD"
// Output: "Radiant"
// Explanation: 
// The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
// And the second senator can't exercise any rights anymore since his right has been banned. 
// And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.

// Example 2:

// Input: senate = "RDD"
// Output: "Dire"
// Explanation: 
// The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
// And the second senator can't exercise any rights anymore since his right has been banned. 
// And the third senator comes from Dire and he can ban the first senator's right in round 1. 
// And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
