#include <stdio.h>

#define S 10

//�֐��̃v���g�^�C�v�錾
void enqueue(void);
void dequeue(void);
void peek(void);
void size(void);
void select(void);
void reset(void);

//�K�v�O���[�o���ϐ��̐錾
int queue[S];
int i;
int end;
int code;

//main: select�Ăяo���A�I���S��
int main(void){

    reset(); //�ŏ��ɒ��g�����Z�b�g������

    return 0;
}

//reset: i�����Z�b�g���邱�ƂŁA�ē��͂ł���悤�ɂ���B
void reset(void){
     
    i = 0;
    code = 0;
    rerurn;
}