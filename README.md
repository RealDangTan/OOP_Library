# OOP_Library
## Thành viên
Lê Đăng Tấn - 11236199

## Mô tả
Đề bài nhóm B là sử dụng các kiến thức lập trình hướng đối tượng để mô phỏng lại hệ thống thư viện với các chức năng cơ bản:
- Xây dựng các lớp: Sách, Độc giả, Mượn trả.
- Thực hiện các chức năng: Tìm kiếm sách, mượn sách, trả sách, quản lý thông tin độc giả.
- Mở rộng: Tính phí phạt quá hạn, tạo báo cáo thống kê.
Với những yêu cầu như trên nhóm B hoàn thành được các chức năng cơ bản mà đề bài yêu cầu, ngoài ra nhóm cũng có thêm những chức năng mới so với đề bài:
- Database tĩnh thông qua file .txt với chức năng đọc/ghi/cập nhật dữ liệu trong quá trình sử dụng (có constraint về format), nhóm có chuẩn bị sẵn 20 đầu sách và 20 user làm dữ liệu mẫu
- Hệ thống mượn sách trả sách tĩnh - người dùng có thể mượn/trả sách theo thời gian thực của máy (`<ctime>`)
- Tạo một số ràng buộc về dữ liệu để đảm bảo tính trơn tru của hệ thống

## User flow
Để tiện cho quá trình đánh giá báo cáo và sử dụng, nhóm B xin phép được trình bày flow của hệ thống:
- Đăng nhập:
	- Người dùng chạy hệ thống và sẽ phải đăng nhập luôn để sử dụng dịch vụ
		- SĐT đã tồn tại: Nhập đúng SĐT, chạy thuật toán linear search để tìm SĐT
		- SĐT chưa tồn tại: Kết thúc linear search không return được SĐT thì sẽ cho user tạo tài khoản mới với các thông tin cơ bản (ngữ cảnh: quản lý của thư viên nên không cần mật khẩu và authentications)

## Constrain (các ép buộc hệ thống)
Việc có các constrain trong 1 hệ thống sẽ khiến cho việc test trơn tru hơn cũng như để theo dõi được những tồn đọng để từ đó có thể cải thiện trong các phiên bản tiếp theo (nếu cần)
- Date mượn/trả sách không thể ở trước ngày hiện tại (time_now)
- Format database bắt buộc phải theo nguyên tắc (mỗi object cách nhau bởi 1 dòng trống, mở đầu và kết thúc file database là 1 dòng trống)
- Giả dụ các dữ liệu đầu vào và có sẵn là dữ liệu sạch
## Nhận xét
Nhóm sử dụng 100% ngôn ngữ C++ để thiết kế và thực hiện bài tập nhóm, dù việc gộp toàn bộ code vào 1 file sẽ khiến cho việc review khó hơn nhưng do các kế thừa trong 
- Độ tối ưu
Các thuật toán sử dụng trong bài tập nhóm là các thuật toán cơ bản (linear seach, ...)  có độ phức tạp là O(n) và phức tạp nhất là O(n^2), lượng dữ liệu lớn có thể khiến cho hệ thống hoạt động chậm và không hiệu quả nên nhóm chỉ xét ở ngữ cảnh demo, chưa có tính ứng dụng cao
