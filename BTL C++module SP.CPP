#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    string maSanPham; // Thu?c tnh 1
    string tenSanPham; // Thu?c tnh 2
    float gia;             // Thu?c tnh 3

public:
    Product();  // H?m t?o
    ~Product(); // H?m h?y

    // Ph??ng th?c
    void themSanPham();                // Ph??ng th?c 1
    void hienThi() const;              // Ph??ng th?c 2
    bool timKiem(const string& ma) const; // Phng th?c 3

    // Getter? truy c?p thu?c tnh
    string getMaSanPham() const { return maSanPham; }
    string getTenSanPham() const { return tenSanPham; }
    float getGia() const { return gia; }
};

#endif
