#include<bits/stdc++.h>
using namespace std;


class TrieNode
{
public:
    char data;
    unordered_map<char,TrieNode*> children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    bool search(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            if(root->isTerminal)
                return true;
            return false;
        }

        if(root->children.find(word[0]) != root->children.end())
            return search(root->children[word[0]],word.substr(1));
        return false;
    }

    void insertWord(TrieNode* root,string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode* child;
        if(root->children.find(word[0]) == root->children.end())
        {
            root->children[word[0]] = new TrieNode(word[0]);
            child = root->children[word[0]];
        }
        else
            child = root->children[word[0]];
        insertWord(child,word.substr(1));
    }
    Trie()
    {
        root = new TrieNode('\0');
    }
};



int main()
{



    Trie *trie = new Trie();
    trie->insertWord(trie->root,"apple");
    trie->insertWord(trie->root,"app");
    trie->insertWord(trie->root,"ape");
    bool b1 = trie->search(trie->root,"apple");
    if(b1)
        cout<<"apple is present"<<endl;
    else
        cout<<"apple is not present"<<endl;

    bool b2 = trie->search(trie->root,"app");
    if(b2)
        cout<<"app is present"<<endl;
    else
        cout<<"app is not present"<<endl;

    bool b3 = trie->search(trie->root,"applet");
    if(b3)
        cout<<"applet is present"<<endl;
    else
        cout<<"applet is not present"<<endl;

    return 0;
}