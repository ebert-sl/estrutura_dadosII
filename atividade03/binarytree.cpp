#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* emptynode(void) {
  return NULL;
}

int empty_tree(struct node* node) {
  return node == NULL;
};

struct node* newnode(int data, struct node* left, struct node* right) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  if(empty_tree(node)) {
    exit(1);
  };
  node->data = data;
  node->left = left;
  node->right = right;
  return node; 
};

bool strict_tree(struct node* node) {
  if(empty_tree(node)) {
    return true;
  }
  if(empty_tree(node->left) && empty_tree(node->right)) {
    return true;
  }
  if((node->left) && (node->right)) {
    return strict_tree(node->left) && strict_tree(node->right);
  }
  return false;
};

int main() {
  struct node* binarytree = newnode(1, 
                                    newnode(2, 
                                            newnode(4, emptynode(), emptynode()), 
                                            newnode(6, emptynode(), emptynode())), 
                                    newnode(3, 
                                            newnode(5, emptynode(), emptynode()), 
                                            newnode(7, emptynode(), emptynode())));

  if(strict_tree(binarytree)) {
    printf("A arvore e estritamente binaria");
  } else {
    printf("A arvore nao e estritamente binaria.");
  }
};