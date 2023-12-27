#include <iostream>
#include <vector>
using namespace std;

// base case has to find rest code is fine till now u have pass 117 case out of 133
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
int row=matrix.size();
int col=matrix[0].size()-1;
int start=0;
int end=row*col-1;
int ans=0;
//int mid=start+(end-start)/2;
// base case1
if(matrix[0].size()==1){
  
}



while(start<=end){
  int  mid=start+(end-start)/2;
int num=matrix[mid/col][mid%col];

    if(num==target){
        return ans=1;}
        else if(num<target){
start=mid+1;
 }
  else{
end=mid-1;
 }
    
}     
   return 0; }
};