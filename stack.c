#include <stdio.h>

#define S 10000

int stack[S];
int size;
int end;

void reset(){
    
    size = 0;
    return;

}

int main(){

    while(1){
        void reset();
        void push();
        void pop();
        void end();
    }

    return 0;
}

void push(){

    if( size >= S){
        printf("ERROR #1\n");
        return;
    }

    while(1){
        printf("Input number %d", S);

        scanf("%d", &stack[S]);
        
        if(stack[S] == -1) break;
    }

    return;
}

void pop(){
    return;
}

void end(){
    return;
}