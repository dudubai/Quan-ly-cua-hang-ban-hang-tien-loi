#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <string>
#include "DonHang.h"
using namespace std;

class Nguoi {
protected:
    string hoTen;
    string sdt;

public:
    Nguoi(string ten, string sdt) : hoTen(ten), sdt(sdt) {}
    virtual void hienThi() const = 0;
    virtual ~Nguoi() {}
};

class KhachHang : public Nguoi {
private:
    string maKH;
    DonHang* donHang;

public:
    KhachHang(string ma, string ten, string sdt) : Nguoi(ten, sdt), maKH(ma), donHang(nullptr) {}

    ~KhachHang() {
        if (donHang) delete donHang;
    }

    void datHang(DonHang* dh) {
        donHang = dh;
    }

    void hienThi() const override {
        cout << "KH: " << maKH << " - " << hoTen << " - " << sdt << endl;
        if (donHang) {
            donHang->hienThiDonHang();
        }
    }
};

#endif

