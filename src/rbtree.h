#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <stddef.h>

/* 1️⃣ RB tree 구조체 생성 */
typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

typedef int key_t;

typedef struct node_t {
  color_t color;
  key_t key;
  struct node_t *parent, *left, *right;
} node_t;

typedef struct rbtree {
  node_t *root;
  node_t *nil;
} rbtree;

rbtree *new_rbtree(void);
void delete_rbtree(rbtree *);
void traverse_and_delete_node(rbtree *, node_t *);

node_t *rbtree_insert(rbtree *, const key_t);
void rbtree_insert_fixup(rbtree *, node_t *);
void right_rotate(rbtree *, node_t *);
void left_rotate(rbtree *, node_t *);
void exchange_color(node_t *, node_t *);

node_t *rbtree_find(const rbtree *, const key_t);
node_t *rbtree_min(const rbtree *);
node_t *rbtree_max(const rbtree *);
int rbtree_erase(rbtree *, node_t *);

int rbtree_to_array(const rbtree *, key_t *, const size_t);

node_t *get_next_node(const rbtree *, node_t *);
void rbtree_erase_fixup(rbtree *, node_t *, int);

#endif  // _RBTREE_H_