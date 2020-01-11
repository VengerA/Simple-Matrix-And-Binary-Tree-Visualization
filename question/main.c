#include <stdio.h>
#include "draw.h"
#include "utils.h"
#define TRUE 1
#define FALSE 0

int main() {
    char opt;
    int size;
    int is_recursive;
    int is_alternant;
    int root;
	int depth;
    float ratio;
    /*
    TODO: Read inputs correctly and call related function!
    */
    scanf(" %c", &opt);
    if(opt == 'f'){
        scanf("%d %f", &root, &ratio);
        find_depth(root, ratio);
    }
    else if(opt == 'd'){
        scanf("%d %d %f", &root, &depth, &ratio);
        draw_binary_tree_rec(root, 0, depth , ratio);
    }
    else if(opt == 'm'){
        scanf("%d %d %d ", &size,  &is_alternant, &is_recursive);
        draw_matrix(size, is_alternant, is_recursive);
    }
    
	return 0;
}
