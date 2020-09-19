#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/print-all-possible-consecutive-numbers-with-sum-n/
void DispSum(int N){
  int nStart, nEnd;
  int i, j;
  int sum = 0;
  nStart = 0;
  nEnd = (N+1)/2;

  while(nStart < nEnd){
    sum = 0;
    for(i=nStart;i<nEnd;i++){
      sum+=i;
      if (sum == N){
        for(j=nStart;j<=i;j++){
          cout << j << " " ;
        }
        cout << endl;
      }
      if ( sum > N) break;
    }
    nStart++;
  }
  cout << endl << endl;
}

int main(){
  DispSum(100);
  DispSum(125);
}
