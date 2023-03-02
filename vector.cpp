#include <iostream>
#include<vector>
using namespace std;
int main (){

vector<int> v;
v.push_back(5);
v.push_back(10);
v.push_back(15);
v.push_back(20);

cout<< v[0]<<endl;
cout<< v[1]<<endl;
cout<< v[2]<<endl;
cout<< v[3]<<endl;
cout<<v.capacity()<<endl;
  cout<<v.size()<<endl;  

    return 0; 
}