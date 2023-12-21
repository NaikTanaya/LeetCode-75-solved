class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        for (int i = 0; i < chars.size();) {
            int j = i + 1;
            while (j < chars.size() && chars[i] == chars[j]) {
                j++;
            }
            chars[index++] = chars[i];

            if (j - i > 1) {
                string c = to_string(j - i);

                for (int k = 0; k < c.size(); k++) {
                    chars[index++] = c[k];
                }
            }
            i = j;
        }
        return index;
    }
};
