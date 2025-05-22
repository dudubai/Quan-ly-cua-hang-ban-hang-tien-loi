#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include <vector>
#include "SanPham.h"

// Lớp cơ sở trừu tượng cho đơn hàng
class DonHang {
protected:
    std::string maDH;       // Mã đơn hàng
    double tongTien;        // Tổng tiền
    std::string trangThai;  // Trạng thái đơn hàng

public:
    // Hàm tạo mặc định
    DonHang(std::string ma = "", double tt = 0.0, std::string ts = "Cho xu ly") 
        : maDH(ma), tongTien(tt), trangThai(ts) {}

    // Hàm huỷ ảo
    virtual ~DonHang() {}

    // Hàm ảo thuần tuý để tính phí vận chuyển (đa hình)
    virtual double tinhPhiVanChuyen() const = 0;

    // Hàm ảo để hiển thị thông tin (overriding)
    virtual void hienThi() const {
        std::cout << "Ma DH: " << maDH << ", Tong tien: " << tongTien 
                  << " VND, Trang thai: " << trangThai << std::endl;
    }

    // Quá tải toán tử < để so sánh tổng tiền
    bool operator<(const DonHang& other) const {
        return tongTien < other.tongTien;
    }

    // Getter
    std::string getMaDH() const { return maDH; }
    double getTongTien() const { return tongTien; }

    // Setter
    void setTongTien(double tt) { tongTien = tt; }

    // Thêm phương thức cập nhật trạng thái
    void capNhatTrangThai(std::string ts) { trangThai = ts; }
};

// Lớp dẫn xuất cho đơn hàng online (thừa kế)
class DonHangOnline : public DonHang {
private:
    std::vector<SanPham*> danhSachSP; // Danh sách sản phẩm (cấp phát động)
    std::string diaChiGiao;           // Địa chỉ giao hàng
    std::string thoiGianDat;          // Thời gian đặt hàng

public:
    // Hàm tạo
    DonHangOnline(std::string ma, std::string dc, std::string thoiGian) 
        : DonHang(ma, 0.0, "Cho xu ly"), diaChiGiao(dc), thoiGianDat(thoiGian) {}

    // Hàm huỷ
    ~DonHangOnline() {
        for (auto sp : danhSachSP) {
            // Không delete sp vì sp được quản lý bởi ProductManager
        }
    }

    // Ghi đè hàm tính phí vận chuyển
    double tinhPhiVanChuyen() const override {
        return tongTien > 500000 ? 0 : 30000; // Miễn phí nếu đơn > 500k
    }

    // Ghi đè hàm hiển thị
    void hienThi() const override {
        DonHang::hienThi();
        std::cout << "Dia chi giao: " << diaChiGiao << ", Thoi gian dat: " << thoiGianDat << std::endl;
        for (const auto sp : danhSachSP) {
            sp->hienThi();
        }
    }

    // Tính năng: Thêm sản phẩm vào đơn hàng
    void themSanPham(SanPham* sp) {
        danhSachSP.push_back(sp);
        tongTien += sp->getGia();
    }

    // Tính năng: Kiểm tra đơn hàng hợp lệ
    bool hopLe() const {
        return !danhSachSP.empty();
    }
};

#endif