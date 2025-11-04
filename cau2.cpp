#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ===== HÀM KIỂM TRA NGÀY BAY =====
bool hopLeNgayBay(string ngay) {
    if (ngay.size() != 10) return false;
    if (ngay[2] != '/' || ngay[5] != '/') return false;

    string dd = ngay.substr(0, 2);
    string mm = ngay.substr(3, 2);
    string yyyy = ngay.substr(6, 4);

    for (char c : dd + mm + yyyy) {
        if (!isdigit(c)) return false;
    }

    int day = stoi(dd);
    int month = stoi(mm);
    int year = stoi(yyyy);

    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    int ngayTrongThang;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            ngayTrongThang = 31; break;
        case 4: case 6: case 9: case 11:
            ngayTrongThang = 30; break;
        case 2:
            ngayTrongThang = (year % 4 == 0) ? 29 : 28; break;
        default:
            return false;
    }

    return (day >= 1 && day <= ngayTrongThang);
}

// ===== LỚP VÉ MÁY BAY =====
class Vemaybay {
public:
    string tenchuyen;
    string ngaybay;
    double giave; // giá vé có thẻ có phần thập phân nên dùng kiểu double.

    void Nhap() {
        cout << "  Nhap ten chuyen bay: ";
        getline(cin, tenchuyen);

        do {
            cout << "  Nhap ngay bay (dd/mm/yyyy): ";
            getline(cin, ngaybay);
            if (!hopLeNgayBay(ngaybay))
                cout << "  Ngay bay khong hop le, vui long nhap lai!\n";
        } while (!hopLeNgayBay(ngaybay));

        do {
            cout << "  Nhap gia ve: ";
            cin >> giave;
            if (giave <= 0)
                cout << "  Gia ve phai lon hon 0!\n";
        } while (giave <= 0);
        cin.ignore();
    }

    void Xuat() {
        cout << "    Ten chuyen: " << tenchuyen << endl;
        cout << "    Ngay bay: " << ngaybay << endl;
        cout << "    Gia ve: " << giave << endl;
    }

    double getGiave() {
        return giave;
    }
};

// ===== LỚP NGƯỜI =====
class Nguoi {
public:
    string hoten;
    string gioitinh;
    int tuoi;

    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }

    void Nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);

        do {
            cout << "Nhap gioi tinh (nam/nu): ";
            getline(cin, gioitinh);
            string gt = toLower(gioitinh);
            if (gt != "nam" && gt != "nu")
                cout << "  Gioi tinh chi duoc nhap 'nam' hoac 'nu'!\n";
            else break;
        } while (true);

        do {
            cout << "Nhap tuoi: ";
            cin >> tuoi;
            if (tuoi <= 0 || tuoi > 150)
                cout << "  Tuoi khong hop le, vui long nhap lai!\n";
        } while (tuoi <= 0 || tuoi > 150);
        cin.ignore();
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

// ===== LỚP HÀNH KHÁCH =====
class Hanhkhach : public Nguoi {
public:
    int soluong;
    Vemaybay* ve;

    void Nhap() {
        Nguoi::Nhap();

        do {
            cout << "Nhap so luong ve: ";
            cin >> soluong;
            if (soluong <= 0)
                cout << "  So luong ve phai lon hon 0!\n";
        } while (soluong <= 0);
        cin.ignore();

        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++) {
            cout << "  - Nhap thong tin ve thu " << i + 1 << ":\n";
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;
        for (int i = 0; i < soluong; i++) {
            cout << "  - Thong tin ve thu " << i + 1 << ":\n";
            ve[i].Xuat();
        }
        cout << "Tong tien phai tra: " << tongtien() << endl;
    }

    double tongtien() {
        double tong = 0;
        for (int i = 0; i < soluong; i++)
            tong += ve[i].getGiave();
        return tong;
    }

    ~Hanhkhach() {
        delete[] ve;
    }
};

// ===== CHƯƠNG TRÌNH CHÍNH =====
int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    cin.ignore();

    Hanhkhach* ds = new Hanhkhach[n];

    cout << "\n=== NHAP DANH SACH HANH KHACH ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Hanh khach thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }

    // Sắp xếp giảm dần theo tổng tiền
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tongtien() < ds[j].tongtien()) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\n=== DANH SACH HANH KHACH SAU KHI SAP XEP ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Hanh khach thu " << i + 1 << " ---\n";
        ds[i].Xuat();
    }

    delete[] ds;
    return 0;
}
