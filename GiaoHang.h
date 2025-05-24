#ifndef GIAOHANG_H
#define GIAOHANG_H

#include <string>
#include <vector>
#include "DonHang.h"
#include "NhanVien.h"

// Lớp cơ sở trừu tượng cho giao hàng
class GiaoHang {
protected:
    std::string maGH;       // Mã giao hàng
    std::string ngayGiao;   // Ngày giao
    std::string diaDiem;    // Địa điểm giao
    int soLuongDH;          // Số lượng đơn hàng
    double khoangCach;      // Khoảng cách (km)

public:
    // Hàm tạo mặc định
    GiaoHang(std::string ma = "", std::string ngay = "", std::string dd = "", int sl = 0, double kc = 0.0) 
        : maGH(ma), ngayGiao(ngay), diaDiem(dd), soLuongDH(sl), khoangCach(kc) {}

    // Hàm huỷ ảo
    virtual ~GiaoHang() {}

    // Hàm ảo thuần tuý để tính phí giao hàng (đa hình)
    virtual double tinhPhiGiaoHang() const = 0;

    // Hàm ảo để hiển thị thông tin (overriding)
    virtual void hienThi() const {
        std::cout << "Ma GH: " << maGH << ", Ngay giao: " << ngayGiao 
                  << ", Dia diem: " << diaDiem << ", So luong DH: " << soLuongDH 
                  << ", Khoang cach: " << khoangCach << " km" << std::endl;
    }

    // Quá tải toán tử < để so sánh khoảng cách
    bool operator<(const GiaoHang& other) const {
        return khoangCach < other.khoangCach;
    }

    // Getter
    std::string getMaGH() const { return maGH; }

    // Thêm phương thức cập nhật ngày giao
    void capNhatNgayGiao(std::string ngay) { ngayGiao = ngay; }
};

// Lớp dẫn xuất cho giao hàng nhanh (thừa kế)
class GiaoHangNhanh : public GiaoHang {
private:
    std::vector<std::pair<DonHang*, int>> danhSachDonHang; // Danh sách đơn hàng với thứ tự
    NhanVien* nhanVienPhuTrach;                           // Nhân viên phụ trách

public:
    // Hàm tạo
    GiaoHangNhanh(std::string ma, std::string ngay, std::string dd, int sl, double kc) 
        : GiaoHang(ma, ngay, dd, sl, kc), nhanVienPhuTrach(nullptr) {}

    // Hàm huỷ
    ~GiaoHangNhanh() {
        delete nhanVienPhuTrach; // Giải phóng bộ nhớ nếu có
    }

    // Ghi đè hàm tính phí giao hàng
    double tinhPhiGiaoHang() const override {
        return khoangCach * 5000 + 10000 * soLuongDH; // 5k/km + 10k/đơn
    }

    // Ghi đè hàm hiển thị
    void hienThi() const override {
        GiaoHang::hienThi();
        if (nhanVienPhuTrach) {
            std::cout << "Nhan vien phu trach: " << nhanVienPhuTrach->getHoTen() << std::endl;
        }
        for (const auto& pair : danhSachDonHang) {
            std::cout << "Don hang thu " << pair.second + 1 << ": ";
            pair.first->hienThi();
        }
    }

    // Tính năng: Thêm đơn hàng vào danh sách
    void themDonHang(DonHang* dh, int thuTu) {
        if (thuTu >= 0 && thuTu < soLuongDH) {
            danhSachDonHang.emplace_back(dh, thuTu);
        }
    }

    // Tính năng: Phân công nhân viên
    void phanCongNhanVien(NhanVien* nv) {
        nhanVienPhuTrach = nv;
    }
};

#endif