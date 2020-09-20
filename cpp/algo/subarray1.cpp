#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/
int CheckDistinct(vector<int> x){
  map<int, int> m;
  int i = 0;
  int data = 0;
  for(i = 0; i<x.size();i++){
    data = x[i];
    m[data] = 1;
  }
  //cout <<"Size of unique elements " << m.size()<<endl;
  return m.size();
}

void subArray(vector<int> v)
{
  int nT = 0;
  int n = 0;
  n = v.size();
  nT = CheckDistinct(v);
  for (int i=0; i <n; i++)
  {
    for (int j=i; j<n; j++)
    {
      vector<int> x;
      int distinct = 0;
      for (int k=i; k<=j; k++)
      {
        //cout << v[k] << " ";
        x.push_back(v[k]);
      }
      distinct = CheckDistinct(x);
      if( distinct == nT)
      {
        cout << distinct << " : ";
        for (int k=i; k<=j; k++)
        {
          cout << v[k] << " ";
        }
        cout << endl;
      }
    }
  }
}

int main(){

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(1);
  v.push_back(1);


  /*
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);
  v.push_back(6);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(2);
*/
  /*
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(1);
  v.push_back(1);
  */
  subArray(v);
  return 0;
}
