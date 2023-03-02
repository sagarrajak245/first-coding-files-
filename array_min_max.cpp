#include<iostream>
#include<math.h>
using namespace std;
// use of combination and factorial with function
int maximum(int arr[], int a){

int maxi=INT32_MIN;
for(int i=0;i<a;i++){

    maxi= max(maxi,arr[i]);

}
return maxi;
}


int minimum(int arr[],int b){

int mini=INT32_MAX;
for(int i=0;i<b;i++){
mini=min(mini,arr[i]);

return mini;
}
}
int main(){
int array[5];
cout<<"take array input\n";
for(int i=0;i<5;i++){

    cin>>array[i];
}

cout<<"the maximum of array is\n"<<maximum( array,5)<<"\n";


cout<<"the minimum of array is\n"<<minimum( array,5);

    return 0;
}