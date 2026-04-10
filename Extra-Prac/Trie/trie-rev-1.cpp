#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount = 0;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption capital character
        int index = word[0] - 'A';
        TrieNode *child;
        // present case
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return (searchUtil(root, word));
    }
    void removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        removeUtil(child, word.substr(1));
    }
    void removeUtilOpti(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        removeUtilOpti(child, word.substr(1));
       if (!child->isTerminal && child->childCount == 0)
        {
            
                delete child;
                root->childCount--; 
                root->children[index] = nullptr;
            
        }
    }
    void remove(string word)
    {
        // removeUtil(root,word);
        removeUtilOpti(root, word);
    }
};
int main()
{
    // object is in stack
    Trie t;
    t.insertWord("AMBUJ");
    // pointer is on stack and object is on heap memory
    Trie *T = new Trie();
    T->insertWord("ABHAY");
    cout << T->search("ABHAY") << endl;
    T->remove("ABHAY");
    cout << T->search("ABHAY");
    delete T;
    return 0;
}