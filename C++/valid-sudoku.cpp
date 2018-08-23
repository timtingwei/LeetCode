// Copyright [2018] <mituh>
// valid-sudoku.cpp
// 这个算法目前烂尾中..
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<string>>& board) {
    for (int i = 0; i < 9; i++) {
      vector<string> line;
      for (int j = 0; j < 9; j++) {
        // if (flag) {int tmp = i; i = j; j = tmp;}
        cout << board[i][j] << " ";
        line.push_back(board[i][j]);
        // 如果是.的话....这个算法怎么改啊??
      }
      for (int k = 0; k < 3; k += 3) {
        cout << "line.size() = " << line.size() << endl;
        sort(line.begin() + k, line.begin()+k+3);
        for (int ik = 1; ik < 3; ik++) {
          if (line[k+ik] == line[k+ik-1]) return false;
        }
      }

      vector<string> merge_v;
      int ii = 0, jj = 0;
      while (line[ii] != line[jj] && ii < 3 && jj < 3) {
        if (line[ii] < line[jj]) {
          merge_v.push_back(line[ii++]);
        } else {
          merge_v.push_back(line[jj++]);
        }
      }
      if (ii != 3 && jj != 3) return false;

      ii = 0, jj = 0;
      while (merge_v[ii] != line[jj] && ii < 6 && jj < 3) {
        if (merge_v[ii] < line[jj+6]) {
          ii++;
        } else {
          jj++;
        }
      }
      if (ii != 6 && jj != 3) return false;
    }

    for (int i = 0; i < 9; i++) {
      vector<string> line;
      for (int j = 0; j < 9; j++) {
        // if (flag) {int tmp = i; i = j; j = tmp;}
        line.push_back(board[j][i]);
      }
      for (int k = 0; k < 3; k += 3) {
        sort(line.begin() + k, line.begin()+k+3);
        for (int ik = 1; ik < 3; ik++) {
          if (line[k+ik] == line[k+ik-1]) return false;
        }
      }

      vector<string> merge_v;
      int ii = 0, jj = 0;
      while (line[ii] != line[jj] && ii < 3 && jj < 3) {
        if (line[ii] < line[jj]) {
          merge_v.push_back(line[ii++]);
        } else {
          merge_v.push_back(line[jj++]);
        }
      }
      if (ii != 3 && jj != 3) return false;

      ii = 0, jj = 0;
      while (merge_v[ii] != line[jj] && ii < 6 && jj < 3) {
        if (merge_v[ii] < line[jj+6]) {
          ii++;
        } else {
          jj++;
        }
      }
      if (ii != 6 && jj != 3) return false;
    }
    return true;
  }
};



int main() {
  vector<vector<string>> board = {{"5","3",".",".","7",".",".",".","."},
       {"6",".",".","1","9","5",".",".","."},
       {".","9","8",".",".",".",".","6","."},
       {"8",".",".",".","6",".",".",".","3"},
       {"4",".",".","8",".","3",".",".","1"},
       {"7",".",".",".","2",".",".",".","6"},
       {".","6",".",".",".",".","2","8","."},
       {".",".",".","4","1","9",".",".","5"},
       {".",".",".",".","8",".",".","7","9"}};
  Solution solution;
  bool ans1 = solution.isValidSudoku(board);
  cout << ans1 << endl;
  return 0;
}

/*
{{"5","3",".",".","7",".",".",".","."},
  {"6",".",".","1","9","5",".",".","."},
  {".","9","8",".",".",".",".","6","."},
  {"8",".",".",".","6",".",".",".","3"},
  {"4",".",".","8",".","3",".",".","1"},
  {"7",".",".",".","2",".",".",".","6"},
  {".","6",".",".",".",".","2","8","."},
  {".",".",".","4","1","9",".",".","5"},
  {".",".",".",".","8",".",".","7","9"}};
*/
