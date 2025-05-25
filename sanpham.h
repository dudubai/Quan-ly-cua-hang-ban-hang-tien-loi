#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>

// Lớp cơ sở trừu tượng cho sản phẩm
class SanPham {
protected:
    std::string maSP;       // Mã sản phẩm
    std::string tenSP;      // Tên sản phẩm
    double gia;             // Giá sản phẩm
    int soLuongTon;         // Số lượng tồn kho
    int hanSuDung;          // Hạn sử dụng (ngày)

public:
    // Hàm tạo mặc định
    SanPham(std::string ma = "", std::string ten = "", double g = 0.0, int sl = 0, int hs = 0) 
        : maSP(ma), tenSP(ten), gia(g), soLuongTon(sl), hanSuDung(hs) {}

    // Hàm huỷ ảo
    virtual ~SanPham() {}

    // Hàm ảo thuần tuý để tính giá ưu đãi (đa hình)
    virtual double tinhGiaUuDai() const = 0;

    // Hàm ảo để hiển thị thông tin (overriding)
    virtual void hienThi() const {
        std::cout << "Ma SP: " << maSP << ", Ten: " << tenSP << ", Gia: " << gia 
                  << " VND, So luong ton: " << soLuongTon << ", Han su dung: " << hanSuDung << " ngay" << std::endl;
    }

    // Quá tải toán tử < để so sánh giá
    bool operator<(const SanPham& other) const {
        return gia < other.gia;
    }

    // Getter
    std::string getMaSP() const { return maSP; }
    std::string getTenSP() const { return tenSP; }
    double getGia() const { return gia; }
    int getSoLuongTon() const { return soLuongTon; }

    // Setter
    void setTenSP(std::string ten) { tenSP = ten; }
    void setGia(double g) { gia = g; }

    // Thêm phương thức cập nhật số lượng
    void capNhatSoLuong(int sl) { soLuongTon = sl; }
};

// Lớp dẫn xuất cho sản phẩm thực phẩm (thừa kế)
class SanPhamThucPham : public SanPham {
private:
    std::string nguonGoc;   // Nguồn gốc sản phẩm

public:
    // Hàm tạo
    SanPhamThucPham(std::string ma, std::string ten, double g, int sl, int hs, std::string ng = "Viet Nam") 
        : SanPham(ma, ten, g, sl, hs), nguonGoc(ng) {}

    // Ghi đè hàm tính giá ưu đãi
    double tinhGiaUuDai() const override {
        return gia * 0.9; // Giảm 10%
    }

    // Ghi đè hàm hiển thị
    void hienThi() const override {
        SanPham::hienThi();
        std::cout << "Nguon goc: " << nguonGoc << std::endl;
    }

    // Getter
    std::string getNguonGoc() const { return nguonGoc; }

    // Setter
    void setNguonGoc(std::string ng) { nguonGoc = ng; }
};

#endif
