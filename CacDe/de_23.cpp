#include<iostream.h>
using namespace std;
class SanPham{
	private:
		char maSP[15];
		char tenSP[30];
		char loaiSP[15];
		float donGia;
		
	public:
		SanPham(){}
		SanPham(char *maSP, char *tenSP, char *loaiSP, float donGia)
		{
			strcpy(this ->maSP, maSP);
			strcpy(this ->tenSP, tenSP);
			strcpy(this ->loaiSP, loaiSP);
					this ->donGia;
		}
		~SanPham(){}
		
		void setData()
		{
			cin.ignore();
			cout<<"\nNhap ma san pham: ";
			cin.getline(maSP, 15);
			cout<<"\nNhap ten: ";
			cin.getline(tenSP, 30);
			cout<<"\nNhap loai: ";
			cin.getline(loaiSP, 15);
			cout<<"\nNhap don gia: ";
			cin>>donGia;
		}
		
		void getData()
		{
			cout<<"\nMa san pham: "<<maSP<<endl;
			cout<<"\nTen san pham: "<<tenSP<<endl;
			cout<<"\nLoai san pham: "<<loaiSP<<endl;
			cout<<"\nDon gia: "<<donGia<<endl;
		}
		
		float getDonGia()
		{
			return donGia;
		}
			
};

class HoaDon : public SanPham{
	private:
		char maHoaDon[15];
		int ngayLap;
		float soLuong;
		
	public:
		HoaDon(){}
		HoaDon(char *maSP, char *tenSP, char *loaiSP, float donGia, char *maHoaDon,
		int ngayLap, float soLuong):SanPham(maSP,tenSP,loaiSP,donGia){
			strcpy(this ->maHoaDon, maHoaDon);
					this ->ngayLap = ngayLap;
					this ->soLuong = soLuong;
		}
		~HoaDon(){}
		
		friend istream& operator>>(istream &is, HoaDon &i)
		{
			i.setData();
			cin.ignore();
			cout<<"\nNhap ma hoa don: ";
			is.getline(i.maHoaDon,15);
			cout<<"\nNhap ngay lap: ";
			is>>i.ngayLap;
			cout<<"\nNhap so luong: ";
			is>>i.soLuong;
		}
		
		float thanhTien()
		{
			float td;
			td = soLuong * getDonGia();
			return td;
		}
		
		friend bool operator<(HoaDon a, HoaDon b)
		{
			return a.thanhTien() > b.thanhTien();
		}
		
		friend ostream& operator<<(ostream &os, HoaDon &o)
		{
			cout<<"\nMa hoa don: "<<o.maHoaDon<<endl;
			cout<<"\nNgay lap: "<<o.ngayLap<<endl;
			cout<<"\nSo luong: "<<o.soLuong<<endl;
			cout<<"\nThanh tien: "<<o.thanhTien()<<endl;
			return cout;
		}		
};

main()
{
	int n;
	cout<<"\nNhap so luong san pham: ";
	cin>>n;
	SanPham *sp = new SanPham[n];
	cout<<"\n*****Nhap thong tin san pham*****\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nSan pham thu "<<i+1<<": "<<endl;
		sp[i].setData();
	}
	cout<<"\n*****Xuat thong tin san pham*****\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nSan pham thu "<<i+1<<": "<<endl;
		sp[i].getData();
	}
	int m;
	cout<<"\nNhap so luong hoa don: ";
	cin>>m;
	HoaDon *hd = new HoaDon[m];
	cout<<"\n*****Nhap thong tin Hoa don*****\n";
	for(int i = 0; i < m; i++)
	{
		cout<<"\nSan pham thu "<<i+1<<": "<<endl;
		cin>>hd[i];
	}
	cout<<"\n*****Xuat thong tin hoa don*****\n";
	for(int i = 0; i < m; i++)
	{
		cout<<"\nSan pham thu "<<i+1<<": "<<endl;
		cout<<hd[i];
	}
	HoaDon max = hd[0];
	cout<<"\n*****Hoa don co thanh tien lon nhat*****\n";
	for(int i = 0 ; i < m; i++)
	{
		if(hd[i] < max)
		{
			max = hd[i];
		}
	}
	cout<<max;
}