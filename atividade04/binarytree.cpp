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

int total_nodes(struct node* node) {
  if(!empty_tree(node)) {
    int counter_left = total_nodes(node->left);
    int counter_right = total_nodes(node->right);
    return 1 + counter_left + counter_right;
  } else {
    return 0;
  }
};

bool identical_tree(struct node* node, struct node* node2) {
  if(empty_tree(node) && empty_tree(node2)) {
    return true;
  }
  if(!empty_tree(node) && !empty_tree(node2)) {
    return(node->data == node2-> data
          && identical_tree(node->left, node2->left)
          && identical_tree(node->right, node2->right));
  }
  return false;
}

int main() {
  struct node* binarytree = newnode(1, 
                                    newnode(2, 
                                            newnode(4, emptynode(), emptynode()), 
                                            newnode(6, emptynode(), emptynode())), 
                                    newnode(3, 
                                            newnode(5, emptynode(), emptynode()), 
                                            emptynode()));

  struct node* binarytree2 = newnode(1, 
                                    newnode(2, 
                                            newnode(4, emptynode(), emptynode()), 
                                            newnode(6, emptynode(), emptynode())), 
                                    newnode(3, 
                                            newnode(5, emptynode(), emptynode()), 
                                            newnode(7, emptynode(), emptynode())));

  if(identical_tree(binarytree, binarytree2)) {
    printf("As arvores sao identicas.");
  } else {
    printf("As arvores nao sao identicas.");
  }
};