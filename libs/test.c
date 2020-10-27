#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

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

unsigned long long powMod(unsigned long long a, unsigned long long x, 
                          unsigned long long p)
{
  unsigned long long result = 1;
  int iter = 0;
  while(x)
  {
    result = (x&1) ? (result * a) % p : result;
    x = x >> 1; 
    a = (a * a) % p;
  }
  return result;
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
    
    return x;
}


int main() {

  unsigned long long a,y,p;
  //a = 3 y = 1 p = 7 {x == 6}
  //a = 88 y = 47 p = 107 {x == 62}
  //a = 2 y = 45 p = 61 {x == 34}
  //a = 1035274024 y = 740748997 p = 1665260969 { x = 1223800018 }
  //a = 109333856 y = 528976328 p = 1487211496 { x = 1442884666 }
  a = 88;
  y = 47;
  p = 107;
  

  printf("\t# a = %10lld\t#\n \t# y = %10lld\t#\n \t# p = %10lld\t#\n", a, y, p);
  printf("\t#########################\n");
  printf("\t# Result = %10lld\t#\n", BabyGiant(a, y, p));
  printf("\t#########################\n");
    return 0;
}

unsigned long long powMod(unsigned long long a, unsigned long long x, 
                          unsigned long long p)
{
  unsigned long long result = 1;
  int iter = 0;
  while(x)
  {
    result = (x&1) ? (result * a) % p : result;
    x = x >> 1; 
    a = (a * a) % p;
  }
  return result;
}
