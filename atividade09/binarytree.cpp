#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void print(struct node* node) {
  if(!empty_tree(node)) {
    printf("<%i", node->data);
    if(node->left != NULL) {
      print(node->left);
    } else {
      printf("<>");
    };
    if(node->right != NULL) {
      print(node->right);
    } else {
      printf("<>");
    };
  };
  printf(">");
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

int tree_height(struct node* node) { 
  if(empty_tree(node)) {
    return 0;
  } else {
    int left_height = tree_height(node->left);
    int right_height = tree_height(node->right); 
    if (left_height >= right_height) {
      return left_height + 1;
    } else {
      return right_height + 1;
    };
  };
};

int main() {
  struct node* binarytree = newnode(1, 
                                    newnode(2, 
                                            newnode(4, emptynode(), emptynode()), 
                                            newnode(6, emptynode(), emptynode())), 
                                    newnode(3, 
                                            newnode(5, emptynode(), emptynode()), 
                                            newnode(7, emptynode(), emptynode())));

  print(binarytree);
  printf("\n%i nos encontrados.\n", total_nodes(binarytree));
  printf("Altura: %i\n", tree_height(binarytree));
  
  if(tree_height(binarytree) >= (1 + floor(log(total_nodes(binarytree))))) {
    printf("Arvore e completa.");
  } else {
    printf("Arvore e incompleta.");
  }
};