#include <iostream>
using namespace std;

int main() {
    int T;
    cout << "Nhap so luong test case (1 ≤ T ≤ 100): ";
    cin >> T;

    // kiểm tra số lượng test case
    while (T < 1 || T > 100) {
        cout << "Gia tri T khong hop le. Vui long nhap lai: ";
        cin >> T;
    }

    for (int t = 1; t <= T; ++t) {
        long long n; // n = 10^9 dẫn đến khi tính ước có thể vượt quá giá trị lớn nhất của int vì thế dùng long long.
        cout << "Nhap so nguyen duong n (1 ≤ n ≤ 10^9) cho test " << t << ": ";
        cin >> n;

        // kiểm tra n
        while (n < 1 || n > 1000000000) {
            cout << "Gia tri n khong hop le. Vui long nhap lai: ";
            cin >> n;
        }

        long long sum = 0;
        for (long long i = 1; i <= n; ++i) {
            if (n % i == 0)
                sum += i;
        }

        cout << "Tong cac uoc cua " << n << " la: " << sum << endl;
    }

    return 0;
}
