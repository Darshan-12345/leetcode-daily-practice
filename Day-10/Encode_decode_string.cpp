#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.length());
            encoded += '#';
            encoded += s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> message;
        int i = 0;

        while (i < s.length()) {
            int len = 0;

            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            i++; // skip '#'

            string chunk = s.substr(i, len);
            message.push_back(chunk);

            i += len;
        }

        return message;
    }
};
