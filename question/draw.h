#ifndef _THE1_DRAW
#define _THE1_DRAW

void draw_matrix(int size, int is_alternant, int is_recursive);

void draw_binary_tree(int root, int depth, float ratio);

void draw_matrix_rec(int row, int col, int size, int is_alternant);

void draw_matrix_itr(int size, int is_alternant);

void draw_binary_tree_rec(int root, int level, int depth, float ratio);

int find_depth(int root, float ratio);

#endif