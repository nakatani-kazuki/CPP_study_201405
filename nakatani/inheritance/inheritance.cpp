#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------
// 規定クラス
// -----------------------------------------
class Neko
{
    string name;
    string cry;
public:
    Neko(string name, string cry);
    void naku() const;
};

Neko::Neko(string n, string c) {
    name = n;
    cry = c;
}

void Neko::naku() const{
    cout << cry << "。俺様は" << name << "だ。" << endl;
}


// -----------------------------------------
// 派生クラス「サラリー猫」
// -----------------------------------------
class SalaryNeko : public Neko
{
    //月給
    int gekkyu;
public:
    //コンストラクタ
    SalaryNeko (string n, string c, int x) : Neko(n, c) {
        gekkyu = x;
    }
    //年収を戻す関数。年収は月給の12倍とする。
    int get_nensyu() const { return gekkyu * 12; }
    //月給を1万円増やす関数
    void syoukyu() { gekkyu++; }
};


// -----------------------------------------
// main
// -----------------------------------------
int COMMAND_NAKU     = 1;
int COMMAND_NENSHUU  = 2;
int COMMAND_SHOUKYUU = 3;
int main()
{
    cout << "ただの猫をメモリ上に生成します。名前を決めて入力してください。" << endl;
    string name1;
    cin >> name1; 
    cout << "鳴き声を入力してください。" << endl;
    string cry1;
    cin >> cry1;
    Neko dora(name1, cry1);
    dora.naku();

    cout << "次はサラリー猫をメモリ上に生成します。" << endl;
    cout << "＜名前入力＞" << endl;
    string name2;
    cin >> name2; 
    cout << "＜鳴き声入力＞" << endl;
    string cry2;
    cin >> cry2;
    cout << "＜初任給入力＞" << endl;
    int syoninkyu;
    cin >> syoninkyu;
    SalaryNeko s_neko(name2, cry2, syoninkyu);

    while(1){
        cout << "どうしますか？" << endl;
        cout << "1:鳴かす  2:年収を表示  3:昇給  4:やめる" << endl;
        int ans;
        cin >> ans;
        if (ans == COMMAND_NAKU) {
            s_neko.naku();
        }
        else if (ans == COMMAND_NENSHUU) {
            cout << "年収は現在" << s_neko.get_nensyu() << "万円です。" << endl;
        }
        else if (ans == COMMAND_SHOUKYUU) {
            s_neko.syoukyu();
            cout << "１万円昇給しました。" << endl;
        }
        else {
            // 入力が1、2、3以外ならループを抜ける
           break;
        }
        cout << endl;
    }

    cout << "おしまい" << endl;
}