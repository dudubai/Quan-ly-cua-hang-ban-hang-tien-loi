#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    string maSanPham; 
    string tenSanPham; 
    float gia;             

public:
    Product();  
    ~Product(); 

    
    void themSanPham();               
    void hienThi() const;             
    bool timKiem(const string& ma) const; 

   
    string getMaSanPham() const { return maSanPham; }
    string getTenSanPham() const { return tenSanPham; }
    float getGia() const { return gia; }
};

#endif
