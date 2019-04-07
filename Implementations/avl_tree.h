#idndef AVL_TREE_H
#define AVL_TREE_H 1

// Type of tree nodes
typedef struct node {
  int bal;
  int key;
  int val;
  struct node *left;
  struct node *right;
} node_t;

node_t *new_node(int bal, int key, int val);
int insert(int *height_changed, node_t *root, int key, int val);
int left_rebalance(int *height_changed, node_t *root);
int right_rebalance(int *height_changed, node_t *root);
void single_left_left_rotation(node_t *root);
void double_left_right_rotation(node_t *root);
void single_right_right_rotation(node_t *root);
void double_right_left_rotation(node_t *root);

#endif
