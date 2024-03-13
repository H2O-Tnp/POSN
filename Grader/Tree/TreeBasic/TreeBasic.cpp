#include <iostream>
using namespace std;

class TreeNode {
  public:
    int key;			// Object is often int, string . . .
    TreeNode* left; TreeNode* right; TreeNode* parent;
    TreeNode(int key) {
      this->key = key;
      left = right = parent = NULL;
    };
};

TreeNode* insert(int key, TreeNode*& current, TreeNode* parent){//Recursive
    if (current == NULL) {
        current = new TreeNode(key);
        current->parent = parent;
        return current;
    }
    if (key == current->key)
        return NULL;    // duplicate, do nothing and return NULL.
    else if (key < current->key)
        return insert(key, current->left, current);
    else // key > current->key
        return insert(key, current->right, current);
}

TreeNode* findMax(TreeNode* current) {
    if (current == NULL)
        return NULL;
    else if (current->right == NULL)
        return current;
    else
        return findMax(current->right);
}

void remove(int key, TreeNode*& current) {
    //1. Perform Standard BST Delete
    if (current == NULL)
        return;     // No match node, do nothing
    else if (key < current->key)
        return remove(key, current->left);
    else if (key > current->key)
        return remove(key, current->right);
    else if (current->left != NULL && current->right != NULL) {
        TreeNode* replacer = findMax(current->left);
        current->key = replacer->key;
        remove(replacer->key, current->left);
    } else {
        TreeNode* temp = current;
        if (current->left != NULL)
            current = current->left;
        else
            current = current->right;

        delete temp;
    }
}
void inorder(TreeNode* current) {
    if (current == NULL)
        return;
    else {
        inorder(current->left);
        cout << current->key << " " ;
        inorder(current->right);
    }
}
int main(){
    TreeNode* root = NULL;
    char cmd;
    int number;
    while(true){
       cin >> cmd >> number;
       if (cmd=='X') break;
       if (cmd=='I') insert(number,root,NULL);
       if (cmd=='R') remove(number,root);
       if ((cmd=='P')&&(number==1)) inorder(root);
    }
    return 0;
}

