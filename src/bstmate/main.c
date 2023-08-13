#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Retorna true si ambos strings son iguales */
bool string_equals(char* string1, char* string2) {
  return !strcmp(string1, string2);
}


/* Revisa que los parametros del programa sean válidos */
bool check_arguments(int argc, char** argv) {
  if (argc != 3) {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    exit(1);
  }
  return true;
}


/* CREAR ARBOL */
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val, int invert) {

    // Creamos arbol normal, shijos izquierdos menores e hijos derechos mayores.
    if (invert == 0 || invert % 2 == 0) {
        if (root == NULL) {
            return newNode(val);
        }
        if (val < root->val) {
            root->left = insert(root->left, val, 0);
        } else {
            root->right = insert(root->right, val, 0);
        }
    } 
    else {
        if (root == NULL) {
            return newNode(val);
        }
        if (val > root->val) {
            root->left = insert(root->left, val, 1);
        } else {
            root->right = insert(root->right, val, 1);
        }
    }
    return root;
}


/* PATH */
bool path_search(struct TreeNode* node, int value, char* path) {
    if (node == NULL) {
        sprintf(path + strlen(path), "X");
        return false;
    }
    
    if (node->val == value) {
        sprintf(path + strlen(path), "%d", node->val);
        return true;
    }

    char temp[100];
    bool found = false;

    if (node->left != NULL && node->left->val == value) {
        sprintf(temp, "%d ", node->val);
        sprintf(path + strlen(path), "%s", temp);
        sprintf(temp, "%d ", node->left->val);
        sprintf(path + strlen(path), "%s", temp);
        found = true;
    }
    else if (node->right != NULL && node->right->val == value) {
        sprintf(temp, "%d ", node->val);
        sprintf(path + strlen(path), "%s", temp);
        sprintf(temp, "%d ", node->right->val);
        sprintf(path + strlen(path), "%s", temp);
        found = true;
    }

    if (!found) {
        sprintf(temp, "%d ", node->val);
        sprintf(path + strlen(path), "%s", temp);

        if (value < node->val && node->left != NULL) {
            found = path_search(node->left, value, path);
        }
        else if (value > node->val && node->right != NULL) {
            found = path_search(node->right, value, path);
        }

        if (!found) {
            // Agregar la X al final del camino cuando no se encuentra el valor buscado
            sprintf(path + strlen(path), "X");
        }
    }

    return found;
}

char* get_path_to_value(struct TreeNode* root, int value) {
    char* path = (char*)malloc(sizeof(char)*10000);
    memset(path, 0, sizeof(char)*10000);
    path_search(root, value, path);
    return path;
}


/* DEEP */
int find_depth(struct TreeNode* root, int value) {
    if (root == NULL) {
        return -1; // no se encontró el valor
    }
    if (root->val == value) {
        return 0; // se encontró el valor en el root
    }
    int left_depth = find_depth(root->left, value);
    if (left_depth >= 0) {
        return left_depth + 1; // se encontró el valor en el subárbol izquierdo
    }
    int right_depth = find_depth(root->right, value);
    if (right_depth >= 0) {
        return right_depth + 1; // se encontró el valor en el subárbol derecho
    }
    return -1; // no se encontró el valor en el árbol
}


/* ORDER */
void order_helper(struct TreeNode* root, char* result, int* index, int* size) {
    if (root != NULL) {
        order_helper(root->left, result, index, size);
        char val_str[32];
        sprintf(val_str, "%d ", root->val);
        int val_len = strlen(val_str);
        if (*index + val_len >= *size) {
            // El resultado excede el tamaño del buffer, aumentar el tamaño del buffer
            *size *= 2;
            result = (char*)realloc(result, (*size) * sizeof(char));
        }
        strcat(result, val_str);
        *index += val_len;
        order_helper(root->right, result, index, size);
    }
}


/* ORDER */
char* order(struct TreeNode* root) {
    char* result = (char*)malloc(10000 * sizeof(char));
    memset(result, '\0', 10000 * sizeof(char));
    int index = 0;
    int size = 10000;
    order_helper(root, result, &index, &size);
    return result;
}


/* DEEP ORDER */
char* deep_order(struct TreeNode* root) {
    if (root == NULL) {
        return "";
    }
    char* result = malloc(sizeof(char) * 10000); // Asignar memoria para almacenar la salida
    char* current = result;
    // Create an empty queue for level order traversal
    struct TreeNode* queue[10000];
    int front = 0;
    int rear = 0;
    queue[rear] = root;
    rear++;
    while (front != rear) {
        // Dequeue the front node and print it
        struct TreeNode* node = queue[front];
        front++;
        current += sprintf(current, "%d ", node->val);
        // Enqueue the left child
        if (node->left != NULL) {
            queue[rear] = node->left;
            rear++;
        }
        // Enqueue the right child
        if (node->right != NULL) {
            queue[rear] = node->right;
            rear++;
        }
    }
    return result;
}


/* IMPRIR NODOS DEL ARBOL EN ORDEN ASCENDENTE */
void inorder_traversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->val);
    inorder_traversal(root->right);
}


/* IMPRIMIR ARBOL NIVEL POR NIVEL, DE IZQUIERDA A DERECHA */
char* print_tree_levels(struct TreeNode *root) {
    if (root == NULL) {
        return "";
    }

    // create queue for BFS
    struct Queue {
        struct TreeNode *node;
        struct Queue *next;
    };
    struct Queue *front = NULL;
    struct Queue *rear = NULL;

    // enqueue root node
    struct Queue *new_queue_node = (struct Queue*) malloc(sizeof(struct Queue));
    new_queue_node->node = root;
    new_queue_node->next = NULL;
    front = rear = new_queue_node;

    // create string to hold the node values
    char* nodes = (char*)malloc(sizeof(char)*10000);
    nodes[0] = '\0';

    while (front != NULL) {
        // dequeue node
        struct TreeNode *current = front->node;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }

        // append node value to string
        char str[10];
        sprintf(str, "%d", current->val);
        strcat(nodes, str);
        strcat(nodes, " ");

        // enqueue children nodes
        if (current->left != NULL) {
            struct Queue *new_queue_node = (struct Queue*) malloc(sizeof(struct Queue));
            new_queue_node->node = current->left;
            new_queue_node->next = NULL;
            if (rear == NULL) {
                front = rear = new_queue_node;
            } else {
                rear->next = new_queue_node;
                rear = new_queue_node;
            }
        }
        if (current->right != NULL) {
            struct Queue *new_queue_node = (struct Queue*) malloc(sizeof(struct Queue));
            new_queue_node->node = current->right;
            new_queue_node->next = NULL;
            if (rear == NULL) {
                front = rear = new_queue_node;
            } else {
                rear->next = new_queue_node;
                rear = new_queue_node;
            }
        }
    }
    return nodes;
}


/* MAIN */
int main(int argc, char** argv) {

  //printf("Main start\n");
  check_arguments(argc, argv);

  FILE* input_file = fopen(argv[1], "r");
  FILE* output_file = fopen(argv[2], "w");

  int n, i, N_EVENTS;
  fscanf(input_file, "%d", &n);
  //printf("Nodo inicial: %d\n", n);

  int nodes[n];
  for (i = 0; i < n; i++) {
    fscanf(input_file, "%d", &nodes[i]);
  }

  // Nodo inicial
  struct TreeNode* root = newNode(nodes[0]);

  // Insertar nodos en el árbol
  for (int i = 1; i < n; i++) {
    insert(root, nodes[i], 0);
  }

  // Recorrer consultas
  fscanf(input_file, "%d", &N_EVENTS);
  //printf("Cantidad de consultas: %d\n", N_EVENTS);

  // String para guardar la instrucción actual 
  char command[32];
  int invertion_num = 0;

  for (int event = 0; event < N_EVENTS; event++) {
    fscanf(input_file, "%s", command);

    if (string_equals(command, "PATH")) {
        int value;
        fscanf(input_file, "%d", &value);
        char* path = get_path_to_value(root, value);
        int len = strlen(path);

        // Buscar la cantidad de caracteres "X" al final de la cadena.
        int num_X = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (path[i] == 'X') {
                num_X++;
            } else {
                break;
            }
        }

        // Eliminar todos los caracteres "X" excepto uno al final de la cadena.
        if (num_X > 1) {
            path[len - num_X + 1] = '\0';
            fprintf(output_file, "%s\n", path);
        }
        else {
            fprintf(output_file, "%s\n", path);
        }

    }

    else if (string_equals(command, "DEEP")) {
      int number;
      fscanf(input_file, "%d", &number);
      int depth = find_depth(root, number);
      //fprintf(output_file, "DEEP: %d\n", depth);
      fprintf(output_file, "%d\n", depth);
    }

    else if (string_equals(command, "ORDER")) {
      //fprintf(output_file, "ORDER: %s\n", order(root));
      fprintf(output_file, "%s\n", order(root));
    }

    else if (string_equals(command, "DEEP-ORDER")) {
      //fprintf(output_file, "DEEP-ORDER: %s\n", deep_order(root));
      fprintf(output_file, "%s\n", deep_order(root));
    }

    else if (string_equals(command, "INVERT")) {
        struct TreeNode* root = newNode(nodes[0]);
        // Insertar nodos en el árbol
        invertion_num += 1;

        for (int i = 1; i < n; i++) {
            insert(root, nodes[i], invertion_num);
        }
        //fprintf(output_file, "INVERT: %s\n", print_tree_levels(root));
        fprintf(output_file, "%s\n", print_tree_levels(root));
    }
  }

  fclose(input_file);
  fclose(output_file);
  return 0;
}