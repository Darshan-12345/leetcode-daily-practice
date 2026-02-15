#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
      int maxP = 0 ,maxVal = prices[n-1];
      for(int i =n-2; i>=0; i--) {
        if(prices[i] > maxVal) maxVal = prices[i];
        else {
            int val = maxVal-prices[i];
            maxP = max(maxP,val);
        }
      }
      return maxP;

    }