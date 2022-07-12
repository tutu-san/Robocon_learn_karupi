#include <stdio.h>

#define S 10  //�f�[�^�e�ʐݒ�

//�e�֐��̃v���g�^�C�v�錾
void reset(void);
void push(void);
void pop(void);
void peek(void);
void size(void);
void select(void);

//�K�v�O���[�o���ϐ��̐錾
int stack[S];
int i;
int end;
int code; //�ǂ̊֐����Ō�ɒʂ������m�F����ϐ�

// main: select�֐��N���ƁA�v���O�����I��
int main(void){

    reset();
    while(1){
        select();

        if (end == -1) break;

    }
    return 0;
}

// reset: i�����Z�b�g���邱�ƂŁA�ē��͂ł���悤�ɂ���B
void reset(void){
    
    i = 0;
    code = 0;
    return;

}

// push: �������݂�S������
void push(void){

    if (i < 0) reset(); // i ���}�C�i�X�ȕϐ��ɏ������ނ��Ƃ�h��
    if ( code == 2 || code == 3) i++;   //pop, peek����̒ǉ����͂� i �� 0 �̎��̓�����K��
    while(1){
        if( i >= S){
        printf("ERROR #1\nCapacity is over\n");
        return;
        }
        printf("Input number %d\n", i);

        scanf("%d", &stack[i]);
        
        if(stack[i] == -1) break; //-1���͎��� while ���甲����

        i++;
    }
    code = 1;
    return;
}

// pop: ���o����S������
void pop(void){
    int con = 0; //while �E�o�p�ϐ�
    
    if( stack[i] == -1) i--; //-1�����͂��ꂽ���̕ϐ���\�����Ȃ�
    if(i >= S) i = S - 1; //�L���p�I�[�o�[��Ƀo�O�錻�ۑ΍� (S�Ԗڂ̓o�O��)
    if(i < 0){  // while�ɓ���O�� i ���}�C�i�X�ɂȂ��Ă��Ȃ����m�F����
        printf("ERROR #2\nNothing to show\n");
        return;
    }

    while(1){
        printf("%d number is %d\n", i, stack[i]);
        i--; //���o���Ȃ̂ŁAi ���f�N�������g
        
        if(i < 0){  // �\����� i ���}�C�i�X�̏ꍇ�� while ���甲����
            printf("ERROR #2\nNothing to show\n");
            break;
        }
        
        printf("continue? y=1/n=0\n");  // ���o�������邩�m�F����
        scanf("%d", &con);
        if(con != 1){
            break;
        }

    
    }
    code = 2;
    return;
}

// peek: ��ԍŌ�ɓ��͂��ꂽ���l(1�ԏ�̃f�[�^)���m�F����
void peek(void){
    if(i >= S) i = S - 1;//�L���p�I�[�o�[��Ƀo�O�錻�ۑ΍� (S�Ԗڂ̓o�O��)
    if(i < 0){  // i ���}�C�i�X(�f�[�^���Ȃ����ƂɂȂ��Ă���)�ȂƂ��ɂ͊֐����I��������
        printf("ERROR #3\nNothing to show\n");
        return;
    }
    if( stack[i] == -1) i--; //-1�����͂��ꂽ���̕ϐ���\�����Ȃ�
    
    // ���ʕ\��
    printf("%d number is %d\n", i, stack[i]);
    code = 3;
    return;
}

void size(void){

    code = 4;
    return;
}

// select: �֐��̑I���Ȃǂ�S������
void select(void){
    printf("Select number for menu\n");
    printf(" 0= reset , 1= push , 2= pop, 3= peek, 4= stack, 5= size , -1= exit\n");
    scanf("%d", &end);

    if ( end == 0) reset();
    if ( end == 1) push();
    if ( end == 2) pop();
    if ( end == 3) peek();
    
    return;
}