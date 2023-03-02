 
#include<iostream>
using namespace std;

int unique_element(int arr[],int size){
int ans=0;
for(int i=1;i<size;i++){

ans=ans^arr[i];

}
return ans;
}




int main(){
int arr[5];



cout<<" enter the array \n";
for(int i=0;i<5;i++){
cin>>arr[i];
}


int element=unique_element(arr,5);

cout<<"unique element in array is \n";
cout<<element;

return 0;
}