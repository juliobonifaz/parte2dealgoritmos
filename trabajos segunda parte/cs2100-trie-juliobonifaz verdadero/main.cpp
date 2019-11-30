#include <iostream>
#include "map"
using namespace std;

class TrieNode {
public:
    map<char,TrieNode*> children;
    bool is_node;
};



TrieNode* getNewTrieNode() //constructor
{
    TrieNode* node = new TrieNode;
    node->is_node = false;
    return node;
}

void insert(TrieNode*& root, const string& str)
{
    if (root == nullptr)
        root = getNewTrieNode();

    TrieNode* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];

        /* make a new node if there is no path */
        if (temp->children.find(x) == temp->children.end())
            temp->children[x] = getNewTrieNode();//insertando cada letra

        temp = temp->children[x];
    }

    temp->is_node = true;
}

/*function to search in trie*/
bool search(TrieNode* root, const string& str)
{
    /*return false if Trie is empty*/
    if (root == nullptr)
        return false;

    TrieNode* temp = root;
    for (int i = 0; i < str.length(); i++) {

        /* go to next node*/
        temp = temp->children[str[i]]; //comprobar letra

        if (temp == nullptr)
            return false;
    }

    return temp->is_node;
}

/*Driver function*/
int main()
{
    TrieNode* root = nullptr;

    insert(root, "hola");
    cout << search(root, "hola") << " ";

    insert(root, "root");
    cout << search(root, "root") << " ";

    cout << search(root, "geekk") << " ";

    insert(root, "sa");
    cout << search(root, "sa") << " ";

    insert(root, "sacience");
    cout << search(root, "sacience") << endl;

    return 0;
}
