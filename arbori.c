#include "arbori.h"
int maxi(int a, int b)
{
    return ((a > b) ? a : b);
}
int compare(float points1, float points2, char *name1, char *name2)
{
    if (points1 < points2)
        return 1;
    else if (points1 == points2 && strcmp(name1, name2) < 0)
        return 1;
    else
        return 0;
}

Tree *newNode(float points_t, char *name)
{
    Tree *node = calloc(1, sizeof(Tree));
    node->points = points_t;
    // node->left = node->right = NULL;
    node->name_team = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(node->name_team, name);
    return node;
}

Tree *AddToTree(Tree *root, float points_t, char *name)
{
    if (root == NULL)
    {
        return newNode(points_t, name);
    }
    else
    {
        if (compare(points_t, root->points, name, root->name_team))
            root->left = AddToTree(root->left, points_t, name);
        else
            root->right = AddToTree(root->right, points_t, name);
        return root;
    }
}

Tree *maxValueNode(Tree *root)
{
    Tree *aux = root;
    while (aux->right != NULL)
    {
        aux = aux->right;
    }
    return aux;
}

Tree *minValueNode(Tree *root)
{
    Tree *aux = root;
    while (aux->left != NULL)
    {
        aux = aux->left;
    }
    return aux;
}

Tree* createListNode(char* key, float value) {
    Tree* newNode = malloc(sizeof(Tree));
    newNode->name_team = key;
    newNode->points = value;
    newNode->right = NULL;
    newNode->left= NULL;
    return newNode;
}

void displayBST(Tree *root, FILE *f ,Tree **list_avl_front,Tree **list_avl_rear)
{
    if (root == NULL)
    {
        return;
    }
    displayBST(root->right, f, list_avl_front,list_avl_rear);
    Tree* aux =createListNode(root->name_team,root->points);
    if(*list_avl_front == NULL){
        *list_avl_front = aux;
        *list_avl_rear = aux;
    }
    else{
        (*list_avl_rear)->right =aux;
        (*list_avl_rear) = aux;
    }
    fprintf(f, "%s", root->name_team);
    for (int i = 0; i < 34 - strlen(root->name_team); i++)
        fprintf(f, " ");
    fprintf(f, "-  %.2f\n", root->points);
    displayBST(root->left, f, list_avl_front,list_avl_rear);
}

int nodeHeight(AVL *root)
{
    if (root == NULL)
        return -1;
    else
        return root->height;
}

AVL *RightRotation(AVL *z)
{
    AVL *y = z->left;
    AVL *T3 = y->right;
    y->right = z;
    z->left = T3;
    z->height = maxi(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = maxi(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    return y;
}

AVL *LeftRotation(AVL *z)
{
    AVL *y = z->right;
    AVL *T2 = y->left;
    y->left = z;
    z->right = T2;
    z->height = maxi(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = maxi(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    return y;
}

AVL *LRRotation(AVL *Z)
{
    Z->left = LeftRotation(Z->left);
    return RightRotation(Z);
}

AVL *RLRotation(AVL *Z)
{
    Z->right = RightRotation(Z->right);
    return LeftRotation(Z);
}

AVL *insert_avl(AVL *root, Tree *aux)
{
    if (root == NULL)
    {
        root = malloc(sizeof(AVL));
        root->points = aux->points;
        root->name_team = aux->name_team;
        root->height = 0;
        root->left = root->right = NULL;
        return root;
    }
    else
    {
        if (compare(aux->points, root->points, aux->name_team, root->name_team))
            root->left = insert_avl(root->left, aux);
        else
            root->right = insert_avl(root->right, aux);
        return root;
    }
    root->height = 1 + maxi(nodeHeight(root->left), nodeHeight(root->right));
    int k = (nodeHeight(root->left) - nodeHeight(root->right));
    int cmp1  =compare(aux->points, root->left->points, aux->name_team, root->name_team);
    int cmp2 =compare(aux->points, root->right->points, aux->name_team, root->name_team);
    if (k > 1 && cmp1 == 1)
        return RightRotation(root);
    if (k < -1 && cmp2 == 0)
        return LeftRotation(root);
    if (k > 1 && cmp1 == 0)
        return RLRotation(root);
    if (k < -1 && cmp2 == 1)
        return LRRotation(root);
    return root;
}

void printlevel(AVL *root ,int level,FILE *f){
    if(root == NULL) return ;
    if (level == 1) fprintf(f,"%s\n",root->name_team);
    else if(level > 1){
        printlevel(root->right,level - 1,f);
        printlevel(root->left,level - 1,f);
    }
}

void print2ndlvl(AVL * root ,FILE *f){
    if(root == NULL) return ;
    if (root->height == 2){
        fprintf(f,"%s\n",root->name_team);
        return;
    }
    else {
        print2ndlvl(root->left,f);
        print2ndlvl(root->right,f);
    }
}




