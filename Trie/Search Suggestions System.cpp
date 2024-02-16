class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string current = "";
        for(char& c: searchWord) {
            current += c;
            vector<string> suggested;
            auto it = lower_bound(products.begin(), products.end(), current);
            //returns an iterator that points to the first value that is 
            //just greater than or equal to the specified value
            for(int i=0; i<3 && (it+i)!=products.end(); i++) {
                string& s = *(it+i);
                //if(s.find(current)) break; 
                if(!s.find(current)) {
                    suggested.push_back(s);
                }
            }
            ans.push_back(suggested);
        }
        return ans;
    }
};

// Example 1:

// Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
// Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
// Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
// After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
// After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

// Example 2:

// Input: products = ["havana"], searchWord = "havana"
// Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
// Explanation: The only word "havana" will be always suggested while typing the search word.
