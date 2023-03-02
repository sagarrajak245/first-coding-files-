
#include<iostream>
using namespace std;


int main(){
int arr[7];

cout<<"enter the array\n";
for(int i=0;i<7;i++){
cin>>arr[i];
}

cout<<"array output is\n";
for(int i=0;i<7;i++){
cout<<arr[i]<<" ";
}
cout<<" \n";
int sum=0;
for(int i=0;i<7;i++){
 
sum=sum+arr[i];

}

cout<<"sum is\n"<<sum;

return 0;
}

