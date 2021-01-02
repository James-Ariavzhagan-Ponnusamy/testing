//https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

typedef map<string, int> MAPSI;

void jsplit(const string &str, char delim, MAPSI &v)
{
    string token;
    istringstream tokenstream(str);

    while(getline(tokenstream, token, delim))
    {
        cout<<token<<endl;
        if (v.find(token) != v.end()){
            cout<<"The entry already in map" << endl;
            v[token]++;
        }
        else
        {
            cout<<"The entry NOT in map" << endl;
            v[token] = 1;
        }
    }
}

int main(){
    string str;
    MAPSI s;
    cout << "Enter the string " << endl;
    getline(cin, str);
    cout<<"["<<str<<"]"<<endl;
    jsplit(str, ' ', s);
    for(auto ite=s.begin();ite!=s.end();ite++)
    {
        cout<<ite->first<<":"<<ite->second<<endl;
    }
    return 0;
}
