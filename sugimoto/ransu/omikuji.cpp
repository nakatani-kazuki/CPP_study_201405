//omikuji.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Omikuji{
    int un; //ラッキーナンバー
public:
    Omikuji(); //コンストラクタ（オブジェクト生成のコマンド）
    void hiku();
};

//ラッキーナンバーをユーザに入力してもらう
Omikuji::Omikuji(){
    srand( (unsigned)time( NULL ) );//実行のたびに乱数が変わる
    cout << "自分のラッキーナンバー(1〜5）を入力してください。" << endl;
    cin >> un;
}

//おみくじを引く
void Omikuji::hiku(){
    int x;
    x = rand()%5+1; //1〜5の乱数を発生させ、xに代入する
    cout << "あなたの運勢は" ;
    if (x == un){ //xとunが等しければ大吉
        cout << "大吉ということです。" <<endl;
        cout << "引いた数：" << x << "ラッキーナンバー：" << un <<endl;
    }else{
        cout << "人並みということです。" <<endl;
        cout << "引いた数：" << x << "ラッキーナンバー：" << un <<endl;
    }
}

int main(){
    Omikuji today;//todayという名前のomikujiを作る
    today.hiku();
}



