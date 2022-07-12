#include <stdio.h>

#define S 10000

void reset(void);
void push(void);
void pop(void);
void peak(void);
void size(void);
void select(void);

int stack[S];
int i = 0;
int end;


int main(void){

    reset();
    while(1){
    select();

    if (end == -1) break;

    }
    return 0;
}

void reset(void){
    
    i = 0;
    return;

}

void push(void){

    if( i >= S){
        printf("ERROR #1\n");
        return;
    }

    while(1){
        printf("Input number %d\n", i);

        scanf("%d", &stack[i]);
        
        if(stack[i] == -1) break;

        i++;
    }

    return;
}

void pop(void){
    int con = 0;
    while(1){
    printf("%d number is %d\n", i, stack[i]);
    i--;
    printf("continue? y=1/n=0\n");
    scanf("%d", &con);
    if(con != 1){
        break;
    }
    
    }
    
    return;
}

void select(void){
    printf("Select number for menu\n");
    printf(" 0= reset , 1= push , 2= pop, 3= peak, 4= stack, 5= size , -1= exit\n");
    scanf("%d", &end);

    if ( end == 1) push();
    if ( end == 2) pop();
    
    return;
}