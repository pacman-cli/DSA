#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTree {
  int key;
  struct BinarySearchTree *left, *right;
};

struct BinarySearchTree *createNewNode(int value) {
  struct BinarySearchTree *node =
      (struct BinarySearchTree *)malloc(sizeof(struct BinarySearchTree));
  node->right = node->left = NULL;
  node->key = value;
  return node;
}

struct BinarySearchTree *insertNode(struct BinarySearchTree *node, int value) {
  if (node == NULL) {
    return createNewNode(value);
  }
  if (value < node->key) {
    node->left = insertNode(node->left, value);
  } else if (value >= node->key) {
    node->right = insertNode(node->right, value);
  }
  return node;
}

void inOrder(struct BinarySearchTree *root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
  }
}

void preOrder(struct BinarySearchTree *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(struct BinarySearchTree *root) {
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->key);
  }
}

struct BinarySearchTree *searchNode(struct BinarySearchTree *root, int target) {
  if (root == NULL || root->key == target) {
    return root;
  }
  if (root->key < target) {
    return searchNode(root->right, target);
  } else {
    return searchNode(root->left, target);
  }
}

struct BinarySearchTree *findMin(struct BinarySearchTree *root) {
  if (root == NULL) {
    return NULL;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

struct BinarySearchTree *findMax(struct BinarySearchTree *root) {
  if (root == NULL) {
    return NULL;
  }
  while (root->right != NULL) {
    root = root->right;
  }
  return root;
}

struct BinarySearchTree *findSecondMin(struct BinarySearchTree *root) {
  if (root == NULL || root->left == NULL) {
    return NULL;
  }
  struct BinarySearchTree *parent = NULL;
  while (root->left != NULL) {
    parent = root;
    root = root->left;
  }
  return parent;
}

struct BinarySearchTree *findSecondMax(struct BinarySearchTree *root) {
  if (root == NULL || root->right == NULL) {
    return NULL;
  }
  struct BinarySearchTree *parent = NULL;
  while (root->right != NULL) {
    parent = root;
    root = root->right;
  }
  return parent;
}

struct BinarySearchTree *deleteNode(struct BinarySearchTree *root, int key) {
  if (root == NULL) {
    return NULL;
  }
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      struct BinarySearchTree *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct BinarySearchTree *temp = root->left;
      free(root);
      return temp;
    } else {
      struct BinarySearchTree *temp = findMin(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }
  return root;
}

void updateNode(struct BinarySearchTree **root, int oldKey, int newKey) {
  *root = deleteNode(*root, oldKey);
  *root = insertNode(*root, newKey);
}

int main() {
  struct BinarySearchTree *root = NULL;
  int choice, value, oldKey, newKey;

  while (1) {
    printf("\n--- Binary Search Tree Menu ---\n");
    printf("1. Insert\n");
    printf("2. In-order Traversal (Sorting)\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Search\n");
    printf("6. Find Min\n");
    printf("7. Find Max\n");
    printf("8. Update\n");
    printf("9. Delete\n");
    printf("10. Find Second Min\n");
    printf("11. Find Second Max\n");
    printf("12. Exit\n");
    printf("-------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      root = insertNode(root, value);
      break;
    case 2:
      printf("In-order Traversal: ");
      inOrder(root);
      printf("\n");
      break;
    case 3:
      printf("Pre-order Traversal: ");
      preOrder(root);
      printf("\n");
      break;
    case 4:
      printf("Post-order Traversal: ");
      postOrder(root);
      printf("\n");
      break;
    case 5:
      printf("Enter value to search: ");
      scanf("%d", &value);
      if (searchNode(root, value) != NULL) {
        printf("%d found in the tree.\n", value);
      } else {
        printf("%d not found in the tree.\n", value);
      }
      break;
    case 6: {
      struct BinarySearchTree *minNode = findMin(root);
      if (minNode != NULL) {
        printf("Minimum value: %d\n", minNode->key);
      } else {
        printf("Tree is empty.\n");
      }
      break;
    }
    case 7: {
      struct BinarySearchTree *maxNode = findMax(root);
      if (maxNode != NULL) {
        printf("Maximum value: %d\n", maxNode->key);
      } else {
        printf("Tree is empty.\n");
      }
      break;
    }
    case 8:
      printf("Enter value to update: ");
      scanf("%d", &oldKey);
      printf("Enter new value: ");
      scanf("%d", &newKey);
      updateNode(&root, oldKey, newKey);
      printf("Node updated.\n");
      break;
    case 9:
      printf("Enter value to delete: ");
      scanf("%d", &value);
      root = deleteNode(root, value);
      printf("Node deleted.\n");
      break;
    case 10: {
      struct BinarySearchTree *secondMinNode = findSecondMin(root);
      if (secondMinNode != NULL) {
        printf("Second minimum value: %d\n", secondMinNode->key);
      } else {
        printf("Second minimum not found.\n");
      }
      break;
    }
    case 11: {
      struct BinarySearchTree *secondMaxNode = findSecondMax(root);
      if (secondMaxNode != NULL) {
        printf("Second maximum value: %d\n", secondMaxNode->key);
      } else {
        printf("Second max not found.\n");
      }
      break;
    }
    case 12:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice, please try again.\n");
    }
  }
  return 0;
}
