#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
Node *buildtree(Node *root)
{

    cout << endl
         << "enter data" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "enter data for left of " << root->data;
    root->left = buildtree(root->left);
    cout << "enter data for Right of" << root->data;
    root->right = buildtree(root->right);
    return root;
}

void levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// inorder traversal LNR
//          1
//      3       5
//    7   11   17
// 2    5
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
//         1
//     3       5
//   7   11   17
// 2    5
// inorder traversal LNR
void Inorder(Node *root)
{
    Node *temp = root;
    stack<Node *> s;
    while (temp)
    {
        s.push(temp);
        temp = temp->left;

        while (!s.empty() && temp == NULL)
        {

            Node *test = s.top();
            s.pop();
            cout << test->data << " ";
            temp = test->right;
        }
    }
}
void Preorder(Node *root) // NLR
{
    Node *temp = root;
    stack<Node *> s;
    while (temp)
    {

        s.push(temp);
        cout << temp->data << " ";
        temp = temp->left;

        while (!s.empty() && temp == NULL)
        {

            Node *test = s.top();
            s.pop();
            // cout<<test->data<<" ";
            temp = test->right;
        }
    }
}
void Postorder(Node *root) // LRN
{
    Node *temp = root;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(temp);
    while (!s1.empty())
    {
        Node *test = s1.top();
        s1.pop();
        s2.push(test);
        if (test->left)
        {
            s1.push(test->left);
        }
        if (test->right)
        {
            s1.push(test->right);
        }
    }
    while (!s2.empty())
    {
        Node *k = s2.top();
        s2.pop();
        cout << k->data << " ";
    }
}

void *buildfromlevelorder(Node *&root)
{
    queue<Node *> q;
    cout << "enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "enter left node for" << temp->data << endl;
        int left;
        cin >> left;
        if (left != -1)
        {
            temp->left = new Node(left);
            q.push(temp->left);
        }
        cout << "enter right node for" << temp->data << endl;
        int right;
        cin >> right;
        if (right != -1)
        {
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
}
void Insert(Node* &root,int x)
{
    
    if(root==NULL)
    {
        
        Node* k=new Node(x);
        root=k;
    }
    else
    {
    if(x<root->data)
    {
        Insert(root->left,x);
    }
    if(x>root->data)
    {
        Insert(root->right,x);
    }
    }
}
Node* Max(Node* cur)  
{  
    while(cur->right != NULL) {  
        cur = cur->right;  
    }  
    return cur;  
}  

void Delete(Node* &root,int x)
{
    
    if(root==NULL)
    {
        
        cout<<"not found";
    }
    else if(x<root->data)
    {
        Delete(root->left,x);
    }
    else  if(x>root->data)
    {
        Delete(root->right,x);
    }
    else if(root->left&&root->right)
    {
        Node* temp=Max(root->left);
        root->data=temp->data;
        Delete(root->left,temp->data);
    }
    else
    {
        Node* temp=root;
        if(root->left==NULL&&root->right==NULL)
        {
            root=NULL;
        }
        else if(root->left!=NULL)
        {
            root=root->left;
        }
                else if(root->right!=NULL)
        {
            root=root->right;
        }

    }
    }


int main()
{
    Node *root = NULL;
    // buildfromlevelorder(root);
    Insert(root,4);
    Insert(root,1);
    Insert(root,10);
    Insert(root,3);
    Insert(root,5);
    cout << endl;
    cout << endl;
    levelordertraversal(root);
    preorder(root);
    Delete(root,3);
    cout<<endl;
    levelordertraversal(root);
    Preorder(root);


    return 0;
}