#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include <vector>
#include <iostream>

class NhanVien {
protected:
    std::string maNV;      
    std::string hoTen;      
    double luongCoBan;     

public:

    NhanVien(std::string ma = "", std::string ten = "", double lc = 0.0) 
        : maNV(ma), hoTen(ten), luongCoBan(lc) {}

    virtual ~NhanVien() {}

    virtual double tinhThuong() const = 0;

    virtual void hienThi() const {
        std::cout << "Ma NV: " << maNV << ", Ten: " << hoTen << ", Luong co ban: " << luongCoBan << " VND" << std::endl;
    }

    bool operator>(const NhanVien& other) const {
        return luongCoBan > other.luongCoBan;
    }

  
    std::string getMaNV() const { return maNV; }
    std::string getHoTen() const { return hoTen; } 
    double getLuongCoBan() const { return luongCoBan; }
    virtual int getSoDonHoanThanh() const = 0;

  
    void setHoTen(std::string ten) { hoTen = ten; } 
    void setLuongCoBan(double lc) { luongCoBan = lc; }
};

class NhanVienBanHang : public NhanVien {
private:
    std::vector<std::string>* danhSachDonHang; 
    int soDonHoanThanh;                       
    double hoaHong;                          

public:
    NhanVienBanHang(std::string ma, std::string ten, double lc, int sdh) 
        : NhanVien(ma, ten, lc), soDonHoanThanh(sdh), hoaHong(0.0) {
        danhSachDonHang = new std::vector<std::string>();
    }

   
    ~NhanVienBanHang() {
        delete danhSachDonHang; 
    }

    double tinhThuong() const override {
        return soDonHoanThanh * 50000; 
    }

    void hienThi() const override {
        NhanVien::hienThi();
        std::cout << "So don hoan thanh: " << soDonHoanThanh << ", Hoa hong: " << hoaHong << " VND" << std::endl;
    }

    int getSoDonHoanThanh() const override {
        return soDonHoanThanh;
    }

    void themDonHang(std::string maDH) {
        danhSachDonHang->push_back(maDH);
        soDonHoanThanh++;
    }

    void capNhatHoaHong(double hh) {
        hoaHong += hh;
    }

    bool hieuSuatCao() const {
        return soDonHoanThanh >= 10;
    }

    void setSoDonHoanThanh(int sdh) { soDonHoanThanh = sdh; }
};

#endif
