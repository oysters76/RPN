#include <string.h> 
#include <stdbool.h>
#include <assert.h>
#include "./stack.h"
#include <stdlib.h> 

char NUMBER_CONSTANTS[] = {'0','1','2','3','4','5','6','7','8','9'}; 
char OP_CONSTANTS[] = {'+', '-', '/', '*'};

bool _is_num(char c){
    for (int i = 0; i < 10; i++){
        if (c == NUMBER_CONSTANTS[i]) return true; 
    }
    return false;
}

bool _is_op(char c){
    for (int i = 0; i < 4; i++){
        if (c == OP_CONSTANTS[i]) return true; 
    }
    return false;
}

int eval(int stackSize, int numSize, char * line){
    int r = 0; 
    int size = strlen(line); 
    
    int stack[stackSize]; 
    int stack_pos = 0;

    char num[numSize+1]; 
    int num_pos = 0; 
    bool copyNum = false; 
    
    for (int i = 0; i < size; i++){
        char c = line[i]; 
        if (_is_num(c)){
            copyNum = true;
        }else if (_is_op(c)){
            int n2 = pop(stack, &stack_pos); 
            int n1 = pop(stack, &stack_pos); 
            int s = 0;
            if (c == '+'){
                s = (n1+n2); 
            }else if (c == '/'){
                assert(n2 != 0); 
                s = (n1/n2); 
            }else if(c == '*'){
                s = (n1*n2); 
            }else{
                s = (n1-n2);
            }
            push(stack, s, &stack_pos, stackSize); 
            r += s; 
        }
        
        if (!_is_num(c)){
             copyNum = false; 
             if (num_pos > 0){
                assert((num_pos+1) < (numSize+1));
                num[num_pos++] = '\0'; 
                
                int n1 = atoi(num);
                push(stack, n1, &stack_pos, stackSize);

                num[0] = '\0'; 
                num_pos = 0;  
             }
        }

        if (copyNum){
            assert((num_pos+1) < (numSize+1)); 
            num[num_pos++] = c; 
        }
    }

    return r; 
}