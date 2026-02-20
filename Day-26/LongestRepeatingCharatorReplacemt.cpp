#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int longestRepeatingCharactorReplacemt(string s,int k) {
    int n = s.length();
   
    vector<int> freq(26, 0);
    int right = 1, left = 0,max_freq = 0,max_len = 0;
    if(n == 1) return 1;
    while(right < n) {
        freq[s[right]- 'A']++;
        max_freq = max(max_freq,freq[s[right] - 'A']);
        int val = (right-left+1) - max_freq;
        if(val > k) {
            freq[s[left]-'A']--;
            left--;
            
        }
        else {
                max_len = max(max_len, max_freq+val);
            }
        right++;
    }
    if(k == 0 && max_len == 0) return 1;
    else return max_len;
}

int main() {
    string s = "ABAB";
    int k = 2;
    int result = longestRepeatingCharactorReplacemt(s,k);
    cout<<result;
}