#include <iostream>
#include <string>
using namespace std;

class Rocket {
private:
    // 燃料
    int fuel_amount;
    //現在の速度
    int speed;
public:
    // コンストラクタの宣言
    // (int fuel_amount)みたいに変数定義してもいい、しなくても大丈夫
    Rocket(int);

    // voidは返り値なしの定義
    void kasoku(); //加速を表す関数の宣言
};

// コンストラクタの定義
// fuel_amountに引数として与えられる値（xで表す）を入れ、speedに0を入れているだけです
// Rocket::Rocket(int x) : fuel_amount(x), speed(0){}
// ↑の書き方は好きに慣れないので直感的に↓みたいに書いとく

// 初期化処理
Rocket::Rocket(int x) {
    cout << "** 燃料 **：" << fuel_amount <<endl;
    fuel_amount = x;
    speed       = 0;
}

// 加速処理
void Rocket::kasoku() {

    // 加速できるだけの燃料がある場合は加速
    if(fuel_amount >= 2){
        speed       += 2;
        fuel_amount -= 2;
        cout<< "現在の燃料は" << fuel_amount << "です。" << endl;
        cout<< "現在の速度は" << speed << "です。" << endl;
    }
    else{
        cout << "燃料切れです。加速できません。漂流します。" <<endl;
    }
    cout << "燃料：" << fuel_amount <<endl;
    cout << "速度：" << speed <<endl;
}

// 実際の処理
int main()
{
    cout << "ロケットをメモリ上につくります。燃料（整数）を入力してください。"<<endl;
    int n;       // ユーザの入力した値を格納する変数をひとつ用意しました。その名はnです。
    cin >> n;    // ユーザの入力した数字をnに代入しました。
    cout << "燃料は" << n << "です。" <<endl;

    // nをコンストラクタに渡してロケットをつくります。
    Rocket apollo_1(n); // これでnの値がコンストラクタの定義のxにコピーされ、
                      // コンストラクタの中身が実行され、fuel_amountの値がnの値に
                      // なったロケットapollo_1（鳳号）が生成されるわけです。
                      // このapollo_1をオブジェクトなどとよぶのでした。
    cout<< "加速します。" <<endl;
    apollo_1.kasoku();  //apollo_1に対してkasokuを使っています
    cout<< "また、加速します。" <<endl;
    apollo_1.kasoku();  //apollo_1に対してkasokuを使っています
    cout<< "またまた、加速してみます。" <<endl;
    apollo_1.kasoku();  //apollo_1に対してkasokuを使っています
    cout<< "鳳号の冒険は終わりました。" <<endl;
}