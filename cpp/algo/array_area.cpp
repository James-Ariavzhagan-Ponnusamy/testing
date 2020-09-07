#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

//https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/

const int rows = 4;
const int cols = 5;

int row_adj[] = { -1, -1, -1,  0,  0,  1,  1,  1 };
int col_adj[] = { -1,  0,  1, -1,  1, -1,  0,  1 };

bool IsSafe(int row, int col, int matrix[rows][cols], int visited[rows][cols]){
  return  (
                row < rows
            &&  col <cols
            &&  row >=0
            &&  col >=0
            &&  matrix[row][col]
            &&  !visited[row][col]) ;
}

void find_area(int matrix[rows][cols], int visited[rows][cols], int r, int c, int &count){
  int i=0;
  visited[r][c] = 1;
  for(i=0;i<8;i++){
    if (IsSafe(r+row_adj[i], c+col_adj[i], matrix, visited)){
      count++;
      find_area(matrix, visited, r+row_adj[i], c+col_adj[i], count);
    }
  }
}

std::tuple<int, int, int> biggest_area(int matrix[rows][cols], int visited[rows][cols]){
  int i, j;
  int result = -1;
  int r=-1, c=-1;
  int count = 0;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      if ( matrix[i][j] && !visited[i][j]){
        count = 1;
        find_area(matrix, visited, i, j, count);
        if ( result < count ){
            result = count ;
            //std::cout <<"result updated to next higher " << result << std::endl;
            //std::cout <<"@row " << i << std::endl;
            //std::cout <<"@col " << j << std::endl;
            r = i; c = j;
        }
      }
    }
  }
  return std::make_tuple(r, c, result);
}

int main(){

  int matrix1[rows][cols] = {
    { 0, 0, 1, 1, 0 },
    { 1, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 1 }
   };

   int matrix2[rows][cols] = {
     {0, 0, 1, 1, 0},
     {0, 0, 1, 1, 0},
     {0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1}
   };

  int visited1[rows][cols] = {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }
  };

  int visited2[rows][cols] = {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }
  };

  //auto [r, c, result] = biggest_area(matrix, visited);
  int r, c, result ;
  std::tie(r, c, result) = biggest_area(matrix1, visited1);

  std::cout <<"@row " << r << std::endl;
  std::cout <<"@col " << c << std::endl;
  std::cout <<"result " << result  << std::endl;

  std::tie(r, c, result) = biggest_area(matrix2, visited2);

  std::cout <<"@row " << r << std::endl;
  std::cout <<"@col " << c << std::endl;
  std::cout <<"result " << result  << std::endl;
}
/*
    @row 0
    @col 2
    result 6
    @row 0
    @col 2
    result 4
*/
