#include<iostream.h>
using namespace std;
class Nguoi{
	private:
		char hoTen[30];
		int tuoiHienTai;
		int cmnd;
		
	public:
		Nguoi(){}
		Nguoi(char *hoTen, int tuoiHienTai, int cmnd)
		{
			strcpy(this ->hoTen, hoTen);
					this ->tuoiHienTai = tuoiHienTai;
					this ->cmnd = cmnd;
		}
		~Nguoi(){}
		
		void setData()
		{
			cin.ignore();
			cout<<"\nNhap ho ten: ";
			cin.getline(hoTen, 30);
			cout<<"\nNhap tuoi hien tai: ";
			cin>>tuoiHienTai;
			cout<<"\nNhap cmnd: ";
			cin>>cmnd;
		}
		
		void getData()
		{
			cout<<"\nHo ten: "<<hoTen<<endl;
			cout<<"\nTuoi hien tai: "<<tuoiHienTai<<endl;
			cout<<"\nCMND: "<<cmnd<<endl;
		}
		
		int getTuoiHien()
		{
			return tuoiHienTai;
		}	
};

class GiangVien : public Nguoi{
	private:
		char maGV[15];
		int tuoiKhiVaoCoQuan;
		char trinhDo[10];
		float hsl;
		
	public:
		GiangVien(){}
		GiangVien(char *hoTen, int tuoiHienTai, int cmnd, char *maGV,
		int tuoiKhiVaoCoQuan, char *trinhDo, float hsl):Nguoi(hoTen,tuoiHienTai,cmnd)
		{
			strcpy(this ->maGV, maGV);
				 	this ->tuoiKhiVaoCoQuan = tuoiKhiVaoCoQuan;
	 		strcpy(this ->trinhDo, trinhDo);
	 				this ->hsl = hsl;
		}
		~GiangVien(){}
		
		friend istream& operator>>(istream &is, GiangVien &i)
		{
			i.setData();
			cin.ignore();
			cout<<"\nNhap ma GV: ";
			is.getline(i.maGV,15);
			cout<<"\nNhap trinh do: ";
			is.getline(i.trinhDo,10);
			cout<<"\nNhap tuoi khi vao co quan: ";
			is>>i.tuoiKhiVaoCoQuan;
			cout<<"\nNhap hsl: ";
			is>>i.hsl;
			return is;
		}
		
		float luong()
		{
			float soNamCongTac = getTuoiHien() - tuoiKhiVaoCoQuan;
			float phuCap = soNamCongTac * 100;
		 	double Luong = hsl * 1490 + phuCap;
			return Luong;
		}
		
	bool GiangVien:: operator > (GiangVien &a){
		return (luong() > a.luong());
	}
		
		friend ostream& operator<<(ostream &os, GiangVien &o)
		{
			o.getData();
			cout<<"\nMa GV: "<<o.maGV<<endl;
			cout<<"\nTrinh do: "<<o.trinhDo<<endl;
			cout<<"\nTuoi khi vao co quan: "<<o.tuoiKhiVaoCoQuan<<endl;
			cout<<"\nHSL: "<<o.hsl<<endl;
			cout<<"\nLuong: "<<o.luong()<<endl;
			return cout;
		}	
};

main()
{
	int n;
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	Nguoi *ng = new Nguoi[n];
	cout<<"\n*****Nhap thong tin cua nguoi*****\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<": "<<endl;
		ng[i].setData();
	}
	cout<<"\n*****Xuat thong tin cua nguoi*****\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<": "<<endl;
		ng[i].getData();
	}
 	int m;
 	cout<<"\nNhap so luong giang vien: ";
 	cin>>m;
 	GiangVien *gv = new GiangVien[m];
 	cout<<"\n*****Nhap thong tin cua giang vien*****\n";
	for(int i = 0; i < m; i++)
	{
		cout<<"\nGiang vien thu "<<i+1<<": "<<endl;
		cin>>gv[i];
	}
	cout<<"\n*****Xuat thong tin cua giang vien*****\n";
	for(int i = 0; i < m; i++)
	{
		cout<<"\nGiang vien thu "<<i+1<<": "<<endl;
		cout<<gv[i];
	}
	cout<<"\n*****Danh sach cac giang vien luong > 10000*****\n";
	for(int i = 0; i < m; i++)
	{
		if(gv[i].luong()>10000)
		{
			cout<<gv[i];
		}
	}
} 