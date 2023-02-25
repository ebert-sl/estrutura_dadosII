/* Criação da árvore, impressão dos nós (mostrando raiz e os filhos da raiz) 
e percurso em largura */

#include <stdio.h>
#include <stdlib.h>

/* Estrutura do nó */
struct node {
  int data;
  struct node* left;
  struct node* right;
};

/* Nó vazio */
struct node* emptynode(void) {
  return NULL;
}

/* Checa se a arvore binária está vazia */
int empty_tree(struct node* node) {
  return node == NULL;
};

/* Cria um novo nó */
struct node* newnode(int data, struct node* left, struct node* right) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  if(empty_tree(node)) {
    return 0;
  };
  node->data = data;
  node->left = left;
  node->right = right;
  return node; 
};

/* Imprime a árvore */
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
    }
  };
  printf(">");
};

/* Calcula a altura da árvore */
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

/* Imprime um nível da árvore */
void print_level(struct node* node, int level_node) {
  if(empty_tree(node)) {
    return;
  };
  if(level_node == 1) {
    printf("%d ", node->data);
  } else {
      print_level(node->left, level_node - 1);
      print_level(node->right, level_node - 1);
  };
};

/* Imprime todos os níveis da árvore por percurso em largura */
void print_levelorder(struct node* node) {
  int height = tree_height(node);
  int counter;
  for (counter = 1; counter <= height; counter++) {
    print_level(node, counter);
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
  printf("Arvore binaria\n");
  print(binarytree);
  printf("\nArvore binaria em percurso em largura\n");
  print_levelorder(binarytree);
};