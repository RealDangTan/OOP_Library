#include <bits/stdc++.h>
using namespace std;

// Đọc file database dạng txt
fstream book_file("@book_database.txt", ios::app); // ios::app để đổi chế độ qua append mode (thêm kí tự)
fstream user_file("@user_database.txt", ios::app); // ios::in để đọc file txt
// Them sach vao thu vien ngay khi khoi tao

// get system date
time_t current_time = time(0);
tm* time_now = localtime(&current_time);  
// Lớp sách thực hiện chức năng làm khung và các chức năng nhập in tìm sách cơ bản
class SACH {
    protected:
        
        
    public:
        string id_sach;
        string tieu_de;
        string tac_gia;
        bool cho_muon = 1;
        tm ngay_muon = {}, ngay_tra = {};

        SACH(){}
        SACH (string x, string y, string z, string t){
            this->id_sach = x;
            this->tieu_de = y; 
            this->tac_gia = z;
            if(t == "Có thể mượn") this->cho_muon = 1;
            else this->cho_muon = 0;
        }

        void khoiTaoSach(){
            cout << endl << "Thông tin cho sách mới thêm vào: " << endl;
            cout << "Nhập ID của sách: "; cin >> id_sach; cin.ignore();
            cout << "Nhập tiêu đề của sách: "; getline(cin, tieu_de); 
            cout << "Nhập tác giả của sách: "; getline(cin, tac_gia); 
        }

        void inSach(){
            cout << endl << left << setw(12) << "ID: " << id_sach << endl;
            cout << left << setw(13) << "Sách: " << tieu_de << endl;
            cout << left << setw(15) << "Tác giả: " << tac_gia << endl;
            if(cho_muon) cout << left << setw(12) <<"Tình trạng: Có thể mượn" << endl;
            else {
                cout << left << setw(12) << "Tình trạng: Đã mượn" << endl;
                cout << left << setw(12) << "Ngày mượn: " << ngay_muon.tm_mday << "/" << ngay_muon.tm_mon + 1 << "/" << ngay_muon.tm_year + 1900 << endl;
                cout << left << setw(12) << "Ngày trả: " << ngay_tra.tm_mday << "/" << ngay_tra.tm_mon + 1 << "/" << ngay_tra.tm_year + 1900 << endl;
            }
        }

        void addSachtoDB() {
            book_file << endl; 
            book_file << left << setw(12) << "ID: " << id_sach << endl;
            book_file << left << setw(13) << "Sách: " << tieu_de << endl;
            book_file << left << setw(15) << "Tác giả: " << tac_gia << endl;
            if (cho_muon) {
                book_file << left << setw(12) <<"Tình trạng: Có thể mượn" << endl;
            } else {
                book_file << left << setw(12) << "Tình trạng: Đã mượn" << endl;
                book_file << left << setw(12) << "Ngày mượn: " << ngay_muon.tm_mday << "/" << ngay_muon.tm_mon + 1 << "/" << ngay_muon.tm_year + 1900 << endl;
                book_file << left << setw(12) << "Ngày trả: " << ngay_tra.tm_mday << "/" << ngay_tra.tm_mon + 1 << "/" << ngay_tra.tm_year + 1900 << endl;
            }
        }


        // Tìm sách qua id (user truyền từ input)
        string timSach(string find_id){
            if(find_id == id_sach){
                return find_id;
            } else return "none";
        }
};

vector<SACH*> thu_vien; // Change to vector of pointers to SACH

// Flow cho reader: đăng nhập chỉ bằng SĐT, khỏi tạo ngay khi user chạy code
class DOCGIA{
    protected:
        // không dùng nên ném vô private hay protected cũng được -.- 
        string dia_chi;
        string email;

    public: 
        // lười viết hàm truy cập biến nên cho truy cập public luôn
        string ho_ten;
        string sdt;
        vector<SACH*> sach_muon; // Change to vector of pointers to SACH

        DOCGIA(){}
        DOCGIA (string x, string y, string z, string t, vector<string> g){
            ho_ten = x;
            sdt = y; 
            dia_chi = z;
            email = t;
            for (auto a:g){
                for(auto b:thu_vien){
                    if(a == b->timSach(a)){
                        sach_muon.push_back(b);
                    }
                }
            }
        }
        
        // Thêm function nhập, in, ném vào database cho user (dùng form đã có sẵn như lớp SACH)
        // thêm lưu user vao database
        void khoiTaoUser(){
            cout << endl << "Đăng kí tài khoản mới: " << endl;
            cout << "Chúng tôi gọi bạn là: ";cin.ignore(); getline(cin, ho_ten); 
            cout << "Nhập địa chỉ của bạn: "; getline(cin, dia_chi); 
            cout << "Nhập email của bạn: "; getline(cin, email);
        }

        void addUserToDB(){
            user_file << endl << left << setw(15) << "Họ và tên: " << ho_ten << endl;
            user_file << left << setw(12) << "SĐT: " << sdt << endl;
            user_file << left << setw(16) << "Địa chỉ: " << dia_chi << endl;
            user_file << left << setw(11) << "Email: " << email << endl;
            user_file << "Sách đang mượn: " << endl;
            for(auto a: sach_muon){
                user_file << "-   ID: " << a->id_sach << endl;
            }
        }

        void inUser(){
            cout << endl << left << setw(15) << "Họ và tên: " << ho_ten << endl;
            cout << left << setw(12) << "SĐT: " << sdt << endl;
            cout << left << setw(16) << "Địa chỉ: " << dia_chi << endl;
            cout << left << setw(11) << "Email: " << email << endl;
            cout << "Sách đang mượn: \n";
            for(auto a: sach_muon){
                a->inSach();
            }
        }
        
        string timUser(string find_sdt){
            if(find_sdt == sdt){
                return sdt;
            } else return "none";
        }

        void addSach(SACH* sach){
            sach_muon.push_back(sach);
        }

        void removeSach(const string& find_id) {
            for (auto it = sach_muon.begin(); it != sach_muon.end(); ) {
                if (find_id == (*it)->id_sach) {
                    it = sach_muon.erase(it); 
                } else ++it;
            }
        }
};

vector<DOCGIA> users_db;
DOCGIA current_user;

// lẽ ra class nên là 1 danh từ với các chức năng của danh từ nên nhóm chỉ làm class MUONTRA với function muonSach
class MUONTRA: public DOCGIA, public SACH {
    public:
        void muonSach() {
            string find_id;

            cout << "\nSách có thể mượn là: \n";
            for (auto a : thu_vien) {
                if (a->cho_muon) {
                    a->inSach();
                }
            }

            cout << "\nNhập ID sách bạn muốn mượn: "; cin >> find_id;
            for (auto a : thu_vien) {
                if (a->cho_muon && a->id_sach == find_id) {
                    a->cho_muon = 0;
                    current_user.addSach(a);
                    setNgayMuonTra(a); 
                    return;
                }
            }

            cout << "\nID không hợp lệ, vui lòng thử lại.\n" << endl;
            muonSach();
        }

        void setNgayMuonTra(SACH* sach) {
            cout << "Chọn ngày mượn sách (Format: dd mm yy): "; 
            cin >> sach->ngay_muon.tm_mday >> sach->ngay_muon.tm_mon >> sach->ngay_muon.tm_year;
            cout << "Chọn ngày hẹn trả sách (Format: dd mm yy): "; 
            cin >> sach->ngay_tra.tm_mday >> sach->ngay_tra.tm_mon >> sach->ngay_tra.tm_year;

            // xử lý time raw 
            // tháng bắt đầu từ 0, năm bắt đầu từ 1900
            sach->ngay_muon.tm_mon -= 1; 
            sach->ngay_muon.tm_year -= 1900; 
            sach->ngay_tra.tm_mon -= 1; 
            sach->ngay_tra.tm_year -= 1900;

            time_t conv_time_start = mktime(&sach->ngay_muon);
            time_t conv_time_end = mktime(&sach->ngay_tra);

            if (current_time > conv_time_start || conv_time_end - conv_time_start < 0) {
                cout << "Ngày mượn hoặc ngày trả không hợp lệ, vui lòng thử lại.\n";
                setNgayMuonTra(sach);
            }

            cout << "Thời gian mượn sách là: " << difftime(conv_time_start, conv_time_end) / (-60 * 60 * 24) << " ngày\n";
        }
};

void logIn(){
    string find_sdt;
    cout << "Đăng nhập (Tự động đăng kí nếu SĐT chưa tồn tại):" << endl; 
    cout << "Nhập số điện thoại: "; getline(cin, find_sdt);
    for(auto a: users_db){
        if(find_sdt == a.timUser(find_sdt)){
            current_user = a; return;
        }
    }   
    cout << "\nSĐT chưa tồn tại trên hệ thống, vui lòng đăng kí.\n";
    current_user.khoiTaoUser();
    current_user.sdt = find_sdt;
    current_user.addUserToDB(); 
    users_db.push_back(current_user);
}

// Func chọn mode 
void chonMode(int &mode){
    do{
        cout << endl << "--------------------------------------------\n"
             << "Chọn chức năng dưới đây:" << endl << endl
             << "1. Thêm sách" << endl
             << "2. Tìm sách (theo ID sách)" << endl
             << "3. Thống kê sách" << endl
             << "\n4. Mượn sách" << endl
             << "5. Trả sách" << endl
             << "6. Gia hạn" << endl 
             << "\n7. Xem thông tin cá nhân" << endl
             << "8. Chỉnh sửa thông tin cá nhân" << endl
             << "\n0. Kết thúc" << endl << endl;
        cout << "Nhập chức năng (0-8) bạn muốn thực hiện: ";
        // Đoạn này khi in ra 3,4 cách nhau 1 dòng trống, 6,7 cách nhau 1 dòng trống, 8,0 cách nhau một dòng trống. 
        cin >> mode;
    } while (mode > 8 || mode < 0);

    // Chỉnh hành vi của mode ở đây
    switch (mode){
        case 1: {
            SACH* sach_them = new SACH();
            bool no_valid = 1;
            
            // Check if the ID already exists
            /* Hỏi id sách trước khi hỏi tên, vậy nếu tên sách thêm vào trùng thì sao? 
                Vậy mỗi đầu sách nên thêm thông tin về số lượng, hỏi tên sách trước, nếu tên sách trùng thì cộng vào số lượng. 
                Không trùng thì "Nhập vào id cho sách mới:" và không được nhập trùng id với sách đã có */
            while (no_valid) {
                sach_them->khoiTaoSach();
                no_valid = 0;
                for (auto a : thu_vien) {
                    if (a->id_sach == sach_them->id_sach) {
                        cout << "\nID sách đã tồn tại. Vui lòng nhập lại.\n";
                        no_valid = 1;
                        break;
                    }
                }
                if (!no_valid) {
                    thu_vien.push_back(sach_them);
                    sach_them->addSachtoDB();
                }
            }
            break;
        }

        case 2: {
            string find_id;
            cout << "Nhập ID sách: "; cin >> find_id;
            for(auto a: thu_vien){
                if(find_id == a->timSach(find_id)){
                    a->inSach();
                }
            } 
            break;
        }

        case 3: {
            int count_muon = 0;
            int vault = 0;
            cout << "------------------------------------" << endl;
            cout << "Tổng hợp sách của thư viện:" << endl;
            for(auto a: thu_vien){
                a->inSach();
                if(a->cho_muon) count_muon++; 
                if(current_time > mktime(&a->ngay_tra) && !a->cho_muon){
                    int money = 5000;
                    int gap = difftime(current_time, mktime(&a->ngay_tra))/(60 * 60 * 24);
                    vault += money*gap;
                }
            }
            cout << endl << endl << "Tổng số sách trong thư viện: " << thu_vien.size() << endl;
            cout << "Số sách có thể mượn: " << count_muon << endl;
            cout << "Tổng số tiền phạt: " << vault << " VND" << endl;
            cout << "------------------------------------" << endl;
            break;
        }
        
        case 4: {
            MUONTRA func1; 
            func1.muonSach();
            break;
        }

        case 5:{
            string find_id;
            for(auto a: current_user.sach_muon){
                a->inSach();
            }
            cout << "\nNhập ID sách bạn muốn trả: "; cin.ignore(); getline(cin, find_id);
            for(auto& a: thu_vien){
                if(find_id == a->timSach(find_id)){
                    if (current_time > mktime(&a->ngay_tra)){
                        int money = 5000;
                        int gap = difftime(current_time, mktime(&a->ngay_tra))/(- 60 * 60 * 24);
                        cout << "Sách đã quá hạn, tiền phạt quá hạn" << money*gap << "VND\n";
                    }
                    a->cho_muon = 1;
                    cout << "\nĐã trả sách thành công!";
                    current_user.removeSach(find_id);
                }
            }
            break;
        }

        case 6:{
            int more_day;
            string find_id;
            cout << "\nSách bạn đang mượn: \n";
            for(auto a: current_user.sach_muon){
                a->inSach();
            }
            cout << "\nNhập ID sách bạn muốn gia hạn: "; cin.ignore(); getline(cin, find_id);
            cout << "Nhập số ngày muốn gia hạn: "; cin >> more_day;
            for(auto& a: thu_vien){
                if(find_id == a->timSach(find_id)){
                    a->ngay_tra.tm_mday += more_day;
                    mktime(&a->ngay_tra);
                    cout << "\nĐã gia hạn thành công sách: ";
                    a->inSach();
                }
            }
            break;
        }

        case 7:{
            current_user.inUser();                
            break; 
        }

        case 8:{
            current_user.khoiTaoUser();
            break;
        }

        case 0: break;
    }  
}

int main(){
    int mode=1;

    // Đọc database ngay khi khởi tạo chương trình (CODE CHẠY RỒI, CẤM SỬA GÌ ĐOẠN NÀY NỮA)
    // Đọc book database
    fstream book_db_read("@book_database.txt", ios::in);
    string read_line; 
    try {
        while (getline(book_db_read, read_line)) {
            string x, y, z, t;
            tm ngay_muon = {}, ngay_tra = {};
            bool cho_muon = true;       
            // Read the book details
            getline(book_db_read, read_line); x = read_line.substr(12);
            getline(book_db_read, read_line); y = read_line.substr(13);
            getline(book_db_read, read_line); z = read_line.substr(15);
            getline(book_db_read, read_line); t = read_line.substr(15);

            if (t == "Có thể mượn") {
                cho_muon = true;
            } else {
                cho_muon = false;
                getline(book_db_read, read_line); // Ngày mượn
                sscanf(read_line.c_str(), "Ngày mượn: %d/%d/%d", &ngay_muon.tm_mday, &ngay_muon.tm_mon, &ngay_muon.tm_year);
                ngay_muon.tm_mon -= 1; // Adjust month
                ngay_muon.tm_year -= 1900; // Adjust year

                getline(book_db_read, read_line); // Ngày trả
                sscanf(read_line.c_str(), "Ngày trả: %d/%d/%d", &ngay_tra.tm_mday, &ngay_tra.tm_mon, &ngay_tra.tm_year);
                ngay_tra.tm_mon -= 1; // Adjust month
                ngay_tra.tm_year -= 1900; // Adjust year
            }

            SACH* sach = new SACH(x, y, z, t);
            sach->ngay_tra = ngay_tra;
            sach->cho_muon = cho_muon;
            thu_vien.push_back(sach);
            
        }
        throw runtime_error("Có lỗi xảy ra"); // đúng ra là cái này sẽ không chạy dù bất cứ giá nào
    }
    catch(const exception& e) {}
    // Đọc user database
    fstream user_db_read("@user_database.txt", ios::in);
    // try{
        getline(user_db_read, read_line);
        while (getline(user_db_read, read_line)) {
            string x, y, z, t;
            vector<string> g;

            x = read_line.substr(15);
            getline(user_db_read, read_line); y = read_line.substr(12);
            getline(user_db_read, read_line); z = read_line.substr(16);
            getline(user_db_read, read_line); t = read_line.substr(11);

            getline(user_db_read, read_line); 

            if (read_line == "Sách đang mượn: ") {
                getline(user_db_read, read_line);
                while (read_line[0] == '-') {
                    g.push_back(read_line.substr(8));
                    cout<< read_line.substr(8) <<endl;
                    getline(user_db_read, read_line);
                }
            }

            users_db.push_back(DOCGIA(x, y, z, t, g));
        }
    //     throw runtime_error("Có lỗi xảy ra"); // đúng ra là cái này sẽ không chạy dù bất cứ giá nào
    // }
    // catch(const exception& e){}
    // ---------------------------------------------------------------------


    logIn();
    cout << "\nXin chào, " << current_user.ho_ten << endl
         << "SĐT: " << current_user.sdt << endl
         << "Thời gian hiện tại: " << time_now->tm_mday << "/" << time_now->tm_mon + 1 << "/" << time_now->tm_year + 1900 << endl << endl;

    while(mode){
        chonMode(mode);
    }
    
    // update databases
    ofstream file1("@book_database.txt", ios::trunc);
    for(auto a:thu_vien){
        a->addSachtoDB();
    }

    for(auto &a: users_db){
        if(current_user.sdt == a.timUser(current_user.sdt)){
            a = current_user;
        }
    }  
    ofstream file2("@user_database.txt", ios::trunc);
    for(auto a:users_db){
        a.addUserToDB();
    }
    
    return 0;
}
