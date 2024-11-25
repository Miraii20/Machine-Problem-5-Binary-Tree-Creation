#include<iostream>
#include<string>
using namespace std;

class node
{
    string data;
    node *left, *right;
    friend class cbt;
};

class cbt
{
    node *root, *temp;
public:
    cbt();
    inline node* get_root() { return root; }
    void accept(int);
    node* insert(node*, node*);
    void display(node*, int);
    int height(node*);
    int bal(node*);
    bool check(node*);
    ~cbt();
};

cbt::cbt()
{
    root = NULL;
    temp = NULL;
}

bool cbt::check(node *r)
{
    if (r == NULL)
        return false;
    bool x = check(r->left);
    if (bal(r))
        return true;
    bool y = check(r->right);
    return x || y;
}

void cbt::accept(int t)
{
    if (t <= 0)
        return;

    temp = new node;
    temp->left = NULL;
    temp->right = NULL;

    cout << "\nEnter the root element (number or letter): ";
    cin >> temp->data;
    root = temp;

    for (int i = 1; i < t; i++)
    {
        temp = new node;
        temp->left = NULL;
        temp->right = NULL;

        cout << "\nEnter the element (number or letter): ";
        cin >> temp->data;
        root = insert(root, temp);
    }
}

node* cbt::insert(node* r, node* t)
{
    if (r == NULL)
        return t;

    if (t->data < r->data)
        r->left = insert(r->left, t);
    else if (t->data > r->data)
        r->right = insert(r->right, t);

    return r;
}

void cbt::display(node* r, int space)
{
    if (r == NULL)
        return;

    space += 5;

    display(r->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << r->data << endl;

    display(r->left, space);
}

int cbt::height(node* r)
{
    if (r == NULL)
        return 0;
    else
    {
        int lheight = height(r->left) + 1;
        int rheight = height(r->right) + 1;
        return (lheight > rheight) ? lheight : rheight;
    }
}

int cbt::bal(node* r)
{
    if (r == NULL)
        return 0;
    int lheight = height(r->left) + 1;
    int rheight = height(r->right) + 1;
    return (lheight - rheight);
}

cbt::~cbt()
{
    delete root;
    delete temp;
}

int main()
{
    cbt c;
    int ch, t;
    do
    {
        cout << "\n\n\t Binary Search Tree \n";
        cout << "\n1.Create";
        cout << "\n2.Insert";
        cout << "\n3.Display";
        cout << "\n4.Exit";
        cout << "\n>";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter the total number of elements: ";
            cin >> t;
            c.accept(t);
            break;
        case 2:
            c.accept(1);
            break;
        case 3:
            if (c.get_root() == NULL)
            {
                cout << "\n\t**** Tree doesn't exist *****\n";
                break;
            }
            cout << "\n\t  Tree Elements \n\n";
            c.display(c.get_root(), 0);
            break;
        case 4:
            cout << "\n\t**** EXIT ****\n";
            break;
        default:
            cout << "\n\t**** Invalid Choice ****\n";
            break;
        }
    } while (ch != 4);
    return 0;
}
