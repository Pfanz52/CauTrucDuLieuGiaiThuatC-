#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho một nút trong hàng đợi
struct NodeHangDoi {
    int duLieu;
    struct NodeHangDoi* tiepTheo;
};

// Định nghĩa cấu trúc cho hàng đợi
struct HangDoi {
    struct NodeHangDoi* dau;
    struct NodeHangDoi* cuoi;
};

// Khởi tạo hàng đợi
void khoiTaoHangDoi(struct HangDoi* h) {
    h->dau = h->cuoi = NULL;
}

// Kiểm tra xem hàng đợi có trống không
int laRong(struct HangDoi* h) {
    return (h->dau == NULL);
}

// Thêm một phần tử vào cuối hàng đợi
void themVaoCuoi(struct HangDoi* h, int giaTri) {
    struct NodeHangDoi* nutMoi = (struct NodeHangDoi*)malloc(sizeof(struct NodeHangDoi));
    nutMoi->duLieu = giaTri;
    nutMoi->tiepTheo = NULL;

    if (laRong(h)) {
        h->dau = h->cuoi = nutMoi;
    } else {
        h->cuoi->tiepTheo = nutMoi;
        h->cuoi = nutMoi;
    }
}

// Lấy một phần tử từ đầu hàng đợi
int layPhanTu(struct HangDoi* h) {
    if (laRong(h)) {
        printf("Hang doi rong.\n");
        return -1;
    }

    struct NodeHangDoi* nutTam = h->dau;
    int giaTri = nutTam->duLieu;

    if (h->dau == h->cuoi) {
        h->dau = h->cuoi = NULL;
    } else {
        h->dau = h->dau->tiepTheo;
    }

    free(nutTam);
    return giaTri;
}

// Hàm để lấy một số hàng đợi
int laySoHangDoi(struct HangDoi* h) {
    static int soHangDoi = 1;
    themVaoCuoi(h, soHangDoi);
    return soHangDoi++;
}

int main() {
    struct HangDoi h;
    khoiTaoHangDoi(&h);

    int luaChon, soHangDoi;

    do {
        printf("\nMenu:\n");
        printf("1. Lấy số hàng đợi\n");
        printf("2. Phục vụ khách hàng tiếp theo\n");
        printf("3. Thoát\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                soHangDoi = laySoHangDoi(&h);
                printf("Bạn nhận số hàng đợi %d.\n", soHangDoi);
                break;
            case 2:
                if (!laRong(&h)) {
                    int phucVu = layPhanTu(&h);
                    printf("Đang phục vụ khách hàng có số hàng đợi %d.\n", phucVu);
                } else {
                    printf("Không có khách hàng nào trong hàng đợi.\n");
                }
                break;
            case 3:
                printf("Đang thoát...\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while (luaChon != 3);

    return 0;
}
