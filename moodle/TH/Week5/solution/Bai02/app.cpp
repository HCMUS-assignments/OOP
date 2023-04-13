#include "Registrar.h"
#include <windows.h>


// 1. xử lý đăng ký khóa học (done)
// 3. Thiết lập thời khóa biểu (done)
// 5. viết hàm setTimeTable từ chuỗi đọc từ file (done)
// 2. xử lý in bảng thời khóa biểu (done)
// 4. viết menu/ hàm run (done)


int main() {
    SetConsoleOutputCP(65001);
    
    Registrar registrar;
    registrar.run();

    return 225;
}