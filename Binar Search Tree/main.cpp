#include <iostream>
#include <string>

using namespace std;
template <class M>
class  BST
{
private:
    //—“–” “”–¿
    struct Node
    {
        M data;
        Node *left;
        Node *right;
        int L;
    };
    typedef Node* PNode;
    PNode Root;

    //ƒŒ¡¿¬À≈Õ»≈ ›À≈Ã≈Õ“¿
    void Add(PNode &H, M x)
    {
        if(H)
        {
            if(x<H->data)
            {
                Add(H->left, x);
                if(H->right)
                    H->L = max(H->right->L, H->left->L)+1;
                else
                    H->L = H->left->L+1;

            }
            else if(x > H->data)
            {
                Add(H->right, x);
                if(H->left)
                    H->L = max(H->right->L, H->left->L)+1;
                else
                    H->L = H->right->L+1;
            }
        }
        else
        {
            H = new Node;
            H->data = x;
            H->left = NULL;
            H->right = NULL;
            H->L = 1;
        }
    }

    //œ≈◊¿“‹

    void Print(PNode T, const int level = 0)
    {
        if (T->left)
            Print(T->left, level + 1);
        for (int i = 0; i < level; i++)
            cout << "        ";
        cout << "-|"<<T->data<<"::"<<T->L <<"|-"<< endl;
        cout<<endl;
        if (T->right)
            Print(T->right, level + 1);

    }

    //”ƒ¿À≈Õ»≈

    void Delete(PNode &H)
    {
        if(H)
        {
            Delete(H->left);
            Delete(H->right);
            delete H;
        }
    }

    //Õ¿…“» —¿ÃŒ≈ œ–¿¬Œ≈

    M find_right(PNode &H)
    {
        if(H->right==NULL)
        {
            M y = H->data;
            if(H->left == NULL)
            {
                delete H;
                H = NULL;
            }
            else
            {
                PNode P = H;
                H = H->left;
                delete P;
            }
            return y;
        }
        return find_right(H->right);
    }

    //”ƒ¿À≈Õ»≈

    void Del_elem(PNode &H, M x)
    {
        if(H)
        {
            if(x<H->data)
                Del_elem(H->left, x);
            else if(x>H->data)
                Del_elem(H->right, x);
            else
            {
                if(H->left == NULL && H->right == NULL)
                {
                    delete H;
                    H = NULL;
                }
                else if(H->left==NULL&&H->right!=NULL)
                {
                    PNode P = H;
                    H = H->right;
                    delete P;
                }
                else if(H->left!=NULL&&H->right==NULL)
                {
                    PNode P = H;
                    H = H->left;
                    delete P;
                }
                else
                {
                    H->data = find_right(H->left);
                }
            }
        }
    }

public:

    BST()
    {
        Root = NULL;
    }

    void add(M x)
    {
        Add(Root, x);
    }

    void print()
    {
        PNode H = Root;
        cout<<endl<<endl<<endl;
        Print(H);
    }

    void del_elem(M x)
    {
        Del_elem(Root, x);
    }

    ~BST()
    {
        Delete(Root);
    }

};

int main()
{
    char x;
    BST <char> A;
    string s = "DBEFPOIUYTREXCVBML";
    for(int i = 0; i<s.size(); i++)
    {
        x = s[i];
        A.add(x);
    }
    A.add('G');
    A.print();
    return 0;
}

//8
//47261087
