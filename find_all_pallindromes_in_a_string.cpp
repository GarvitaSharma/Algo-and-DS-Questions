#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    string input = "geekfke";
    //append a special character at starting and end of the string to make calculations easier
    string s = "@" + input + "#";
    map<string,int> maps;
    //find all even pallindromes
    for(int i=1; i<s.size(); i++){
        int t = i;
        int rd = 0;
        string temp = "";
        string front = "";
        string end = "";
        //find all even pallindromes with s[i] as the pivot element
        while(s[t-1-rd] == s[t+rd] && t-1-rd>0 && t+rd<s.size()){
            front += s[t-1-rd];
            end += s[t+rd];
            rd++;
            maps[front+end] = 1;
        }
        if(rd > 0){
            temp = front+end; 
        }
        
    }
    //find all odd pallindromes
    for(int i=1; i<s.size(); i++){
        int t = i;
        int rd = 0;
        string temp = "";
        string front = "";
        string end = "";
        //find all odd pallindromes with s[i] as the pivot element
        while(s[t-1-rd] == s[t+rd+1] && t-1-rd>0 && t+rd+1<s.size()){
            front += s[t-1-rd];
            end += s[t+rd+1];
            string tempfront = front;
            reverse(tempfront.begin(),tempfront.end());
            maps[tempfront+s[t]+end] = 1;
            rd++;
        }
        maps[string(1,s[i])] = 1;
        if(rd > 0){
            reverse(front.begin(),front.end());
            temp = front+s[i]+end;
        }
    }
    map<string,int>::iterator it;
    for(it = maps.begin(); it != maps.end(); it++)
        if(it->first != "@" && it->first != "#")
            cout<<it->first<<"\n";
    return 0;
}




/*
 * Complete the function below.
 */

    


