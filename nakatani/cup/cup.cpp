#include <iostream>
#include <string>
using namespace std;

class Cup {
    int water_amount;
public:
    // 引数を取らないコンストラクタ
    Cup(int);
    void pour(int);
};

// 初期化処理
Cup::Cup(int x) {
    water_amount = x;
}

// 水を出す処理
void Cup::pour(int x) {
    if (water_amount >= x) {
        water_amount -= x;
        cout<< "現在の水の量は" << water_amount << "です。" << endl;
    } else {
        cout<< "そんなに水ないよ" << endl;
        cout<< "あと" << water_amount << "しかない" << endl;
    }
}

int main() {
    // コップを生成
    int x;
    cout << "コップを生成します。どれだけ水をいれるか入力してください。" << endl;
    cin >> x;
    Cup cup_1(x);

    cout << "コップcup_1をつくりました。" << endl;
    cout << "さあ、glassから水を出します。いくら出しますか。入力してください。" <<endl;
    cin >> x; // 上のxを使いまわしている

    cup_1.pour(x);
    cout<<"終了"<<endl;
}