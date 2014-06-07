#include <iostream>
#include <cstdlib>  //乱数のために必要
#include <ctime>    //乱数のために必要

#include <stdio.h>
#include <string.h>
#include <memory.h>

using namespace std;

// ---------------
// 勇者クラス
// ---------------
class Hero
{
    int power;
public:
    Hero() : power(100){}
    void attack(int n);       //「攻撃する」関数
    void get_attacked(int n); //「攻撃される」関数
    int  get_left_power();
    int  is_alive();
};

//「ヒーローが攻撃する」関数の定義、nは攻撃に使うパワー
void Hero::attack(int n)
{
    cout << "HERO 「悪党め。正義の攻撃(" << n << ")を受けてみよ！！」 BOOOOMMMMM!!!!!" << endl;
    power -= n;

    // パワーの残りあり
    if(power >= 0){
        // cout << "残りのパワーは" << power << "です。" << endl;
    }
    // パワーの残りなし
    else{
        cout << "HERO 「あ、パワーを使いすぎたから帰るわ」" << endl;
        cout << "\n***************************" << endl;
        cout << " ヒーローは帰路につきました" << endl;
        cout << "***************************" << endl;
    }
}

//「ヒーローが攻撃される」関数の定義、nは攻撃に使うパワー
void Hero::get_attacked(int n)
{
    cout << "HERO「いってええええええ！」" << endl;
    power -= n; //攻撃された分のパワーが減る

    // パワーの残りあり
    if(power >= 0){
        // cout << "残りのパワーは" << power << "です。" << endl;
    }
    // パワーの残りなし
    else{
        cout << "HERO「あーだめだわこれ、くらいすぎだわ」 がくっ" << endl;
        cout << "\n***************************" << endl;
        cout << "    ヒーロー死んじゃった" << endl;
        cout << "***************************" << endl;
    }
}

int Hero::is_alive()
{
    return power > 0 ? 1 : 0;
}

int Hero::get_left_power()
{
    return power;
}

// ---------------
// 魔王クラス
// ---------------
class Devil
{
    int power;
public:
    Devil() : power(100){}
    void attack(int n);       //「攻撃する」関数
    void get_attacked(int n); //「攻撃される」関数
    int  get_left_power();
    int  is_alive();
};

//「魔王が攻撃する」関数の定義、nは攻撃に使うパワー
void Devil::attack(int n)
{
    cout << "魔王「魔王だよーぶちころすよー(" << n << ")」 BOOOOMMMMM!!!!!" << endl;
    power -= n;

    // パワーの残りあり
    if(power >= 0){
        // cout << "残りのパワーは" << power << "です。" << endl;
    }
    // パワーの残りなし
    else{
        cout << "魔王「もうぱわーがない、かえるわ」" << endl;
        cout << "\n***************************" << endl;
        cout << "   魔王かえっちゃったよ" << endl;
        cout << "***************************" << endl;
    }
}

//「魔王が攻撃される」関数の定義、nは攻撃に使うパワー
void Devil::get_attacked(int n)
{
    cout << "魔王「ぐあー！」" << endl;
    power -= n; //攻撃された分のパワーが減る

    // パワーの残りあり
    if(power >= 0){
        // cout << "残りのパワーは" << power << "です。" << endl;
    }
    // パワーの残りなし
    else{
        cout << "魔王「え…？めっちゃ血でとるぅ…」 がくっ" << endl;
        cout << "***************************" << endl;
        cout << "      魔王は倒れました。" << endl;
        cout << "***************************" << endl;
    }
}

int Devil::is_alive()
{
    return power > 0 ? 1 : 0;
}

int Devil::get_left_power()
{
    return power;
}

// ---------------
// バトルクラス
// ---------------
class BattleSpace
{
    Devil devil;           // 対決場所にいる魔王
    Hero  hero;            // 対決場所にいるヒーローyou！
    int devils_coordinate; // 魔王のいる座標
    int heros_coordinate;  // ヒーローのいる座標
public:
    BattleSpace(); // 対決場所のコンストラクタ
    void exec_battle(); // バトル実行関数
};

// 座標の決定
BattleSpace::BattleSpace() {
    //乱数の初期化
    srand( (unsigned)time( NULL ) );

    // 魔王の座標を決定
    //rand() % 5は0～4の乱数
    devils_coordinate = rand() % 5 + 1;

    cout << "「ヒーロー(あなた) vs 魔王(" << devils_coordinate <<")」\n" << endl;
    cout << "魔王は座標1～5のどこかに潜んでいます。" << endl;
    cout << "あなたもどこかに身を潜めてください。" << endl;
    cout << "身を潜める座標（1～5の数値）を入力してください。" << endl;
    cin >> heros_coordinate;
}

// バトルの実行
void BattleSpace::exec_battle()
{

    cout << "\n\n----------- BATTLE START ----------\n" << endl;

    while (hero.is_alive() && devil.is_alive()) {

        // hero -> devil の攻撃
        cout << "=======================================================" << endl;
        cout << "  HERO ATTACK" << endl;
        cout << "=======================================================\n" << endl;
        int attack_coordinate, attack_power;
        cout << "さあ、あなたの攻撃です。" << endl;
        cout << "[攻撃座標] : ";
        cin  >> attack_coordinate;
        cout << "[使用パワー] : ";
        cin  >> attack_power;
        cout << endl;
        hero.attack(attack_power);
        if (!devil.is_alive()) {
            break;
        }
        if(devils_coordinate == attack_coordinate){
            cout << "       HIT!!!!!!!!\n" << endl;

            // 攻撃があたった場合はpowerの2倍くらう
            devil.get_attacked(attack_power * 2);
        }
        else{
            cout << "       MISS...\n" << endl;
        }
        cout << "\n[残りパワー]" << endl;
        cout << "HERO  : " << hero.get_left_power() << endl;
        cout << "DEVIL : " << devil.get_left_power() << endl;
        cout << endl;

        // devil -> hero の攻撃
        cout << "\n=======================================================" << endl;
        cout << "  DEVIL ATTACK" << endl;
        cout << "=======================================================\n" << endl;
        attack_coordinate = rand() % 5 + 1;
        attack_power = rand() % 100 + 1;
        devil.attack(attack_power);
        if(heros_coordinate == attack_coordinate){
            cout << "       HIT!!!!!!!!\n" << endl;
            hero.get_attacked(attack_power * 2);
        }
        else{
            cout << "       MISS...\n" << endl;
        }
        cout << "\n[残りパワー]" << endl;
        cout << "HERO  : " << hero.get_left_power() << endl;
        cout << "DEVIL : " << devil.get_left_power() << endl;
        cout << endl;
        if (!hero.is_alive()) {
            break;
        }
    }
}

// ---------------
// バトルクラス
// ---------------
int main()
{
    BattleSpace somewhere;
    somewhere.exec_battle();
}