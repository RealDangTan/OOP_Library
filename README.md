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
![[Pasted image 20241026081738.png| center | 500]]
- Đăng nhập:
	- Người dùng chạy hệ thống và sẽ phải đăng nhập luôn để sử dụng dịch vụ![[Pasted image 20241026081705.png]]
		- SĐT đã tồn tại: Nhập đúng SĐT, chạy thuật toán linear search để tìm SĐT
		- SĐT chưa tồn tại: Kết thúc linear search không return được SĐT thì sẽ cho user tạo tài khoản mới với các thông tin cơ bản (ngữ cảnh: quản lý của thư viên nên không cần mật khẩu và authentications)

- Quản lý sách:
	- Thêm sách: người dùng nhập ID, tên sách và tác giả sách, nếu ID hợp lệ (không trùng ID sau khi dùng linear search để check thư viện) thì sẽ in ra thông tin sách thêm vào thành công![[Pasted image 20241026084142.png]]
	- Tìm sách: người dùng sẽ nhập ID (biết trước) sách định tìm, nếu ID hợp lệ  ![[Pasted image 20241026090554.png]]
	- Thống kê sách: Giao diện sẽ trả lại toàn bộ sách có trong thư viện với các thông số cơ bản (sau khi đọc toàn bộ sách trong database trước đó), đồng thời trả về tổng số sách, số sách có thể mượn và số tiền thu được của thư viện khi sách quá hạn.![[Pasted image 20241026090813.png]]'
- Chức năng cho User:
	- 

## Constrain (các ép buộc hệ thống)
Việc có các constrain trong 1 hệ thống sẽ khiến cho việc test trơn tru hơn cũng như để theo dõi được những tồn đọng để từ đó có thể cải thiện trong các phiên bản tiếp theo (nếu cần)
- Date mượn/trả sách không thể ở trước ngày hiện tại (time_now)
- Format database bắt buộc phải theo nguyên tắc (mỗi object cách nhau bởi 1 dòng trống, mở đầu và kết thúc file database là 1 dòng trống)
- Giả dụ các dữ liệu đầu vào và có sẵn là dữ liệu sạch
- Ở chức năng số 2 (tìm sách), bắt buộc phải biết trước ID để tìm chính xác sách cần tìm
## Nhận xét
Nhóm sử dụng 100% ngôn ngữ C++ để thiết kế và thực hiện bài tập nhóm, dù việc gộp toàn bộ code vào 1 file sẽ khiến cho việc review khó hơn nhưng do các kế thừa trong 
- Độ tối ưu
	- Thời gian: Các thuật toán sử dụng trong bài tập nhóm là các thuật toán cơ bản (linear seach, ...)  có độ phức tạp là O(n) và phức tạp nhất là O(n^2), lượng dữ liệu lớn có thể khiến cho hệ thống hoạt động chậm và không hiệu quả nên nhóm chỉ xét ở ngữ cảnh demo, chưa có tính ứng dụng cao
	- Không gian: do việc lưu dữ liệu thông qua vector 
## Đánh giá thành viên 

| Họ và tên      | Mã sinh viên | Công việc       | Điểm |
| -------------- | ------------ | --------------- | ---- |
| Lê Đăng Tấn    | 11236199     | Làm hết mọi thứ | A+++ |
| Nguyễn Ngọc Hà |              | Làm slide       |      |
 