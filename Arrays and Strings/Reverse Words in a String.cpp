#include <vector>
class Solution {
public:
    string reverseWords(string s) {
        // istringstream iss(s);
        // string x;
        // vector<string> str;

        // while(iss>>x)
        // {
        //     str.push_back(x);
        // }
        // string reverse;
        // for(int i=str.size()-1;i>=0;i--)
        // {
        //     reverse+=str[i];
        //     if(i!=0)
        //     {
        //         reverse+=' ';
        //     }
        // }
        // return reverse;

        istringstream iss(s);
        string x;
        string reverse;

        while (iss >> x) {
            if (!reverse.empty()) {
                reverse = x + ' ' + reverse;
            } else {
                reverse = x;
            }
        }
        return reverse;
    }
};
