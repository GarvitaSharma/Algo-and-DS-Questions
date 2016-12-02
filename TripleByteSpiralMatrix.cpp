#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void printSpiral(int n){
    int space = n;
    
    int row = 0;
    int col = n-1;
    /*if(n == 0){
        cout<<"Incorrect input";
        return;
    }
    
    for(int i=0; i<n; i++){
        cout<<"*";
    }
    
    for(int i=1; i<n; i++){
        cout<<"\n";
        for(int j=1; j<space; j++)
            cout<<" ";
        cout<<"*";
    }*/
    
    vector<vector<string>> matrix;
    
    for(int i=0; i<n; i++){
        vector<string> tempVector;
        for(int j=0; j<n; j++){
            tempVector.push_back(" ");
        }
        matrix.push_back(tempVector);
    }
        
    while(row<col){    
        //print first row
        for(int i=row; i<n-row; i++)
            matrix[row][i] = "*";
    
        //print last column
        for(int j=row+1; j<n-row; j++)
            matrix[j][col] = "*";
        
        //print last row
        for(int i=col; i>row+1; i--)
            matrix[n-1-row][i] = "*";
    
        //print first column
        for(int j=col; j>row+1; j--)
            matrix[j][n - col] = "*";
        row++;
        row++;
        col--;
        col--;
        
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << matrix[i][j];
        cout<<"\n";
    }
        

}

int main(){
    int n = 12;
    
    printSpiral(n);
    return 0;
}
