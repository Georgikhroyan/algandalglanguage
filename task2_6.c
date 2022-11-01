#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;
/*Используем typedef для создания нового типа, чтобы в дальнейшем не писать слово struct.
int key — ключ, может быть любого типа.
struct tree *left —  указатель на левое поддерево.
struct tree *right — указатель на правое поддерево.
struct tree *parent — указатель на родителя.
node — название структуры.*/
node *create(node *root, int key)
{
// Выделение памяти под корень дерева
    node *tmp = malloc(sizeof(node));
// Присваивание значения ключу
    tmp -> key = key;
// Присваивание указателю на родителя значения NULL
    tmp -> parent = NULL;
// Присваивание указателю на левое и правое поддерево значения NULL
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}
/*Мы инициализируем дерево отдельной функцией для того, чтобы облегчить процесс добавления узлов в дерево. Другими словами, мы создаем корень бинарного дерева поиска.*/
node *add(node *root, int key)
{
    node *root2 = root, *root3 = NULL;
// Выделение памяти под узел дерева
    node *tmp = malloc(sizeof(node));
// Присваивание значения ключу
    tmp -> key = key;
/* Поиск нужной позиции для вставки (руководствуемся правилом 
вставки элементов, см. начало статьи, пункт 3) */
    while (root2 != NULL)
    {
        root3 = root2;
        if (key < root2 -> key)
            root2 = root2 -> left;
        else
            root2 = root2 -> right;
    }
/* Присваивание указателю на родителя значения указателя root3 
(указатель root3 был найден выше) */
    tmp -> parent = root3;
// Присваивание указателю на левое и правое поддерево значения NULL
    tmp -> left = NULL;
    tmp -> right = NULL;
/* Вставляем узел в дерево (руководствуемся правилом
вставки элементов, см. начало статьи, пункт 3) */
    if (key < root3 -> key) root3 -> left = tmp;
    else root3 -> right = tmp;
    return root;
}
/*tmp -> left и tmp -> right имеют значение NULL, так как указатель tmp расположен в конце дерева.
Указатель root2 использовался для того, чтобы сохранить адрес на родителя вставляемого узла.
Мы не проверяем дерево на пустоту, так как ранее дерево был инициализировано (имеется корень).*/
node *search(node * root, int key)
{
// Если дерево пусто или ключ корня равен искомому ключу, то возвращается указатель на корень
    if ((root == NULL) || (root -> key == key))
        return root;
// Поиск нужного узла
    if (key < root -> key)
        return search(root -> left, key);
    else return search(root -> right, key);
}
/*Данная функция рекурсивная, поэтому комментарий «Если дерево пусто или ключ корня равен искомому ключу, то возвращается указатель на
корень» является не совсем верным, потому что root указывает на корень только во время первой итерации, далее root ссылается на другие узлы дерева,
но из-за рекурсивности функции условие if ((root == NULL) || (root -> key == key)) будет проверяться всегда.*/
// Минимальный элемент дерева
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
/*Итак, пришло время освоить, наверное, самое сложное действие с деревом, а именно, удалить узел
. Удаление элемента из дерева реализуется намного сложнее, чем в списках. Это связано с особенностью построения деревьев (см. начало статьи, пункт 3).*/
/*Рассмотрим самый простой случай: у удаляемого узла нет левого и правого поддерева. В данной ситуации мы просто удаляем данный лист (узел).*/
/*У удаляемого узла одно поддерево. В данной ситуации мы просто удаляем данный узел, а на его место ставим поддерево.*/
/*Самый сложный случай: у удаляемого узла существуют оба поддерева. В данной ситуации необходимо сначала найти следующий за удаляемым элемент, а потом его поставить на место удаляемого элемента.*/
node *succ(node *root)
{
    node *p = root, *l = NULL;
// Если есть правое поддерево, то ищем минимальный элемент в этом поддереве
    if (p -> right != NULL)
        return min(p -> right);
/* Правое дерево пусто, идем по родителям до тех пор,
пока не найдем родителя, для которого наше поддерево левое */
    l = p -> parent;
    while ((l != NULL) && (p == l -> right))
    {
        p = l;
        l = l -> parent;
    }
    return l;
}
/*Общая функция поиска следующего за удаляемым элемента:*/
    /*В нашем случае из данного кода нужна только первая часть, так как поиск следующего за удаляемым элемента нужен тогда, когда у удаляемого узла существуют оба поддерева.*/
node *delete(node *root, int key)
{
// Поиск удаляемого узла по ключу
    node *p = root, *l = NULL, *m = NULL;
    l = search(root, key);
// 1 случай
    if ((l -> left == NULL) && (l -> right == NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right = NULL;
        else m -> left = NULL;
        free(l);
    }
// 2 случай, 1 вариант - поддерево справа
    if ((l -> left == NULL) && (l -> right != NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right = l -> right;
        else m -> left = l -> right;
        free(l);
    }
// 2 случай, 2 вариант - поддерево слева
    if ((l -> left != NULL) && (l -> right == NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right = l -> left;
        else m -> left = l -> left;
        free(l);
    }
// 3 случай
    if ((l -> left != NULL) && (l -> right != NULL))
    {
        m = succ(l);
        l -> key = m -> key;
        if (m -> right == NULL)
            m -> parent -> left = NULL;
        else m -> parent -> left = m -> right;
        free(m);
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

