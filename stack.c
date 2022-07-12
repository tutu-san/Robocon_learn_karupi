#include <stdio.h>

#define S 10  //データ容量設定

//各関数のプロトタイプ宣言
void reset(void);
void push(void);
void pop(void);
void peek(void);
void size(void);
void select(void);

//必要グローバル変数の宣言
int stack[S];
int i;
int end;
int code; //どの関数を最後に通ったか確認する変数

// main: select関数起動と、プログラム終了
int main(void){

    reset();
    while(1){
        select();

        if (end == -1) break;

    }
    return 0;
}

// reset: iをリセットすることで、再入力できるようにする。
void reset(void){
    
    i = 0;
    code = 0;
    return;

}

// push: 書き込みを担当する
void push(void){

    if (i < 0) reset(); // i がマイナスな変数に書き込むことを防ぐ
    if ( code == 2 || code == 3) i++;   //pop, peekからの追加入力で i が 0 の時の動作を規定
    while(1){
        if( i >= S){
        printf("ERROR #1\nCapacity is over\n");
        return;
        }
        printf("Input number %d\n", i);

        scanf("%d", &stack[i]);
        
        if(stack[i] == -1) break; //-1入力時に while から抜ける

        i++;
    }
    code = 1;
    return;
}

// pop: 取り出しを担当する
void pop(void){
    int con = 0; //while 脱出用変数
    
    if( stack[i] == -1) i--; //-1が入力された時の変数を表示しない
    if(i >= S) i = S - 1; //キャパオーバー後にバグる現象対策 (S番目はバグる)
    if(i < 0){  // whileに入る前に i がマイナスになっていないか確認する
        printf("ERROR #2\nNothing to show\n");
        return;
    }

    while(1){
        printf("%d number is %d\n", i, stack[i]);
        i--; //取り出しなので、i をデクリメント
        
        if(i < 0){  // 表示後に i がマイナスの場合に while から抜ける
            printf("ERROR #2\nNothing to show\n");
            break;
        }
        
        printf("continue? y=1/n=0\n");  // 取り出し続けるか確認する
        scanf("%d", &con);
        if(con != 1){
            break;
        }

    
    }
    code = 2;
    return;
}

// peek: 一番最後に入力された数値(1番上のデータ)を確認する
void peek(void){
    if(i >= S) i = S - 1;//キャパオーバー後にバグる現象対策 (S番目はバグる)
    if(i < 0){  // i がマイナス(データがないことになっている)なときには関数を終了させる
        printf("ERROR #3\nNothing to show\n");
        return;
    }
    if( stack[i] == -1) i--; //-1が入力された時の変数を表示しない
    
    // 結果表示
    printf("%d number is %d\n", i, stack[i]);
    code = 3;
    return;
}

void size(void){

    code = 4;
    return;
}

// select: 関数の選択などを担当する
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