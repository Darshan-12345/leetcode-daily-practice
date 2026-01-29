#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
       vector<int> ans;
       vector<int> freqP(26,0);
       vector<int> windofreq(26,0);
       if(p.length() > s.length()) return ans;
       for(int i =0; i<p.length(); i++) {
        freqP[p[i] -'a']++;
       }
       for(int i =0; i<p.length(); i++) {
            windofreq[s[i] - 'a']++;
       }
       if(windofreq== freqP) {
        ans.push_back(0);
       }
       for(int i = p.length(); i < s.length(); i++) {
            windofreq[s[i] - 'a']++;//include new character
            windofreq[s[i- p.length() ] - 'a']--; // exclude old charator
            if(freqP == windofreq) {    // compare
                ans.push_back(i-p.length()+1);
            }
       }

        return ans;
    }
};