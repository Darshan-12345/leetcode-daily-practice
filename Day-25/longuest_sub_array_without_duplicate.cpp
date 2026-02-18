#include<iostream>
#include<vector>
#include<string>
using namespace std;

int logest_substring(string s) {
    int n = s.length();
    vector<int> freq(256,0);
    int left = 0,right = 0,max_len = 0;
    while(right<n) {
        freq[s[right]]++;
        while(freq[s[right]]>1) {
            freq[s[left]]--;
            left++;
        }
        max_len = max(max_len,right-left+1);
        right++;
    }
    return max_len;
}

int main() {
    string s = "abcabcbb";
    cout<<logest_substring(s);
}