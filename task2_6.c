#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

node *create(node *root, int key)
{
    node *tmp = malloc(sizeof(node));
    tmp -> key = key;
    tmp -> parent = NULL;
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}
node *add(node *root, int key)
{
    node *root2 = root, *root3 = NULL;
    node *tmp = malloc(sizeof(node));
    tmp -> key = key;

    while (root2 != NULL)
    {
        root3 = root2;
        if (key < root2 -> key)
            root2 = root2 -> left;
        else
            root2 = root2 -> right;
    }

    tmp -> parent = root3;
    tmp -> left = NULL;
    tmp -> right = NULL;
    if (key < root3 -> key) root3 -> left = tmp;
    else root3 -> right = tmp;
    return root;
}
node *search(node * root, int key)
{
    if ((root == NULL) || (root -> key == key))
        return root;
    if (key < root -> key)
        return search(root -> left, key);
    else return search(root -> right, key);
}
node *min(node *root)
{
    node *l = root;
    while (l -> left != NULL)
        l = l -> left;
    return l;
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    if (root -> key)
        printf("%d ", root -> key);
    preorder(root -> left);}
node *succ(node *root)
{
    node *p = root, *l = NULL;
    if (p -> right != NULL)
        return min(p -> right);
    l = p -> parent;
    while ((l != NULL) && (p == l -> right))
    {
        p = l;
        l = l -> parent;
    }
    return l;
}
node *delete(node *root, int key)
{
    node *p = root, *l = NULL, *m = NULL;
    l = search(root, key);
    if ((l -> left == NULL) && (l -> right == NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right = NULL;
        else m -> left = NULL;
    }
    if ((l -> left == NULL) && (l -> right != NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right = l -> right;
        else m -> left = l -> right;
    }
    if ((l -> left != NULL) && (l -> right == NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right = l -> left;
        else m -> left = l -> left;
    }
            if ((l -> left != NULL) && (l -> right != NULL))
    {
        m = succ(l);
        l -> key = m -> key;
        if (m -> right == NULL)
            m -> parent -> left = NULL;
        else m -> parent -> left = m -> right;
    }
    return root;
}   


int main(){
node *root = NULL;
    root = create(root,0);
    int a;
    char ch[100];
    char e;
    char chislo[100];
 
    while(scanf( "%s", &ch)  && (e = getchar()) != EOF){
        for (int i = 0 ; i < 99 ;i++){
            chislo[i] = ch[i+1];
        }
        if(ch[0] == '?'){
            if(search(root,atoi(chislo))){
                printf("\n%d\tyes\n",atoi(chislo));
            }
            else{
                printf("\n%d\tno\n",atoi(chislo));
            }
        }
        else if(ch[0] == '+'){
            if(search(root,atoi(chislo))){
                printf("\nЧисло уже есть в дереве \n");
            }
            else{
                printf("\nЧисло добавлено в дерево!\n");
                add(root,atoi(chislo));
            }
        }
        else if(ch[0] == '-'){
            if(!search(root,atoi(chislo))){
                printf("\nЧисла нет в дереве \n");
            }
            else{
                printf("\nЧисло удалено из дерева!\n");
                delete(root,atoi(chislo));
            }
        }
        else if(ch[0] == 'p'){
            preorder(root);
        }
    }
}

