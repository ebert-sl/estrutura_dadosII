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

/* Imprime o total de nós da árvore */
int total_nodes(struct node* node) {
  if(!empty_tree(node)) {
    int counter_left = total_nodes(node->left);
    int counter_right = total_nodes(node->right);
    return 1 + counter_left + counter_right;
  } else {
    return 0;
  }
};

/* Imprime o total de folhas */
int total_leaves(struct node* node) {
  if(empty_tree(node)) {
    return 0;
  };
  if(empty_tree(node->left) && empty_tree(node->right)) {
    return 1;
  } else {
    return total_leaves(node->left) + total_leaves(node->right);
  };
};

/* Calcula a altura da árvore */
int tree_height(struct node* node) { 
  if(empty_tree(node)) {
    return -1;
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

/* Procura um nó na árvore */
void search_node(struct node* node, int value) {
  if(!empty_tree(node)) {
    if(node->data == value) {
      printf("No encontrado com sucesso!\n");
    } else {
      search_node(node->left, value);
      search_node(node->right, value);
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
  printf("%i nos encontrados.\n", total_nodes(binarytree));
  printf("%i folhas encontradas.\n", total_leaves(binarytree));
  printf("Altura: %i\n", tree_height(binarytree));   
  search_node(binarytree, 8);                                      
};