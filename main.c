/*BINARY TREES IN C
SUBJECT: DATA STRUCTURES
PROFESSOR: MARIO LIZIER*/

#include <stdio.h>
#include <stdlib.h>

typedef char T;

#define MAX 10
#define NULL ((void*)0)

//struct to define a node
typedef struct node{
  T data;
  unsigned nchild;
  struct node *left, *right;
  //struct node *children[MAX];
  //struct node *father;
}node;

//function to create a new node
node* createNode(T data){
  node* newNode = (node*)malloc(sizeof(node));
  if(newNode==NULL) {printf("memory allocation failled!\n"); return NULL;}
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
} 

//function to insert a node into the binary tree
node* insertNode(node* root, T data){
  if (root == NULL) {
        root = createNode(data);
        return root;
    }
  if(data < root->data) root->left = insertNode(root->left, data);
  else if(data > root->data) root->right = insertNode(root->right, data);
  return root;
}

//function to calculate the number of nodes in a tree
unsigned size(node* root){
  if(root==NULL) return 0;
  int leftsize = size(root->left);
  int rightsize = size(root->right);
  return 1 + leftsize + rightsize;
}

void inorderTraversal(node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}


/*unsigned size_recursive(node* root){
    if(root){
      unsigned acc = 0;
      for(unsigned i=0; i< root->nchild; i++)
        acc += size_recursive(root->children[i]);
      return 1+acc;
    }
  }*/

/*unsigned size_iterative(node* root){
  if(root){
    unsigned count = 0;
    Conjunct c; //pile? line?
    initialize(&c, root);
    while(!empty(&c)){
      remove(&c, &root);
      count++;
      for(unsigned i=0; i<root->nchild; i++)
        insert(&c. root->children[i]);
    }
    destroy(&c);
    return count;
  }
  return 0;
}
*/

int main(void) {
  printf("Data Structures studies in C\n");
  printf("Binary tree\n");

  //initializing
  node* root = createNode('A');
  //constrcting
  root->left = createNode('B');
  root->right = createNode('C');
  root->left->left = createNode('D');
  root->left->right = createNode('E');
  root->right->left = createNode('F');
  
  printf("%u elements\n", size(root));
  printf("In-order traversal: ");
  inorderTraversal(root);
  printf("\n\n");

  //initializing another tree;
  node* root1 = NULL;
  root1 = insertNode(root1, 'C');
  root1 = insertNode(root1, 'A');
  root1 = insertNode(root1, 'B');
  root1 = insertNode(root1, 'Z');

  printf("%u elements\n", size(root1));
  printf("In-order traversal: ");
  inorderTraversal(root1);
  
  //deallocation
  
  return 0;
}