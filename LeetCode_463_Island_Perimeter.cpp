#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1)
                    perimeter += 4;
            }
        }
        
        int sum = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(j < grid[i].size()-1 && grid[i][j] == 1 && grid[i][j+1] == 1)
                    sum += 2;
                if(i < grid.size()-1 && grid[i][j] == 1 && grid[i+1][j] == 1)
                    sum += 2;
            }
            
        }
        return perimeter-sum;
    }
};

int main(){
    vector<vector<int>> grid(4,vector<int>(4,0));
    
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[3][0] = 1;
    grid[3][1] = 1;
    
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    
    Solution s;
    int islandPerimeter = s.islandPerimeter(grid);
    cout<<"Perimeter = " << islandPerimeter<<"\n";
    return 0;
}
