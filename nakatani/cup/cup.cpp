#include <iostream>
#include <string>
using namespace std;

class Cup {
    int water_amount;
public:
    // 引数を取らないコンストラクタ
    Cup();
    // 引数を取る同名のコンストラクタ
    Cup(int);
    void pour(int);
};

// 初期化処理
Cup::Cup() {
    water_amount = 10;
}

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
    int x;
    cout << "水量10のコップ（cup）を生成します。" << endl;
    Cup cup; //引数を取らないコンストラクタが呼び出される
    cout << "さあ、glassから水を出します。いくら出しますか。入力してください。" <<endl;
    cin >> x;
    cup.pour(x);

    cout << "水量を指定してコップ（cup_2）を生成します。" << endl;
    cin >> x;
    Cup cup_2(x); //引数を取るコンストラクタが呼び出される
    cout << "さあ、cup_2から水を出します。いくら出しますか。入力してください。" <<endl;
    cin >> x;
    cup_2.pour(x);
    cout<<"終了"<<endl;
}