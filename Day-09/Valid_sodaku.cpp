#include <iostream>
#include <vector>
using namespace std;




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // 1. Check each row
        for (int i = 0; i < 9; i++) {
            int freq[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (freq[num]++) return false;
            }
        }

        // 2. Check each column
        for (int i = 0; i < 9; i++) {
            int freq[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                int num = board[j][i] - '0';
                if (freq[num]++) return false;
            }
        }

        // 3. Check each 3x3 sub-box
        for (int rowStart = 0; rowStart <= 6; rowStart += 3) {
            for (int colStart = 0; colStart <= 6; colStart += 3) {
                int freq[10] = {0};
                for (int i = rowStart; i < rowStart + 3; i++) {
                    for (int j = colStart; j < colStart + 3; j++) {
                        if (board[i][j] == '.') continue;
                        int num = board[i][j] - '0';
                        if (freq[num]++) return false;
                    }
                }
            }
        }

        return true;
    }
};
