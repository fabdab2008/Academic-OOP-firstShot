#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int element;
    int height;
    Node(int x)
    {
        element=x;
        this->left=NULL;
        this->right=NULL;
    }
};
int h(Node *u)
{
    return (u == NULL) ? -1 : u->height;
}
void LeftRotation(Node *&u)
{
    Node *v = u->right;
    u->right = v->left;
    v->left = u;
    u->height = max(h(u->right), h(u->left))+1;
    v->height = max(h(v->right), h(v->left))+1;
    u=v;
}
void RightRotation(Node *&u)
{
    Node *v = u->left;
    u->left = v->right;
    v->right = u;
    u->height = max(h(u->right), h(u->left))+1;
    v->height = max(h(v->right), h(v->left))+1;
    u=v;
}
void RightLeftRotation(Node *&u)
{
    RightRotation(u->right);
    LeftRotation(u);
}
void LeftRightRotation(Node *&u)
{
    LeftRotation(u->left);
    RightRotation(u);
}
void balance( Node *&u )
{
    if(u == NULL)
        return;
    if( h( u->left ) - h( u->right ) > 1 )
    {
        if( h( u->left->left ) >= h( u->left->right ) )
            RightRotation( u );
        else
            LeftRightRotation( u );
    }
    else if( h( u->right ) - h( u->left ) > 1 )
    {
        if( h( u->right->right ) >= h( u->right->left ) )
            LeftRotation(u);
        else
            RightLeftRotation(u);
    }
    else
        u->height = max( h(u->left), h(u->right) ) + 1;
}
void insertt( int x, Node *&u)
{
    if( u == NULL )
        u = new Node(x);
    else if( x < u->element )
        insertt( x,u->left );
    else if( u->element <x )
        insertt( x,u->right);
    balance(u);
}
Node* findMin(Node *u)
{
    if(u->left==NULL)
        return u;
    u=u->left;
}
void removee( int x, Node *&u )
{
    if( u == NULL )
        return;

    if( x < u->element )
        removee( x, u->left );
    else if( u->element < x )
        removee( x, u->right );
    else if( u->left != NULL && u->right != NULL ) // Two children
    {
        u->element = findMin( u->right )->element;
        removee( u->element, u->right );
    }
    else //One child or no child
    {
        Node *oldNode = u;
        u = ( u->left != NULL ) ? u->left : u->right;
        delete oldNode;
    }
    balance( u );
}



void inorder(Node *u)
{
    if(u==NULL)
        return;
    inorder(u->left);
    cout<<u->element<<"  "<<h(u)<<endl;
    inorder(u->right);
}

int main()
{
    Node *root=NULL;
    while(1)
    {
        cout<<"1. Insert in AVL   2. In-order Traversal    3. Delete  4. End"<<endl<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int x;
            cout<<"Enter value to insert: ";
            cin>>x;
            insertt(x,root);
        }
        else if(choice==2)
        {
            cout<<"In-order traversal of the tree"<<endl;
            inorder(root);
        }
        else if(choice==3)
        {
            int x;
            cout<<"Enter value to delete: ";
            cin>>x;
            removee(x,root);
        }
        else if(choice==4)
        {
            break;
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
            break;
        }
        cout<<endl;
    }
}
/*inputs:

1 16
1 14
1 15
1 6
1 7
1 19
1 5
1 2
1 4

*/
