//sneko.cpp
#include <iostream>
#include <string>
using namespace std;

//元祖「猫」
class Neko
{
    string name;
public:
    Neko(string s);   //「Neko(string);」でも可
    void naku() const;
};

Neko::Neko(string s) : name(s){}

void Neko::naku() const{
    cout<<"にゃあ。俺様は"<<name<<"だ。"<<endl;
}

//「猫」の派生クラス「サラリー猫」
class SalaryNeko : public Neko
{
    int gekkyu;   //月給
public:
    //コンストラクタ。本文で説明します。
    SalaryNeko(string s, int x) : Neko(s), gekkyu(x){}
    //年収を戻す関数。年収は月給の12倍とする。
    int get_nensyu() const { return gekkyu * 12; }
    //月給を1万円増やす関数
    void syoukyu() { gekkyu++; }
};

int main()
{
    cout << "サラリー猫をメモリ上に生成します。名前を決めて入力してください。" << endl;
    string temp;
    cin >> temp; 
    cout << "初任給を決めて入力してください。" << endl;
    cout << "（1万円単位で、半角整数を入力してください。）" << endl;
    int syoninkyu;
    cin >> syoninkyu;
    SalaryNeko dora(temp,syoninkyu);  //サラリー猫の生成
    //ループ。抜けるにはユーザが4か1、2、3以外の数字を入力すればよい。
    while(1){
        cout << "どうしますか？" << endl;
        cout << "1．鳴かす　2．年収を表示　3．昇給　4．やめる" << endl;
        int ans;
        cin >> ans;
        if(ans == 1){     //もし、ansが１なら、、、
            //Nekoの関数NakuをSalaryNekoが使う。 
            dora.naku();
            //Nekoのnaku()はSalaryNekoでも使えるのです。
        }
        else if(ans == 2){ //そうじゃなくて、ansが２なら、、、
            //SalaryNekoの関数get_nensyuをSalaryNekoが使う。 
            cout << "年収は現在" << dora.get_nensyu() << "です。" << endl;
        }
        else if(ans == 3){   //そうじゃなくて、ansが３なら、、、
            // SalaryNekoの関数syoukyuをSalaryNekoが使う。 
            dora.syoukyu();
            cout << "１万円昇給しました。" << endl;
        }
        else{    //上のどれも成り立たない場合
            //ユーザには4と入力すれば「やめる」になると表示しているが、
            //ほかの数字も含めて上の1、2、3以外ならループを抜けるようにした。
           //ループから抜けるにはbreak;
           break;
        }
        //見やすさのための改行
        cout << endl;
    }
    cout << "おしまい" << endl;
}