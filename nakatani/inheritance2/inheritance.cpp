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
    SalaryNeko(string, string, int); 
    // 年収は月給の12倍
    int get_nensyu() const { return gekkyu * 12; }
    // 月給を1万円増やす
    void syoukyu() { gekkyu++; }
};

// コンストラクタの定義
SalaryNeko::SalaryNeko (string n, string c, int x) : Neko(n, c) {
    gekkyu = x;
}


// -----------------------------------------
// 派生クラス「資産家猫」
// -----------------------------------------
class AssetNeko : public Neko
{
    // 資産
    int asset;
public:
    //コンストラクタ
    AssetNeko(string, string, int); 
    int get_asset() const { return asset; }
    // 年収は資産の利子のみで、利率は2%
    int get_nensyu() const { return asset * 2 / 100; }
};

// コンストラクタの定義
AssetNeko::AssetNeko (string n, string c, int a) : Neko(n, c) {
    asset = a;
}

// -----------------------------------------
// main
// -----------------------------------------
int COMMAND_NAKU     = 1;
int COMMAND_NENSHUU  = 2;
int main()
{
    string n;
    string c;
    int s;
    cout << "資産家猫をメモリ上に生成します" << endl;
    cout << "<名前>" << endl;
    cin >> n;
    cout << "<鳴き声>" << endl;
    cin >> c;
    cout << "<資産>（単位：万円）" << endl;
    cout << "（数字は半角で入力してください。）" << endl;
    cin >> s;
    AssetNeko dora(n, c, s);

    // loop
    while(1){
        cout << "どうしますか？" << endl;
        cout << "1:鳴かす 2:年収を表示 3:やめる" << endl;
        int ans;
        cin >> ans;

        // 鳴く
        if(ans == COMMAND_NAKU){
            dora.naku();
        }
        // 年収表示
        else if(ans == COMMAND_NENSHUU){
            cout << "年収は現在" << dora.get_nensyu()<< "万円です。" << endl;
        }
        // 1、2以外ならループを抜ける
        else{
           break;
        }

        cout << endl;
    }

    cout << "おしまい" << endl;
}