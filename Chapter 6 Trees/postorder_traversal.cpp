#include <iostream>
#include <stack>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *init(int data)
{
    node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert_left(node *root, int data)
{
    root->left = init(data);
}
void insert_right(node *root, int data)
{
    root->right = init(data);
}

void delete_left(node *root)
{

    node *todel = root->left;
    root->left = NULL;
    delete todel;
}
void delete_right(node *root)
{

    node *todel = root->right;
    root->right = NULL;
    delete todel;
}

void postorder_recursive(node *root)
{

    if (root == NULL)
    {
        return;
    }
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout << root->data << " ";
}

void postorder_iterative(node *root)
{

    stack<node *> stk;
    node *prev = NULL;

    do
    {
        while (root != NULL)
        {
            stk.push(root);
            root = root->left;
        }

        while (root == NULL && !stk.empty())
        {
            root = stk.top();

            if (root->right == NULL || root->right == prev)
            {
                cout << root->data << " ";
                stk.pop();
                prev = root;
                root = NULL;

            }
            else
            {
                root = root->right;
            }
        }

    } while (!stk.empty());
}
int main()
{
    node *root = NULL;

    root = init(1); // root node

    //       1

    insert_left(root, 2);
    insert_right(root, 3);

    //        1
    //       / \'
    //      2   3

    insert_left(root->left, 4);
    insert_right(root->left, 5);

    //        1
    //       / \'
    //      2   3
    //      / \'
    //     4   5

    insert_left(root->right, 6);
    insert_right(root->right, 7);

    //        1
    //       / \'
    //       2   3
    //      / \' / \'
    //     4   5 6  7

    postorder_recursive(root);
    cout << endl;
    postorder_iterative(root);

    return 0;
}