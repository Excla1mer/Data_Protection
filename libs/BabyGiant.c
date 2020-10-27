#include "headers.h"

typedef struct tree
{
    unsigned long long key;
    unsigned long long index;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

node *create(node *root, unsigned long long key, unsigned long long index)
{
// Выделение памяти под корень дерева
    node *tmp = malloc(sizeof(node));
// Присваивание значения ключу
    tmp -> key = key;
    tmp -> index = index;
// Присваивание указателю на родителя значения NULL
    tmp -> parent = NULL;
// Присваивание указателю на левое и правое поддерево значения NULL
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}

node *add(node *root, unsigned long long key, unsigned long long index)
{
    node *root2 = root, *root3 = NULL;
// Выделение памяти под узел дерева
    node *tmp = malloc(sizeof(node));
// Присваивание значения ключу
    tmp -> key = key;
    tmp -> index = index;
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

node *search(node * root, unsigned long long key)
{
// Если дерево пусто или ключ корня равен искомому ключу, то возвращается указатель на корень
    if ((root == NULL) || (root -> key == key))
        return root;
// Поиск нужного узла
    if (key < root -> key)
        return search(root -> left, key);
    else return search(root -> right, key);
}

unsigned long long BabyGiant(unsigned long long a, unsigned long long y, 
    unsigned long long p){
    unsigned long long i, j, k, m, *giant;
    unsigned long long x = -1;
    k = ceill(sqrt(p));
    m = k;
    node * tree;
    node * tmp;
    //Baby step
    for(j = 0; j < m; j++){
        if( j == 0 )
            tree = create(tree, (powMod(a, j, p) * (y % p)) % p, j);
        else
            add(tree, (powMod(a, j, p) * (y % p)) % p, j); 
    }
    //Giant step
    giant = (unsigned long long*)malloc((k + 1) * sizeof(unsigned long long));
     for(i = 1; i <= k; i++){
        giant[i] = powMod(a, (i * m), p); 
    }
    //x
    for(i = 1; i <= k; i++) {
        tmp = search(tree, giant[i]);
        if(tmp == NULL)
            continue;
        if(tmp->key == giant[i]) {
            x = (i * m)-tmp->index;
            break;
        }        
    }

    free(giant);

    if(tmp == NULL)
        return -1;
    else    
        return x;
}