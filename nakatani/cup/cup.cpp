#include <iostream>
#include <string>
using namespace std;

class Cup {
    int water_amount;
public:
    // 引数を取らないコンストラクタ
    Cup();
    void pour();
};

// 初期化処理
Cup::Cup() {
    water_amount = 10;
}

// 水を出す処理
void Cup::pour() {
    water_amount -= 2;
    cout<< "現在の水の量は" << water_amount << "です。" << endl;
}

int main() {
    // コップを生成
    Cup cup_1;

    cout << "コップcup_1をつくりました。" << endl;
    cout << "cup_1から水を出します。" << endl;
    cup_1.pour();
    cout<<"終了"<<endl;
}