#include <iostream>
#include<vector>
using namespace std;

class BanDoc
{
	private:
		int mbd;
		string hoten,diachi,sdt;
	public:
		void nhap()
		{
			cout << "Nhap ho ten: "; getline(cin,hoten);
			cout << "Nhap dia chi: "; getline(cin,diachi);
			cout << "Nhap sdt: " ; getline(cin,sdt);
			cout << "Nhap ma ban doc: "; cin >> mbd;cin.ignore();
		}
		void xuat()
		{
			cout << "Ho ten: " << hoten << endl;
			cout << "Ma ban doc: " << mbd << endl;
			cout << "Dia chi: " << diachi << endl;
			cout << "Sdt : " << sdt << endl;
			cout << "<---------------------->" << endl;
		}
		string getten(){ return hoten; }
		int getmbd(){ return mbd; }
};
class DanhSachBD
{
	private:
		vector<BanDoc>	dsbd;
	public:
		void thembandoc()
		{
			cout << "Nhap so luong ban doc can them: "; 
			int n ;
			cin >> n; cin.ignore();
			BanDoc x[n];
			cout << "Nhap thong tin ban doc" << endl;
			for(int i = 0 ; i < n ; i++)
			{
				x[i].nhap();
				dsbd.push_back(x[i]);
			}
		}
		void xoaBD()
		{
			cout << "Nhap ma ban doc ma ban muon xoa: "; int mbd; cin >> mbd;
			int ok = 0;
			for(int i = 0 ; i < dsbd.size() ;i++)
			{
				if(dsbd[i].getmbd()==mbd)
				{
					ok = 1;
					dsbd.erase(dsbd.begin()+i);
				}
			}
			if(ok==0)
			{
				cout << "Ban doc nay chua duoc tao the nen khong the xoa!" << endl;
			}
			else
			{
				cout << "Xoa ban doc thanh cong!" << endl;
			}
		}
		void inthongtin()
		{
			if(dsbd.size()==0)
			{
				cout << "Hien tai danh sach trong, chua co ai tao the!" << endl;
			}
			else
			{
				for(int i = 0 ; i < dsbd.size() ; i++)
				{
					dsbd[i].xuat();
				}
			}
		}
};
class Sach
{
	private:
		int ms;
		string tens,tentg,chuyenn,namxb;
	public:
		void nhap()
		{
			cout << "Nhap ten sach: "; getline(cin,tens);
			cout << "Nhap ma sach: "; cin >> ms;cin.ignore();
			cout << "Nhap ten tac gia: "; getline(cin,tentg);
			cout << "Nhap chuyen nganh: " ; getline(cin,chuyenn);
			cout << "Nhap nam xuat ban: "; getline(cin,namxb);
		}
		void xuat()
		{
			cout << "Ten sach: " << tens << endl;
			cout << "Ma sach: " << ms << endl;
			cout << "Ten tac gia: " << tentg << endl;
			cout << "Chuyen nganh: " << chuyenn << endl;
			cout << "Nam xuat ban: " << namxb << endl;
		}
		int getms(){ return ms; }
};

class DanhsachSach
{
	private:
		vector <Sach>	danhsachsach;
	public:
		void themsach()
		{
			cout << "Nhap so luong sach can them: "; int n ; cin >> n;cin.ignore();
			Sach x[n];
			for(int i = 0 ; i < n ; i++)
			{
				x[i].nhap();
				danhsachsach.push_back(x[i]);
			}
		}
		void xoasach()
		{
			int ms;
			cout << "Nhap ma sach ma ban muon xoa khoi danh sach: "; cin >> ms;
			int ok = 0;
			for(int i = 0 ; i < danhsachsach.size(); i++)
			{
				if(danhsachsach[i].getms()==ms)
				{
					ok = 1;
					danhsachsach.erase(danhsachsach.begin()+i);
				}
			}
			if(ok==0)
			{
				cout << "Sach nay khong the xoa vi khong co trong danh sach!" << endl;
			}else
			{
				cout << "Xoa sach thanh cong!." << endl;
			}
		}
		void inthongtin()
		{
			for(int i = 0 ; i < danhsachsach.size() ; i++ )
			{
				danhsachsach[i].xuat();
			}
		}
};

class MuonTraSach
{
	private:
		string ngaymuon;
		string ngaytra;
		vector <Sach> dssach;
		vector <pair<BanDoc,vector<Sach> > > dsmuon;
	public:
		void muonsach()
		{
			BanDoc z;
			z.nhap();
			cout << "Nhap so luong sach ban muon muon: "; int n ; cin >> n;cin.ignore();
			Sach x[n];
			for(int i = 0 ; i < n ; i++)
			{
				x[i].nhap();
				dssach.push_back(x[i]);
			}
			pair <BanDoc,vector<Sach> > o;
			o.first = z;
			o.second = dssach;
			dsmuon.push_back(o);
			cout << "Nhap ngay muon: "; getline(cin,ngaymuon);
			cout << "Nhap ngay tra: "; getline(cin,ngaytra);
			cout << "Muon sach thanh cong,nho tra sach dung hen!" << endl;
		}
		void inthongtinmuon()
		{
			if(dsmuon.size()==0)
			{
				cout << "Khong co ban doc nao muon sach gan day!" << endl;
			}else{
				for(int i = 0 ; i < dsmuon.size() ; i++)
				{
					dsmuon[i].first.xuat();
					cout << "Da muon sach vao ngay: " << ngaymuon << endl;
					cout << "Du dinh se tra sach vao ngay: " << ngaytra << endl;
					cout << "Thong tin sach muon: ";
					for(int j = 0 ; j < dsmuon[i].second.size(); j++)
					{
						dsmuon[i].second[j].xuat();
						cout << "Tinh trang: Chua tra sach!" << endl;
					}
				}
			}
		}
		void timkiemthongtinbandoc()
		{
			int mbd;
			cout << "Nhap ma ban doc ban muon tim kiem: ";cin >> mbd;
			int ok = 0;
			for(int i = 0 ; i < dsmuon.size(); i++)
			{
				if(dsmuon[i].first.getmbd()==mbd)
				{
					ok = 1;
					dsmuon[i].first.xuat();
					cout << dsmuon[i].first.getten() << " da muon sach: " << endl;
					for(int j = 0 ; j < dsmuon[i].second.size() ;j++)
					{
						dsmuon[i].second[j].xuat();
						cout << "Tinh trang: Chua tra sach!" << endl;
					}
				}
			}
			if(ok==0)
			{
				cout << "Khong tim thay thong tin cua nguoi nay!" << endl;
			}
		}
		void trasach()
		{
			int mbd;
			cout << "Nhap ma cua cua ban de tra sach: "; cin >> mbd;
			int ok = 1;
			for(int i = 0 ; i < dsmuon.size(); i++)
			{
				if(dsmuon[i].first.getmbd()==mbd)
				{
					ok = 0;
					dsmuon[i].first.xuat();
					cout << "Tra sach thanh cong!" << endl;
					dsmuon.erase(dsmuon.begin()+i);
					break;
				}
			}
			if(ok==1)
			{
				cout << "Ban chua muon sach o day!";
			}
		}
};

int main()
{
	int s = 1;
	BanDoc x;
	Sach y;
	DanhSachBD x1;
	DanhsachSach y1;
	MuonTraSach z;
	do
	{
		cout << "1.Tao ban doc." << endl;
		cout << "2.Xoa ban doc." << endl;
		cout << "3.Xem thong thong tin tat ca ban doc." << endl;
		cout << "4.Them sach." << endl;
		cout << "5.Xoa sach." << endl;
		cout << "6.Xem thong tin tat ca cac sach." << endl;
		cout << "7.Muon sach." << endl;
		cout << "8.Danh sach ban doc muon sach." << endl;
		cout << "9.Tra sach." << endl;
		cout << "10.Tim kiem thong tin ban doc." << endl;
		cout << "0.Thoat." << endl;
		cout << "Nhap lua chon cua ban: "; cin >> s;cin.ignore();
		cout << endl;
		switch(s)
		{
			case 1:
				cout << "Them thong tin ban doc." << endl;
				x1.thembandoc();
				cout << endl;
				break;
			case 2:
				cout << "Xoa ban doc." << endl;
				x1.xoaBD();
				cout << endl;
				break;
			case 3:
				cout << "Thong tin tat ca ban doc. " << endl;
				x1.inthongtin();
				cout << endl;
				break;
			case 4:
				cout << "Them sach. " << endl;
				y1.themsach();
				cout << endl;
				break;
			case 5:
				cout << "Xoa sach." << endl;
				y1.xoasach();
				cout << endl;
				break;
			case 6:
				cout << "Xem thong tin tat ca sach. " << endl;
				y1.inthongtin();
				cout << endl;
				break;
				
			case 7:
				cout << "Muon sach." << endl;
				z.muonsach();
				cout << endl;
				break;
			case 8:
				cout << "Danh sach ban doc muon sach." << endl;
				z.inthongtinmuon();
				cout << endl;
				break;
			case 9:
				cout << "Tra Sach." << endl;
				z.trasach();
				cout << endl;
				break;
			case 10:
				cout << "Tim kiem thong tin ban doc." << endl;
				z.timkiemthongtinbandoc();
				cout << endl;
				break;
		}
	}while(s!=0);
}
