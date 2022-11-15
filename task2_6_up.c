

#include <stdio.h>
#include <stdlib.h>
struct node {
  int key;
  struct node *left, *right;
};
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d\t ", root->key);
    inorder(root->right);
  }
}

int *search(struct node *root, int key)
{
    if ((root == NULL) || (root -> key == key))
        return root;
    if (key < root -> key)
        return search(root -> left, key);
    else return search(root -> right, key);
}
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
int main() {
    struct node *root = NULL;
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
                root = insert(root,atoi(chislo));
            }
        }
        else if(ch[0] == '-'){
            if(!search(root,atoi(chislo))){
                printf("\nЧисла нет в дереве \n");
            }
            else{
                printf("\nЧисло удалено из дерева!\n");
                root = deleteNode(root,atoi(chislo));
            }
        }
        else if(ch[0] == 'i'){
            inorder(root);
            printf("\n");
        }
    }
}