#include <assert.h> 

void push(int * stack, int num, int * pos, int capacity){
    assert((*pos+1) < capacity); 
    *pos += 1; 
    stack[*pos] = num;  
}

int pop(int * stack, int * pos){
    assert(pos >= 0); 
    int t = stack[*pos]; 
    *pos -= 1;
    return t; 
}

