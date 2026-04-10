// User function Template for C++
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
        int index = word[0] - 'a';
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
    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for (int i = 0; i < 26; i++)
        {
            TrieNode *next = curr->children[i];
            if (next)
            {
                prefix.push_back(i + 'a');
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    };
    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++)
        {
            vector<string> temp;
            if (prev == nullptr)
            {
                temp.push_back("0");
                output.push_back(temp);
                continue;
            }
            char lastch = str[i];
            prefix.push_back(lastch);
            // check for last char
            TrieNode *curr = prev->children[lastch - 'a'];
            // if not found
            if (curr == nullptr)
            {
                temp.push_back("0");
                output.push_back(temp);
                prev = nullptr;
                continue;
            }
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *t = new Trie();
        for (int i = 0; i < n; i++)
        {
            t->insertWord(contact[i]);
        }
        return t->getSuggestions(s);
    }
};