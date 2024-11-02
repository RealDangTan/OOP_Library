# OOP_Library
## Thành viên

| Họ và tên   | Mã sinh viên |
| ----------- | ------------ |
| Lê Đăng Tấn | 11236199     |

## Mô tả
Đề bài nhóm B là sử dụng các kiến thức lập trình hướng đối tượng để mô phỏng lại hệ thống thư viện với các chức năng cơ bản:
- Xây dựng các lớp: Sách, Độc giả, Mượn trả.
- Thực hiện các chức năng: Tìm kiếm sách, mượn sách, trả sách, quản lý thông tin độc giả.
- Mở rộng: Tính phí phạt quá hạn, tạo báo cáo thống kê.
Với những yêu cầu như trên nhóm B hoàn thành được các chức năng cơ bản mà đề bài yêu cầu, ngoài ra nhóm cũng có thêm những chức năng mới so với đề bài:
- Database tĩnh thông qua file .txt với chức năng đọc/ghi/cập nhật dữ liệu trong quá trình sử dụng (có constraint về format), nhóm có chuẩn bị sẵn 20 đầu sách và 5 users làm dữ liệu mẫu
- Hệ thống mượn sách trả sách có thời gian động - người dùng có thể mượn/trả sách theo thời gian thực của máy (`<ctime>`)
- Tạo một số ràng buộc về dữ liệu để đảm bảo tính trơn tru của hệ thống
## User flow
Bất kì một hệ thống nào cũng cần hướng dẫn sử dụng và cách dùng và để tiện cho quá trình đánh giá báo cáo và sử dụng, nhóm B xin phép được trình bày flow của hệ thống:
- Đăng nhập:
	- Người dùng chạy hệ thống và sẽ phải đăng nhập luôn để sử dụng dịch vụ
		- SĐT đã tồn tại: Nhập đúng SĐT, chạy thuật toán linear search để tìm SĐT
		- SĐT chưa tồn tại: Kết thúc linear search không return được SĐT thì sẽ cho user tạo tài khoản mới với các thông tin cơ bản (ngữ cảnh: quản lý của thư viên nên không cần mật khẩu và authentications)
- Quản lý sách:
	- Thêm sách: người dùng nhập ID, tên sách và tác giả sách, nếu ID hợp lệ (không trùng ID sau khi dùng linear search để check thư viện) thì sẽ in ra thông tin sách thêm vào thành công
	- Tìm sách: người dùng sẽ nhập ID (biết trước) sách định tìm, nếu ID hợp lệ 
	- Thống kê sách: Giao diện sẽ trả lại toàn bộ sách có trong thư viện với các thông số cơ bản (sau khi đọc toàn bộ sách trong database trước đó), đồng thời trả về tổng số sách, số sách có thể mượn và số tiền thu được của thư viện khi sách quá hạn.
- Chức năng cho User:
	- Mượn sách: hệ thống sẽ trả về những quyển sách có trạng thái "có thể mượn" về cho user chọn và user sẽ nhập ID của sách vào, sau đó hệ thống sẽ check nếu hợp lệ thì sẽ cho vào vector sach_muon của user, ngoài ra thuộc tính ngay_muon và ngay_tra sẽ được sử dụng thông qua input của user
	- Trả sách: Hệ thống sẽ hiện thị lại một lượt những quyển sách đã mượn trong cho_muon từ đó cho user nhập ID trong số sách đó để trả lại thu_vien
	- Gia hạn sách: Hệ thống sẽ hiện thị lại một lượt những quyển sách đã mượn trong cho_muon từ đó cho user nhập ID trong số sách đó để gia hạn và overwrite ngay_muon và ngay_tra cho quyển sách (không tính phạt)
- Quản lý user:
	- Xem thông tin chi tiết user hiện tại: sử dụng hàm inUser có trong class của DOCGIA từ đó trả về toàn bộ thông tin user
	- Sửa thông tin user: chạy lại hàm khoiTaoUser() để nhập lại hết thông tin cho user lại từ đầu
# Phân tích hệ thống
Với những comment chi tiết trong file code, nhóm B xin phép được trình bày chi tiết hơn về các cơ sở lý thuyết cũng như cách từng đoạn code hoạt động:
- Hệ thống tiến hành đọc file ngay khi khởi tạo xong chương trình:
```cpp
fstream book_file("@book_database.txt", ios::app); 
fstream user_file("@user_database.txt", ios::app); 
```
- Lớp SACH có những thuộc tính cơ bản như ID sách, tieu_de, tac_gia, biến bool check xem sách có cho mượn không và 1 bộ ngày trả/mượn sách gắn liền với đối tượng sách chính nó luôn
- Lớp dẫn xuất DOCGIA thực hiện các chức năng mà user có thể sử dụng và các thuộc tính user có như ho_ten, SĐT, ...
- Lớp dẫn xuất MUONTRA thực hiện các chức năng mượn trả của người dùng
- Hàm `chonMode()` xử lý các mode của hệ thống
- Hàm `main()` để thực thi chương trình và đọc database từ file txt
- Thuật toán tìm kiếm sử dụng chính: linear search - trả về kết quả nếu chuỗi đầu vào trùng chuỗi tìm được
## Constrain (các ràng buộc hệ thống)
Việc có các constrain trong 1 hệ thống sẽ khiến cho việc test trơn tru hơn cũng như để theo dõi được những tồn đọng để từ đó có thể cải thiện trong các phiên bản tiếp theo (nếu cần)
- Date mượn/trả sách không thể ở trước ngày hiện tại (time_now)
- Format database bắt buộc phải theo nguyên tắc (mỗi object cách nhau bởi 1 dòng trống, mở đầu và kết thúc file database là 1 dòng trống)
- Giả dụ các dữ liệu đầu vào và có sẵn là dữ liệu sạch
- Ở chức năng số 2 (tìm sách), bắt buộc phải biết trước ID để tìm chính xác sách cần tìm
- Các data lưu trữ và hiện thị vẫn còn ở dạng txt, không phải dạng table hay json tiêu chuẩn nên việc truy vấn và phân tích dữ liệu còn gặp khó khăn và không hiệu quả
Với những ràng buộc như trên, nếu đi vào hoạt động thực tế, nhóm sẽ có những điều chỉnh sau:
- Chuyển sang cơ sở dữ liệu hoàn chỉnh khi lượng người dùng/số lượng sách trong database lớn hơn (MongoDB với JSON, Table với MySQL, ...)
- Thiết kế giao diện GUI hoàn chỉnh.
## Nhận xét
Nhóm sử dụng 100% ngôn ngữ C++ để thiết kế và thực hiện bài tập nhóm, dù việc gộp toàn bộ code vào 1 file sẽ khiến cho việc review khó hơn nhưng do các kế thừa trong file hiện đang rất rối nên việc tách ra làm nhiều file sẽ gây nhiều lỗi và khó truy cập vào các phần tử.
- Độ tối ưu
	- Thời gian: Các thuật toán sử dụng trong bài tập nhóm là các thuật toán cơ bản (linear seach, ...)  có độ phức tạp là O(n) và phức tạp nhất là O(n^2), lượng dữ liệu lớn có thể khiến cho hệ thống hoạt động chậm và không hiệu quả nên nhóm chỉ xét ở ngữ cảnh demo, chưa có tính ứng dụng cao
	- Không gian: do việc lưu dữ liệu thông qua vector chưa được tối ưu nếu số lượng data lớn khi các dữ liệu sẽ phải lưu ra 1 file txt và mỗi lần hệ thống được sử dụng thì sẽ đọc hết file txt đó cho vào vector (không tối ưu, 2 lần lưu dữ liệu)
- Các kiến thức nâng cao trong OOP vẫn chưa được vận dụng trong bài tập nhóm như biến, hàm tĩnh, hàm/lớp ảo, template, ...
## Đánh giá thành viên 

| Họ và tên      | Mã sinh viên | Công việc       | Điểm |
| -------------- | ------------ | --------------- | ---- |
| Lê Đăng Tấn    | 11236199     | Làm hết mọi thứ | A+++ |
| Nguyễn Ngọc Hà |              | Làm slide       |      |
 
