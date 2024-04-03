#include <stdio.h> 
#include "./rpn.h" 

#define MAX_LINE_SIZE 200
#define STACK_SIZE    200 
#define NUM_SIZE      50

int main(void){
     printf("Enter rpn expression: ");
     char line[MAX_LINE_SIZE+1]; 
     int i = 0; 
     while (i < MAX_LINE_SIZE){
        char c = getchar(); 
        if (c == '\n') break;
        line[i] = c;
        i++; 
     }
    line[(i+1)] = '\0'; 

    int r = eval(STACK_SIZE, NUM_SIZE, line); 
    printf("Result: %d\n", r); 

    return 0; 
}