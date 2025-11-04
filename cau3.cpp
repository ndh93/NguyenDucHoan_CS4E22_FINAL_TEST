#include <iostream>
#include <string>
using namespace std;

// Hàm mã hóa chuỗi theo kiểu đếm số lần lặp ký tự
string maHoaChuoi(const string &s) {
    string result = "";
    int dem = 1;

    // Duyệt từ ký tự thứ 2 (index = 1) đến hết chuỗi
    for (int i = 1; i <= s.length(); i++) {
        // Nếu ký tự hiện tại giống ký tự trước đó → tăng biến đếm
        if (i < s.length() && s[i] == s[i - 1]) {
            dem++;
        } 
        // Nếu khác hoặc đã đến cuối chuỗi → ghi vào kết quả
        else {
            result += s[i - 1];      // thêm ký tự
            result += to_string(dem); // thêm số lần lặp
            dem = 1; // reset biến đếm cho ký tự mới
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Nhap chuoi: ";
    cin >> s;

    string ketqua = maHoaChuoi(s);
    cout << "Chuoi ma hoa: " << ketqua << endl;

    return 0;
}
