// Copyright [2018] <mituh>
#include <iostream>
#include <vector>
using namespace std;

/*
   1 2 3    7 8 9    7 4 1 
   4 5 6 -> 4 5 6 -> 8 5 2
   7 8 9    1 2 3    9 6 3
*/
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size()-1; i++) {
      for (int j = i+1; j < matrix.size(); j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

void print_matrix(vector<vector<int>>& matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
  vector<vector<int>> matrix2 = {{1}};
  s.rotate(matrix2);
  print_matrix(matrix2);
  return 0;
}

