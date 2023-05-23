#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stive&cozi.h"
#include <math.h>
typedef struct tree
{
    float points;
    char *name_team;
    struct tree *left, *right;
} Tree;

typedef struct avl
{
    float points;
    int height;
    char *name_team;
    struct avl *left, *right;
} AVL;

int compare(float points1, float points2, char *name1, char *name2);
Tree *newNode(float points_t, char *name);
Tree *AddToTree(Tree *root, float points_t, char *name);
Tree *maxValueNode(Tree *root);
Tree *minValueNode(Tree *root);
void displayBST(Tree *root, FILE *f, Tree **list_avl_front, Tree **list_avl_rear);
void printlevel(AVL *root, int level, FILE *f);
int nodeHeight(AVL *root);
AVL *RightRotation(AVL *z);
AVL *LeftRotation(AVL *z);
AVL *LRRotation(AVL *Z);
AVL *RLRotation(AVL *Z);
AVL *insert_avl(AVL *root, Tree *aux);
int maxi(int a, int b);
void print2ndlvl(AVL *root, FILE *f);
