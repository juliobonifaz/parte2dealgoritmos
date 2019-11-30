// C++ program to insert element in binary tree
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has key, pointer to left child
and a pointer to right child */
class Node {
public:
    int key;
    class Node* left, *right;
};

/* function to create a new node of tree and r
eturns pointer */
class Node* newNode(int key)
{
    class Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = nullptr;
    return temp;
};

//inorder
void inorder(class Node* temp)
{
    if (!temp)
        return;

    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
}

void insert(class Node* temp, int key)
{
    if (temp== nullptr){
        class Node* root = newNode(key); // nullptr node inster fail

    }

    queue<class Node*> q;
    q.push(temp);




    while (!q.empty()) { //recorer hasta encontrar un espacio
        class Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode(key);
            break;
        } else
            q.push(temp->left);

        if (!temp->right) {
            temp->right = newNode(key);
            break;
        } else
            q.push(temp->right);
    }
}





Node* deletion(class Node* root, int key) //not working
{

    queue<class Node*> q;
    q.push(root);

    class Node* temp;
    class Node* key_node = nullptr;

    temp = q.front();
    while (!q.empty()) {

        q.pop();

        if (temp->key == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
    temp = nullptr;
    return root;
}







// Driver code
int main() {
    class Node *root = newNode(2);//first node insert

    cout << "Inorder traversal before insertion:";
    inorder(root);

    int key = 12;
    insert(root, key);

    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);

    //deletion(root,key);
    //inorder(root);



    return 0;
} 
