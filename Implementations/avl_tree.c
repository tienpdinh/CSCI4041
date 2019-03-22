#include<stdio.h>
#include<stdlib.h>
#include"avl_tree.h"

int main()
{
  return 0;
}

node_t *new_node(int bal, int key, int val)
{
  node_t node = {.bal = bal, .key = key, .val = val, .left = NULL, .right = NULL};
  return &node;
}

int left_rebalance(int *height_changed, node_t *root)
{
  if (root->bal == 1) {
    root->bal = 0;
    *height_changed = 0;
    return 0;
  } else if (root->bal == 0) {
    root->bal = -1;
    return 0;
  } else if (root->bal == -1) {
    if (root->left->bal == -1) {
      single_left_left_rotation(root);
    } else {
      double_left_right_rotation(root);
    }
    root->bal = 0;
    *height_changed = 0;
    return 0;
  } else return 1;
}

int right_rebalance(int *height_changed, node_t *root)
{
  if (root->bal == -1) {
    root->bal = 0;
    *height_changed = 0;
    return 0;
  } else if (root->bal == 0) {
    root->bal = 1;
    return 0;
  } else if (root->bal == 1) {
    if (root->right->bal == 1) {
      single_right_right_rotation(root);
    } else {
      double_right_left_rotation(root);
    }
    root->bal = 0;
    *height_changed = 0;
    return 0;
  } else return 1;
}

void single_left_left_rotation(node_t *root)
{
  node_t *p1 = &(root->left);
  root->left = p1->right;
  p1->right = *root;
  root->bal = 0;
  root = p1;
}

void double_left_right_rotation(node_t *root)
{
  node_t p1 = root->left;
  node_t p2 = p1.right;
  p1.right = p2.left;
  p2.left = p1;
  root->left = p2.right;
  p2.right = *root;
  if (p2.bal == -1) {
    root->bal = 1;
  } else root->bal = 0;
  if (p2.bal == 1) {
    p1.bal = -1;
  } else p1.bal = 0;
  *root = p2;
}
void single_right_right_rotation(node_t *root)
{
  node_t p1 = root->right;
  root->right = p1.left;
  p1.left = *root;
  root->bal = 0;
  *root = p1;
}
void double_right_left_rotation(node_t *root)
{
  node_t p1 = root->right;
  node_t p2 = root->left;
  p1.left = p2.right;
  p2.right = p1;
  root->right = p2.left;
  p2.left = *root;
}
