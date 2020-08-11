#include <iostream>

#include <algorithm>
#include <functional>

using namespace std;

template<typename t>
struct myvector{


}



template<typename t>
void DefaultDisp(t x){
  cout<<"Default Disp "<< x <<endl;
}

template<typename t>
void Operate(vector<t> &v){
  cout << "The elements are " << endl;
  for(auto a:v){
    DefaultDisp(a);
  }
}

template<typename t>
void Operate(vector<t> &v, std::function<void(t)> func)
{
  cout << "The elements are " << endl;
  for(auto a:v){
    func(a);
  }
}
int main(){
  int operations = 0;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  Operate(v);
  Operate<int>(v, [&](int x) {cout<<"Inside lambda " << x<<endl;operations++;} );
  cout<<"Total number of operations are " << operations << endl;

}
