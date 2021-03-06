#include <stdio.h>

#define S 10

//関数のプロトタイプ宣言
void enqueue(void);
void dequeue(void);
void peek(void);
void size(void);
void select(void);
void reset(void);

//必要グローバル変数の宣言
int queue[S];
int i;
int end;
int code;

//main: select呼び出し、終了担当
int main(void){

    reset(); //最初に中身をリセットさせる

    return 0;
}

//reset: iをリセットすることで、再入力できるようにする。
void reset(void){
     
    i = 0;
    code = 0;
    return;
}

//enqueue: 入力担当
void enqueue(void){
    if(i < 0) reset(); // iがマイナスの時に書き込むことを防ぐ
    
    while (1)
    {
        if( i >= S){
            printf("NOTICE DATA CAPACITY IS OVER\nOLD DATA WAS DELETED\n");
            queue[] = 0;
        }
    }
    

}