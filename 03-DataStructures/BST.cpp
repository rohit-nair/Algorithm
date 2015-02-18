# include<iostream>

class tree {
    public:
        int item;
        tree *parent;
        tree *left;
        tree *right;
};

tree *search_tree(tree *t, int x)
{
    if (t == NULL)
        return NULL;
    if (t->item == x)
        return t;
    if (t->item < x)
        return search_tree(t->left, x);
    else
        return search_tree(t->right, x);

}

tree *minimum(tree *t)
{
    if (t == NULL) return NULL;
    tree *temp = t;
    while (temp != NULL)
    {
        if (t->left != NULL)
            temp = t->left;
    }
    return temp;
}

void traverse_tree(tree *t)
{
    if (t != NULL)
    {
        traverse_tree(t->left);
        std::cout << t->item;
        traverse_tree(t->right);
    }
}

void insert_tree(tree** t, int x, tree* parent)
{
    if (*t == NULL)
    {
        tree* n = new tree();
        n->left = n->right = NULL;
        n->item = x;
        n->parent = parent; // Can't I assign *t instead?
        *t = n;
        return;
    }
    if ((*t)->item < x)
        insert_tree(&((*t)->left), x, *t);
    else
        insert_tree(&((*t)->right), x, *t);

}

void delete_tree(tree** t, int x)
{
    if (*t == NULL)
        return;

    if ((*t)->item < x)
        delete_tree(&(*t)->left, x);
    else if ((*t)->item > x)
        delete_tree(&(*t)->right, x);
    else
    {
        if ((*t)->left == NULL && (*t)->right == NULL)
            *t = NULL;
        else if ((*t)->left == NULL)
            *t = (*t)->right;
        else if ((*t)->right == NULL)
            *t = (*t)->left;
        else
        {
            tree* temp = minimum((*t)->right);
            temp->right = (*t)->right;
            *t = temp;
            delete_tree(&(*t)->right, temp->item);
        }

    }

}

int main()
{
    tree *myTree = NULL;
    insert_tree(&(myTree), 5, myTree);

    search_tree(myTree, 5);
    return 0;
}
