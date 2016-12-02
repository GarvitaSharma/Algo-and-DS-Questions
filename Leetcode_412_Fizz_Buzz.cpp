#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> out;
        for(int i=1; i<=n; i++){
            if(i%3 == 0 && i%5 == 0)
                out.push_back("FizzBuzz");
            else if(i%3 == 0)
                out.push_back("Fizz");
            else if(i%5 == 0)
                out.push_back("Buzz");
            else
                out.push_back(to_string(i));
        }
       return out; 
    }
};

int main(){
    int n = 15;
    vector<string>result;
    Solution s;
    result = s.fizzBuzz(n);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\n";
    }
    
    return 0;
}
