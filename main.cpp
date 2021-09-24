//程式碼(困難版) https://replit.com/@andy8787coding/Hen-Jian-Dan-De-Dian-Nao-Ke-Dan-Que-Bian-Cheng-OOP-1#main.cpp
#include <iostream>
using namespace std;

void One() {
    //1.請撰寫一程式能讓輸入的兩數值互換。

    int a, b, temp;//a,b是兩數值 temp是暫存
    cout << "請輸入a b: ";
    cin >> a >> b;
    temp = a;
    a = b;
    b = temp;
    cout << "a b的數字互換後是" << a << " " << b << endl;
}

void Two() {
    //2.小新為一名服飾店老闆，其店面租金每日800元，一件衣服成本123元，該件衣服售價200元，請撰寫一程式讓小新輸入每天賣出的衣服件數，輸出它的利潤。
    int n, ans;//n是衣服 ans是利潤
    cout << "請輸入賣出幾件衣服: ";
    cin >> n;
    ans = n*(200-123) - 800;
    cout << "利潤為" << ans << "元\n";
}

void Three() {
    //3.國外長度單位常使用英制單位(英呎與英寸)表示，請撰寫一程式，在一次輸入英呎與英吋後，輸出對應的公分。
    //(1英呎 = 12吋，1英吋 = 2.54公分)

    float em, e, cm;//em英呎 e英吋 //cm公分
    cout << "請輸入英呎 英吋";
    cin >> em >> e;
    cm = 2.54*(e+em*12);//英吋轉公分
    cout << cm << "公分\n";
}


class Taxi{ //第四題
    /*
    新北市計程車主運價（104年10月1日零時起）
    =======================================
    計費表項目      新式計費表          舊式計費表
    起程           1.25公里70元        1.25公里70元
    續程           每200公尺5元        每250公尺5元
    延滯計時       時速5公里以下累計    時速5公里以下累計
                   每1分20秒5元       每1分40秒5元
    夜間加成        每趟次加收20元     每趟次加收20元
    (23:00~06:00)
    淡水區上車      每趟次加收30元      每趟次加收30元
    */
    public:
        int money;
        float km, slowtimeMin, slowtimeSec;//幾公里 延滯時間
        bool old, night, freshwater; //舊或新式 夜間 淡水區
} Car;

void Fourcin() {//輸入
    cout << "請輸入數字 是用舊式計費表為(1) 是用新式計費表為(0): ";
    cin >> Car.old;
    cout << "請輸入座了幾公里: ";
    cin >> Car.km;
    cout << "延遲計時 幾分 幾秒: ";
    cin >> Car.slowtimeMin >> Car.slowtimeSec;
    cout << "是否是夜間加成時段 是為(1) 否為(0): ";
    cin >> Car.night;
    cout << "是否是在淡水區上車 是為(1) 否為(0): ";
    cin >> Car.freshwater;
}

void Old() {//舊式計費表運價
    Car.km -= 1.25;//扣除起程的錢

    if (Car.km > 0) {//續程 每250公尺5元
        Car.money += (Car.km/0.25+1)*5;
    }

    //延滯計時 每1分40秒5元
    Car.slowtimeSec += Car.slowtimeMin*60;
    if (Car.slowtimeSec >= 100) {
        Car.money += (Car.slowtimeSec/100)*5;
    }
}

void New() {//新式計費表運價
    Car.km -= 1.25;//扣除起程的錢

    if (Car.km > 0) {//續程 每200公尺5元
        Car.money += (Car.km/0.2+1)*5;
    }

    //延滯計時 每1分20秒5元
    Car.slowtimeSec += Car.slowtimeMin*60;
    if (Car.slowtimeSec >= 80) {
        Car.money += (Car.slowtimeSec/80)*5;
    }
}

void Four() {
    //4.請撰寫一程式預估新北市計程車車資
    Fourcin();
    Car.money = 70;//起程

    if (Car.night) {//夜間加成
        Car.money += 20;
    }

    if (Car.freshwater) {//淡水區上車加成
        Car.money += 30;
    }

    if (Car.old){//舊式計費表運價
        Old();
    } else {//新式計費表運價
        New();
    }
    cout << "車資為" << Car.money << endl;
}


int main() {//主程式
    cout << "第一題\n";
    One();
    cout << "第二題\n";
    Two();
    cout << "第三題\n";
    Three();
    cout << "第四題\n";
    Four();
}
