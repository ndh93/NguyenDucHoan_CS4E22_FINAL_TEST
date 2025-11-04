#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số có phải nguyên tố không
bool laNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra xem số có phải siêu nguyên tố không
bool laSieuNguyenTo(int x) {
    while (x > 0) {
        if (!laNguyenTo(x)) return false;
        x /= 10; // Bỏ chữ số cuối
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    cout << "Cac so sieu nguyen to nho hon hoac bang " << n << " la: ";
    for (int so = 2; so <= n; so++) {
        if (laSieuNguyenTo(so)) {
            cout << so << " ";
        }
    }

    cout << endl;
    return 0;
}
