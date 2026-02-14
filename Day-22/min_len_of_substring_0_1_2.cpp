#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

// first method
int min_len_substring( string &nums) {
    int n = nums.length();
    int zeroindex = 0,oneindex =0,twoindex = 0;
    bool zero = false,one = false,two = false;
    int res = 9999999;
    for(int i =0; i<n; i++) {
        if(nums[i] == '0') {
            zeroindex = i;
            zero = true;
        }
        else if(nums[i] == '1') {
            oneindex = i;
            one = true;
        }
        else if(nums[i] == '2') {
            twoindex = i;
            two = true;
        }
        if(zero and two and one) {
            res = min(res, max({zeroindex, oneindex, twoindex}) - min({zeroindex, oneindex, twoindex}));
        }
    }
    if(res == 9999999 ) return -1;
    else return res+1;

}

int main() {
    string s = "012112";
    int n = min_len_substring(s);
    cout<<n;
}
