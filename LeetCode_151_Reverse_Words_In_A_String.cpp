/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
       string temp,result;
       
       //loop over the complete string
        for(int i=0; i<s.size(); i++){
            if(char(s[i]) == ' ' && temp.empty()) // skip white spaces
                continue;
            if(char(s[i]) == ' ' && !temp.empty()){ // current word has ended
                result = temp+" "+result; //add the current word at the starting of the result string i.e. in reverse order
                temp = "";
                continue;
            }
            if(char(s[i]) != ' ')//current word continues
                temp = temp+char(s[i]);
                continue;
       }
       
        if(!temp.empty()){ // add the last word at the beginning of the result string
            s = temp+" "+result;
        }
        
        else{
            s = result;
        }
        s = s.substr(0,s.size()-1); //remove the extra space at the last
        
    }
};
int main(){
    string original = "The sky is blue";
    reverseWords(original);
    cout<<"New String is = "<<original;
    return 0;
}
