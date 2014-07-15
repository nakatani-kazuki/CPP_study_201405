//jimbutu_game.cpp
#include <iostream>
#include <cstdlib>  //乱数に必要、入門１０を参照
#include <ctime>   //乱数に必要
using namespace std;

//人物、剣士や占い師などの基底クラス
class Man
{
    static const int DEFAULT_POWER = 5;
    int power;
public:
    //コンストラクタ、powerを初期化
    Man() {
        power = DEFAULT_POWER;
    }
    // constはメンバ内の変数を変更できないように制限をかけている
    int get_power() const {
        return power;
    }
    // 仕事をした後にパワーを減らす関数
    void decr_power() {
        power--;
        cout << "現在のパワー：" << power << endl;
    }
};

//-------------------------------
// 剣士
// コンストラクタは持たない
class Fencer : public Man
{
    static const string name;
    static const string serif1;
    static const string serif2;
public:
    void role();
};

const string Fencer::name   = "剣士";
const string Fencer::serif1 = "俺の剣技を見せてやる！ザシュッ！";
const string Fencer::serif2 = "すまん。疲れているんだ。";

void Fencer::role()
{
    // powerが0以下なら何もしない。
    if(get_power() <= 0){
        cout << serif2 << endl;
        return;
    }
    cout << "俺は" << name << "だ。" << endl;
    cout << serif1 << endl;

    // powerを減算
    decr_power();
}

//占い師
class FortuneTeller : public Man
{
    static const string name;
    static const string serif1;
    static const string serif2;
public:
    void role();
};

const string FortuneTeller::name   = "占い師";
const string FortuneTeller::serif1 = "私は占い師じゃ。今日のおまえの運勢を占ってやろうかの。";
const string FortuneTeller::serif2 = "わしゃ～占い師じゃが、腹減って動けんよ。";

void FortuneTeller::role()
{
    // powerが0以下なら何もしない。
    if(get_power() <= 0){
        cout << serif2 << endl;
        return;
    }

    cout << serif1 << endl;
    int x = rand() % 3;
    if(x == 0){
        cout << "おまえの今日の運勢は最高じゃ。" << endl;
    }
    else if(x == 1){
        cout << "今日のおまえは、まあ、普通じゃな。" << endl;
    }
    else if(x == 2){
        cout << "今日はおまえの厄日じゃ。何もせん方がよい。" << endl;
    }
    decr_power();
}

int main()
{
    srand( (unsigned)time( NULL ) );
    Fencer fencer;    //剣士ヘロの誕生
    FortuneTeller teller; //占い師ペロの誕生

    while(1){
        int x;
        cout << "どうします？" << endl;
        cout << "1 剣士に仕事をしてもらう。 2 占い師に仕事をしてもらう。 3 やめる" << endl;
        cin >> x;
        if(x == 1){
            fencer.role();
        }
        else if(x == 2){
            teller.role();
        }
        else{
            break;
        }
        cout << endl;
    }
    cout<<"おしまい。"<<endl;
}

// コンストラクタなしでも派生クラスを作れる（基底クラスのコンストラクタのみが使用される）