#include <stdio.h>
#include "draw.h"
#include "utils.h"

void draw_matrix(int size, int is_alternant, int is_recursive)
{
    if (is_recursive)
    {
        draw_matrix_rec(1, 1, size, is_alternant);
    }
    else
    {
        draw_matrix_itr(size, is_alternant);
    }
}

void draw_binary_tree(int root, int depth, float ratio)
{
    draw_binary_tree_rec(root, 0, depth, ratio);
}

void draw_rec_matrix(int col, int row, int size, int num, int is_alternant){
    unsigned long to_print;
    if(col > size){
        num = 0;
        if(col + row > size){
            num = 1;
        }
        row++;
        col = 0;
        printf("\n");
        draw_rec_matrix(col+1, row, size, num, is_alternant);
    }
    else{
        if(is_alternant){
            if(row == size && col == size){
                to_print = apply_function(num, (col-1)%5);
                printf("%ld", to_print );
            }
            else {
                if(col + row > size){
                    to_print = apply_function(num, (col-1)%5);
                    if(col == size){
                        printf("%ld", to_print );
                    }
                    else {
                        printf("%ld ", to_print );
                    }
                    num++;
                    draw_rec_matrix(col+1, row, size, num, is_alternant);
                }else {
                    to_print = apply_function(0, col-1);
                    printf("%ld ", to_print );
                    draw_rec_matrix(col+1, row, size, num, is_alternant);
                }
            }
        }
        else {
            if(row == size && col == size){
                printf("%d", num );
            }
            else {
                if(col + row > size){
                    if(col == size){
                        printf("%d", num);
                    }
                    else{
                        printf("%d ", num);
                        
                    }
                    num++;
                    draw_rec_matrix(col+1, row, size, num, is_alternant);
                }else {
                    printf("%d ", 0);
                    draw_rec_matrix(col+1, row, size, num, is_alternant);
                }
            }
        }
    }
}


void draw_matrix_rec(int row, int col, int size, int is_alternant)
{
    unsigned long to_print;
    /*
    TODO: Implement this function recursively!
   */
   draw_rec_matrix(col, row, size ,1, is_alternant);
}



void draw_matrix_itr(int size, int is_alternant)
{
    unsigned long to_print;
   /*
    TODO: Implement this function iteratively!
   */
   int i,j;
   int num = 1;
   if(!is_alternant){
       for(i=0; i<size; i++){
           num = 1;
           for(j=0; j<size; j++){
                if( (size - j-1)  <= i){
                    if((j + 1) == size){
                        printf("%d", num);
                    }
                    else{
                       printf("%d ", num);
                       num++;
                    }
                   
                }
                else{
                   printf("0 ");
                }
            }
            if(!(size -1 == i)){
                printf("\n");
            }
        }
    }else{
        for(i=0; i<size; i++){
            num = 1;
            for(j=0; j<size; j++){
                if( (size - j-1)  <= i){
                   if((j + 1) == size){
                        to_print = apply_function(num, j);
                        printf("%ld", to_print);
                        num++;
                    }
                    else{
                        to_print = apply_function(num, j);
                        printf("%ld ", to_print);
                        num++;
                    }
                }
                else{
                    to_print = apply_function(0, j);
                    printf("%ld ", to_print);
                }
            }
            
            if(!(size -1 == i)){
                printf("\n");
            }
        }
    }
}

void putSpaces(int depth){
    if(depth>0){
        printf("\t");
        putSpaces(depth - 1);
    }
    
}

void drawMyBody(int root, int level, int depth, float ratio, int solcu){
    float biggerRatio =ratio;
   if(1-ratio > ratio){
       biggerRatio = 1-ratio;
   }
   if(root <= 1 && solcu == 1){
       putSpaces(depth - 1 - level);
       printf("1\n");
   }
   else if(root == 2){
       int rhs = root * biggerRatio;
       putSpaces(depth - 1 - level);
       printf("%d\n", root);
       drawMyBody(rhs, level + 1, depth, ratio, 1);
   }
   else if( root > 2){
       int lhs = root * (1-biggerRatio);
       int rhs = root * biggerRatio;
       if(lhs == 1){
           putSpaces(depth-2-level);
           printf("1\n");
       }
       else {
           drawMyBody(lhs, level + 1, depth, ratio, 0);
       }
       putSpaces(depth - 1 - level);
       printf("%d\n", root);
       drawMyBody(rhs, level + 1, depth, ratio, 1);
   }
}



void draw_binary_tree_rec(int root, int level, int depth, float ratio)
{
    /*
    TODO: Implement this function recursively!
   */
   drawMyBody(root,level,depth,ratio,1);
}

int deepDown(int root, float ratio){
    int rhs = root * ratio;
    if(rhs <=1){
        return 1;
    }
    else{
        return 1 + deepDown(rhs, ratio);
    }
}


int find_depth(int root, float ratio)
{
    /*
    TODO: Implement this function recursively!
   */
   float biggerRatio = ratio;
   int deep;
   if(1-ratio > ratio){
       biggerRatio = 1 - ratio;
   }
   deep = 1 + deepDown(root, biggerRatio);
   printf("Depth of the tree[size: %d, ratio:%.2f] is %d.\n", root, ratio, deep);
    return deep;
}
