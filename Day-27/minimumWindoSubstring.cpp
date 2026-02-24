#include<iostream>
#include<vector>
using namespace std;

string minimumWindowSubstring(string s, string t) {
    int n = s.length();
    int m = t.length();
   
    if(m > n) return " ";
    vector<int> freq(256,0);
    for(int i =0; i<m; i++) {
        freq[t[i]]++;
    }
    int left = 0,right = 0,min_len = 100000000,cnt = 0,startindex = 0;
    while(right < n) {
        if(freq[s[right]] > 0) {
            cnt++;
        }
        freq[s[right]]--;
        
        while(cnt == m) {
            if(right - left+1 < min_len) {
                min_len = right - left+1;
                startindex = left;
            }
            freq[s[left]]++;
            if(freq[s[left]] > 0) {
                cnt--;
            }
            left++;
        }
        right++;
    }
    if(min_len == 100000000) return " ";
    return s.substr(startindex,min_len);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<minimumWindowSubstring(s,t);
}