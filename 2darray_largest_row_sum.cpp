#include<iostream>
#include<algorithm>
using namespace std;



int largest_row_sum(int arr[][3],int row,int col){
int rowindex=-1;
int maxi=INT32_MIN;
  for( row=0;row<3;row++){
    int sum=0;
for( col=0;col<3;col++){
 sum+=arr[row][col];  
}
 if(sum>maxi){maxi=sum;
 rowindex=row;}
}
cout<<"the maximum sum is"<<" "<<maxi<<endl;
    return rowindex;
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
int largestsum=largest_row_sum(arr,3,3);
cout<<"the maximum sum of rows and row index of that row is"<<" "<<largestsum<<endl;
  


return 1;
}