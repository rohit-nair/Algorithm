#include <iostream>

class list {
    public:
        int item;
        list *next;
};

list *search_list(list *l, int x)
{
    if (l == NULL) return (NULL);

    if (l->item == x)
        return(l);
    else
        return(search_list(l->next, x));

}

void insert_list(list **l, int x)
{
    list *n = new list();
    n->item = x;
    n->next = *l;
    *l = n;
    return;
}


list *find_predecessor(list *l, int x)
{
    if (l == NULL || l->next == NULL)
    {
        std::cout <<  "List is null or has one item.\n";
        return(NULL);
    }

    if ((l->next)->item == x)
    {
        return(l);
    }
    else
    {
        return (find_predecessor(l->next, x));
    }

}

void delete_list(list *l, int x)
{
    if (l== NULL)
        return;

    list *p = find_predecessor(l, x);

    if (p == NULL)
    {
        std::cout << "Item not found.\n.\n";
        return;
    }
    
    list *t = p->next;
    p->next = (p->next)->next;
    std::cout << "Item to be deleted: " << t << " Value: " << t->item << "\n";
    free(t);
    std::cout << "Item deleted: " << t << " Value: " << t->item << "\n";
    std::cout << "Item deleted.\n";
}

void print_list(list *l)
{
    if (l == NULL)
    {
        std::cout << "NULL list.\n";
        return;
    }

    std::cout << "Item: " << l->item << "\n";
    return(print_list(l->next));
}


int main()
{
    list* head = NULL;

    print_list(head);
    insert_list(&head, 1);
    insert_list(&head, 2);
    insert_list(&head, 3);
    insert_list(&head, 4);

    print_list(head);
    
    delete_list(head, 2);
    
    print_list(head);
//    getchar();
    return(0);
}
