//Game.cpp
#include <iostream>
#include <cstdlib>  //乱数のために必要（説明は次回）
#include <ctime>    //乱数のために必要（説明は次回）
using namespace std;

//ここから勇者

class Hero
{
public:
    //Heroはパワーという要素を持っています
    int power;
    //パワー100でヒーローを作ります
    Hero() : power(100){}
    void kougeki_suru(int n); 
    void kougeki_sareru(int n);
};

void Hero::kougeki_suru(int n){
    cout << "  『悪党め！やっつけてやる！！』  " << endl;
    cout << "パワー" << n << "の攻撃！どか〜ん！！" << endl;
    //攻撃に使ったパワーが減る
    power -=n; 

    //パワー0以上残っていればそのまま生存、0以下だと死ぬ
    if(power >= 0){
        cout << "現在のパワーは" << power << "です。" << endl;
    }
    else{
        cout << "  『しまった！パワーを使いすぎた…これまでか…』  " << endl;
        cout << "ヒーローは死んでしまいました。" << endl;
    }
}

//「攻撃される」関数。相手の攻撃の数字の分、HPを削る。
void Hero::kougeki_sareru(int n){
    cout << "  『あいたたたたたた！！』  " << endl;
    cout << "痛恨の一撃！" << n << "のダメージを食らった！！" << endl;
    power -= n;
    if(power >= 0){
        cout << "現在のパワーは" << power << "です。" << endl;
    }
    else{
        cout <<  "  『くっ…こんなところで…』  " << endl;
        cout << "ヒーローは死んでしまいました。" << endl;
    }
}


// ここまで勇者
// ここから大魔王


class Daimao
{
public:
    int power;
    //パワー100で大魔王を作ります
    Daimao() : power(100){}
    void kougeki_suru(int n); 
    void kougeki_sareru(int n);
};

void Daimao::kougeki_suru(int n){
    cout << "  『フハハハ！！これでも喰らえ！！！！』  " << endl;
    cout << "パワー" << n << "の攻撃！どか〜ん！！" << endl;
    //攻撃に使ったパワーが減る
    power -=n; 

    //パワー0以上残っていればそのまま生存、0以下だと死ぬ
    if(power < 0){
        cout << "  『しまった！パワーを使いすぎただと…』  " << endl;
        cout << "大魔王は死んでしまいました。" << endl;
    }
}

void Daimao::kougeki_sareru(int n){
    cout << "  『ぐああああああ！！！』  " << endl;
    power -= n;
    if(power < 0){
        cout << "  『ぐふっ…ばかな…』  " << endl;
        cout << "大魔王をやっつけました。" << endl;
    }
}

// ここまで大魔王
// ここから対決場所

class Taiketu_basyo
{
    //対決を作るには大魔王と勇者が必要なので、ここでオブジェクトを作る
    Daimao bu;
    Hero you;
public:
    //ビルド用。一発目をどう作るかは後で。
    Taiketu_basyo();
    //実際にバトルさせる関数
    void taiketu();
    //勇者と大魔王の隠れ場所を1ターンごとに決める
    void set_hide_area();
    //勇者の攻撃
    void hero_attack();
    //大魔王の攻撃
    void bu_attack();
    //大魔王と勇者の場所を持たせる。1ターン毎に書き換えを行う
    int bu_no_basyo;  //1ターン毎にランダムで決定
    int you_no_basyo;  //1ターン毎にユーザが入力
};


//対決場所をビルドする。
//乱数で大魔王の居場所を生成、勇者の居場所はユーザに入力させて初期値とする
Taiketu_basyo::Taiketu_basyo()
{
    cout << "大魔王ブーをやっつけろ！ \n" << endl;
    cout << "大魔王は1〜5のどこかに潜んでいます。" << endl;  
}


//実際に対決をさせる関数
//大魔王の攻撃はランダムで生成、勇者の攻撃はユーザに入力させてお互い殴らせる
void Taiketu_basyo::taiketu(){
    cin.sync(); //あとで
    cin.get(); //あとで
    srand( (unsigned) time(NULL) );  //乱数の初期化らしい

    //ここから実際のバトル。交互に攻撃を繰り返す。
    while( bu.power > 0 && you.power > 0)
        {
        //ターンの最初に隠れ場所を決める
        set_hide_area();

        //ユーザの攻撃
        hero_attack();

            //この時点でyouが死んでたらループを抜ける
        if(bu.power <= 0 or you.power <= 0){
            break;
        }
        cout << endl;
        cout << endl;
        //大魔王の攻撃
        bu_attack();
    }

    //この時点で主人公が生きてたら勝利コメント、そうでなければ負けコメント
    if(you.power >0)
    {
        cout << "＼＼おめでとう！あなたの勝利だ！！//／" << endl;  
    }
    else{
        cout << "il||li残念！ブウに負けてしまいました…il||li" << endl; 
    }
}


//1ターン毎に隠れ場所を決める。ユーザは自身で入力した数値、大魔王はランダム抽選
void Taiketu_basyo::set_hide_area(){
    cout << "隠れ場所を決めましょう。！1~5のうち、隠れたい数字を入力してください" << endl;
    //勇者の場所はユーザが入力
    cin >> you_no_basyo;
    //大魔王の隠れ場所をランダムで決定
    //rand() %5 で、0~4までの乱数が取れる。＋1して1〜5にしとく
    bu_no_basyo = rand() %5 + 1;
}

//勇者の攻撃
void Taiketu_basyo::hero_attack(){
        int iti, kougeki;
        cout << "あなたの攻撃です。狙う位置を1~5の数値で入力してください。" << endl;
        cin >> iti;
        cout << "攻撃に使うパワー（100以下の数値）を入力してください" << endl;  
        cin >> kougeki;
        cout << endl;
        //Heroのkougeki_suru関数に、今入力された攻撃パワーを渡して攻撃
        //実際にはHeroのパワーがこの分減るだけ
        cout << "=============勇者の攻撃！=============" << endl; 
        you.kougeki_suru(kougeki);
        //大魔王の場所とユーザが狙った場所が合っていたら大魔王のパワーが削れる
        if(bu_no_basyo == iti){
            //ユーザが入力した攻撃力の2倍のダメージを食らう

            bu.kougeki_sareru(kougeki*2);

        cout << "ヒット！大魔王に" << kougeki*2 << "のダメージ！" << endl;  
        }
        else{
            cout << "ミス！大魔王は別の場所にいる！" << endl;  
        }
}

void Taiketu_basyo::bu_attack(){
        int iti, kougeki;

        //狙う位置を1〜5のランダムで生成
        iti = rand() %5+1; 
        //大魔王の使うパワーを1~100のランダムで生成
        kougeki = rand() %50+1;

        //Daimaoのkougeki_suru関数に、今入力された攻撃パワーを渡して攻撃
        //実際にはDaimaoのパワーがこの分減るだけ
        cout << "=============大魔王の攻撃！=============" << endl;    
        bu.kougeki_suru(kougeki);
        if(you_no_basyo == iti){
            //攻撃力の2倍のダメージを食らう
            you.kougeki_sareru(kougeki*2);
        }
        else{
        cout << "ラッキー！大魔王の攻撃がはずれた！ \n" << endl; 
        }
}


//対決をビルドして、バトル
int main()
{
    //Taiketu_basyoのビルド。名前はdokoka。
    Taiketu_basyo dokoka;
    //Taiketu_basyoが持っている「taiketu」コマンドを呼び出す
    dokoka.taiketu();
}





