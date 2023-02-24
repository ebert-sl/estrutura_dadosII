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
  if(node == NULL) exit(1);
  node->data = data;
  node->left = left;
  node->right = right;
  return node; 
};

void print(struct node* node) {
  if(!empty_tree(node)) {
    printf("<%i ", node->data);
    print(node->left);
    print(node->right);
  } else {
    printf("<>");
  };
};

int tree_height(struct node* node) {
  if(!empty_tree(node)) {
    return 0;
  } else {
    int left_height = tree_height(node->left);
    int right_height = tree_height(node->right);
    if (left_height >= right_height) {
      return left_height + 1;
    } else {
      return right_height + 1;
    }
  }
}

void print_level(struct node* node, int level_node) {
  if(level_node == 0) {
    printf("%d -> ", node->data);
  } else {
      print_level(node->left, level_node - 1);
      print_level(node->right, level_node - 1);
  }
}

void print_levelorder(struct node* node) {
  int height = tree_height(node);
  for (int counter=0; counter<height; counter++) {
    print_level(node, counter);
  }
}

int main() {
  struct node* binarytree = newnode(1, newnode(2, emptynode(), emptynode()), newnode(3, emptynode(), emptynode()));
  print(binarytree);
  printf("\n");
  print_levelorder(binarytree);
};