#include<iostream>
#include<algorithm>
using namespace std;



bool ispresent(int arr[][3],int target,int row,int col){


for(int row=0;row<3;row++){
for(int col=0;col<3;col++){
    if(target==arr[row][col]){return 1;}
}

}
   return 0;
}



int main(){

int arr[3][3];
int target;
int row,col;
cout<<"enter the 2d array"<<"\n";
for(int row=0;row<3;row++){
for(int col=0;col<3;col++){
    cin >> arr[row][col];
}

}

//print
for( row=0;row<3;row++){
for(col=0;col<3;col++){
    cout<< arr[row][col]<<" ";

}
cout<<endl;
}
cout<<"enter the element to search"<<"\n";
cin>>target;


if(ispresent(arr,target,3,3)){
    cout<<"element is present";
}
else{cout<<"element is absent";}
cout<<endl;
cout<<endl;
cout<<"the sum of rows is"<<endl;
   for( row=0;row<3;row++){
    int sum=0;

for( col=0;col<3;col++){

    sum+=arr[row][col];  
}
 cout<<sum<<" ";
}


return 1;
}