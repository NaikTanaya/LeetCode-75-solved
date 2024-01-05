class Solution {
public:
    string decodeString(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        // When ']' is encountered, we need to start
        // decoding
        if (s[i] == ']') {
            string temp;
            while (!st.empty() && st.top() != '[') {
                // st.top() + temp makes sure that the
                // string won't be in reverse order eg, if
                // the stack contains 12[abc temp = c + "" =>
                // temp = b + "c" => temp = a + "bc"
                temp = st.top() + temp;
                st.pop();
            }
            // remove the '[' from the stack
            st.pop();
            string num;
            // remove the digits from the stack
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            int number = stoi(num);
            string repeat;
            for (int j = 0; j < number; j++)
                repeat += temp;
            for (char c : repeat)
                st.push(c);
        }
        // if s[i] is not ']', simply push s[i] to the stack
        else
            st.push(s[i]);
    }
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}
};

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"
