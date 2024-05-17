#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL; 
    }
    void put(char ch,Node* node){
            links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    
};

class Trie{
    private:
    Node* root;
    public:
    //Initialize  data structure 
    Trie(){
        root=new Node();
    }
    //inserts the word into the Trie
    //O(length of word)
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
           //moves to the reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
        cout<<word;
    }
    //returns if the word exits in the trie
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if (!node->containsKey(word[i]))
            {
                return false;
            }
           node= node->get(word[i]);
        }
        return node->flag;
    }
    //returns if there is any word in the trie that starts with the given string
    bool startsWith(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }

};
int main(){
    Trie t1;
    t1.insert("hunny");
    t1.insert("pupp");
  cout<<  t1.search("hunn");
  cout<<t1.startsWith("pu");
}