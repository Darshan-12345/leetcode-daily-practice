#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

// first method
// int min_len_substring( string &nums) {
//     int n = nums.length();
//     int zeroindex = 0,oneindex =0,twoindex = 0;
//     bool zero = false,one = false,two = false;
//     int res = 9999999;
//     for(int i =0; i<n; i++) {
//         if(nums[i] == '0') {
//             zeroindex = i;
//             zero = true;
//         }
//         else if(nums[i] == '1') {
//             oneindex = i;
//             one = true;
//         }
//         else if(nums[i] == '2') {
//             twoindex = i;
//             two = true;
//         }
//         if(zero and two and one) {
//             res = min(res, max({zeroindex, oneindex, twoindex}) - min({zeroindex, oneindex, twoindex}));
//         }
//     }
//     if(res == 9999999 ) return -1;
//     else return res+1;

// }

// int main() {
//     string s = "012112";
//     int n = min_len_substring(s);
//     cout<<n;
// }


// second method using sliding window

// Online C++ compiler to run C++ program online
// #include <iostream>
// #include<algorithm>
// #include<string>
// using namespace std;

int min_len_subString(string &s) {
    int n = s.length();
    int i =0,k =0,cnt = 0,min_len = 999999;
    int freq[3] = {0};
    while(k<n) {
      freq[s[k] - '0']++;
      if(freq[s[k] - '0'] == 1) cnt++;
      if(cnt == 3) {
          while(freq[s[i] - '0'] > 1) {
              freq[s[i] - '0']--;
              i++;
          }
          min_len = min(min_len,k-i+1);
          freq[s[i] - '0']--;
          i++;
          cnt--;
      }
      k++;
    }
    if(min_len == 999999) return -1;
    else return min_len;
}

int main() {
   string s = "1021211212";
   int n = min_len_subString(s);
   cout<<n;

    return 0;
}