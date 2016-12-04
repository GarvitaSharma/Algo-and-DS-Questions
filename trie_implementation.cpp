// This is the text editor interface. 
/*
Design a dictionary that support 2 interfaces

void add_word(word)
bool exist(word), where it can take a simple regular expression of "?" where "?" can match any one letter

Example
add_word("hello")
add_word("world")
exist("hell") -> false
exist("hello") -> true
exist("hell?") -> true
exist("he?ll") -> false
exist("hi") -> false
exist("?woo)" -> false
add_word("hi")
exist("hi") -> true
*/
// Anything you type or change here will be seen by the other person in real time.
#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;

struct Tree{
  char val;
  Tree *next[27];
};
class dictionary{
  public:
  Tree *root = new Tree();
  //root = new Tree();
  //root->val = "";
  
  dictionary(){
      root->val = ' ';
      for(int i=0; i<27; i++){
          root->next[i] = NULL;
      }
  }
  
  //function to add word in a trie
  void add_word(string word){
      Tree *temp = root;
      int start = 0;
      int end = word.size();
      //loop over the word
      while(start <= end){

        //if end of the word reached, insert * element to mark end of word
        if(start == end){
            Tree *leafNode = new Tree();
            leafNode->val = '*';
            for(int i=0; i<27; i++)
                leafNode->next[i] = NULL;
            temp->next[26] = leafNode;
            break;
        }
        
        //get the index of the current character
        int index = (word[start])-97;

        //if the current character found in the trie
        if(temp->next[index] != NULL && temp->next[index]->val == word[start]){
              
        //do nothing      
        }

        //if current character not found in the trie then make a new node and insert in the trie at its position
        else{
            Tree *node = new Tree();
            node->val = word[start];
            for(int i=0; i<27; i++)
                node->next[i] = NULL;
            temp->next[index] = node;
        }
        //continue for next characters in the word
        temp = temp->next[index];
        start++;
    }
}
  
//function to check if the word exist in the trie or not
bool exist(string word){
    Tree *temp = root;
    int index = 0;
    for(int i=0; i<=word.size(); i++){
        //if alphabet found then get the index of the alphabet
        if (i < word.size() && word[i] != '?')
            index = (word[i]) - 97;
        
        //if ? found then make index 0    
        else if(word[i] == '?')
            index = 0;
        else
            index = 26;

        //if current character found in the trie    
        if(temp->next[index] != NULL && temp->next[index]->val == word[i]){cout<<i<<"->"<<temp->val<<"\n";
            //move to next index
            temp = temp->next[index];
          }

        if end of word reached  
        else if(i == word.size() && temp->next[index] != NULL && temp->next[index]->val == '*'){
            return true;
        }
        
        //if wild character appears and it is at the end of the word, check if the word end in the trie as well
        else if(word[i] == '?' && i == word.size()-1){
            for(int j=0; j<27; j++){
                if(temp->next[j] != NULL && temp->next[j]->next[26] != NULL && temp->next[j]->next[26]->val == '*'){
                    return true;
                }
                    
            }
            return false;
        }

        //if the wild character appear in between, check for the next character that matches
        else if(word[i] == '?' && i < word.size()-1){
            index = word[i+1] - 97;
            int flag = 0;
            for(int j=0; j<27; j++){
                if(temp->next[j] != NULL && temp->next[j]->next[index]->val == word[i+1]){
                    i++;
                    temp = temp->next[j]->next[index];
                    cout<<i<<"->"<<temp->val<<"\n";
                    flag = 1;
                    break;
                }
            }

            //if no matching next character found, return false
            if(flag == 0)
            return false;
        }

        //return false for all other non alpha and non wild characters
        else{
            cout<<i<<"->"<<temp->val<<"\n";
            return false;
        }
    }
    return false;
}
  
  
};

int main(){
    dictionary d;
    d.add_word("hello");
    d.add_word("world");
    d.add_word("he");
    d.add_word("here");
    d.add_word("head");
    if(d.exist("he?d"))
        cout<<"true";
    else
        cout<<"false";
}
