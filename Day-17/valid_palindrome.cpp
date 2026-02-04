#include <iostream>
#include <string>

using namespace std;



// 1
class Solution {
public:
    bool isPalindrome(string s) {
        string val = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(isalnum(s[i])) {
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    val.push_back(s[i] + 32);
                } else {
                    val.push_back(s[i]);
                }
            }
        }
        
        int left = 0, right = val.size() - 1;
        while(left < right) {
            if(val[left] != val[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


// 2

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            while(!isalnum(s[left]) && left < right) {
                left++;
            }
            while(!isalnum(s[right]) && left < right) {
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};