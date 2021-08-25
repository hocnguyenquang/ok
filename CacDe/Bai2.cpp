#include<iostream.h>
#include<iomanip.h>
using namespace std;
class GV {
	private:
		char ht[30];
		char chuyenNganh[20];
		float bl;
		
	public:
		GV(){}
		GV(char *ht, char *chuyenNganh, float bl)
		{
			strcpy(this ->ht, ht);
			strcpy(this ->chuyenNganh, chuyenNganh);
					this ->bl = bl;	
		}
		~GV(){}	
		void setDataGV()
		{
			cin.ignore();
			cout<<"\nNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\nNhap chuyen nganh: ";
			cin.getline(chuyenNganh, 20);
			cout<<"\nNhap bac luong: ";
			cin>>bl;
		}
		
		void getDataGV()
		{
			cout<<setw(35)<<ht
				<<setw(25)<<chuyenNganh
				<<setw(15)<<bl;
		}
		float getBl()
		{
			return bl;
		}
		void tieuDe1()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(25)<<"CHUYEN NGANH"
				<<setw(15)<<"BAC LUONG"<<endl;
		}
};

class GVTH : public GV
{
	private:
		char l[3];
		float lpc;
		
	public:
		GVTH(){}
		GVTH(char *ht, char *chuyenNganh, float bl, char *l, float lpc)
		:GV(ht, chuyenNganh, bl)
		{
			strcpy(this ->l, l);
					this ->lpc = lpc;
		}
		~GVTH(){}
		
		void setDataGVTH()
		{
			GV::setDataGV();
			cin.ignore();
			cout<<"\nNhap lop: ";
			cin.getline(l, 3);
			cout<<"\nNhap luong phu cap: ";
			cin>>lpc;
		}
		
		
		float tienLuong()
		{
			return 1150*getBl()+lpc;
		}
		
		friend bool operator>=(GVTH &a, GVTH &b)
		{
			return a.tienLuong() > b.tienLuong();
		}
		
		void getDataGVTH()
		{
			GV::getDataGV();
			
			cout<<setw(5)<<l
				<<setw(15)<<lpc<<endl;
		}
		
		void tieuDe2()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(25)<<"CHUYEN NGANH"
				<<setw(15)<<"BAC LUONG"
				<<setw(5)<<"LOP"
				<<setw(15)<<"LUONG PHU CAP"<<endl;
		}	
};

main()
{
	int n;
	cout<<"\nNhap so luong GV: ";
	cin>>n;
	GV *giaovien = new GV[n];
	cout<<"\nNhap thong tin GV: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nGiao vien thu "<<i+1<<": ";
		
		giaovien[i].setDataGV();
	}
	
	cout<<"\nXuat thong tin GV: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nGiao vien thu "<<i+1<<": \n";
		giaovien[i].tieuDe1();
		giaovien[i].getDataGV();
	}
	
	cout<<endl;
	
	cout<<"\nNhap so luong GVTH: ";
	cin>>n;
	GVTH *giaovienTH = new GVTH[n];
	cout<<"\nNhap thong tin GVTH: ";	
	for(int i = 0; i < n; i++)
	{
		cout<<"\nGiao vien thu tieu hoc "<<i+1<<": \n";
		giaovienTH[i].setDataGVTH();
	}
	cout<<"\nXuat thong tin GVTH: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nGiao vien thu tieu hoc "<<i+1<<": \n";
		giaovienTH[i].tieuDe2();
		giaovienTH[i].getDataGVTH();
	}
	
	cout<<"\nSap xep tang dan theo luong: \n";
	for(int i = 0; i < n; i++)
	{
		if(giaovienTH[i].tienLuong() >= giaovienTH[i+1].tienLuong())
		{
			GVTH temp = giaovienTH[i];
				giaovienTH[i] = giaovienTH[i+1];
				giaovienTH[i+1] = temp;
		}
		giaovienTH[i].tieuDe2();
		giaovienTH[i].getDataGVTH();
	}
	cout<<endl;
}