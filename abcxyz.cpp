#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;

class GV{
	private:
		char ht[30];
		int t;
		char bc[15];
		char chuyenNganh[20];
		float bl;
		
	public:
		GV(){}	
		GV(char *ht, int t, char *bc, char *chuyenNganh, float bl)
		{
			strcpy(this ->ht, ht);
					this ->t = t;
			strcpy(this ->bc, bc);
			strcpy(this ->chuyenNganh, chuyenNganh);
					this ->bl = bl;
		}
		
		void setHt()
		{
			cout<<"\tNhap ho ten: ";
			cin.getline(ht, 30); 
		}
		
	/*
	void showLuong()
		{
			cout<<setw(15)<<luongCB();
		}*/
		
		void setInfor()
		{
			cin.ignore();
			cout<<"\tNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\tNhap chuyen nganh: ";
			cin.getline(chuyenNganh, 20);
			cout<<"\tNhap bang cap: ";
			cin.getline(bc, 15);
			cout<<"\tNhap tuoi: ";
			cin>>t;
			cout<<"\tNhap bac luong: ";
			cin>>bl;
		}
		
		float luongCB()
		{
			return bl*610;
		}
		
		void showInfor()
		{
			cout<<setw(35)<<ht
				<<setw(25)<<chuyenNganh
				<<setw(20)<<bc
				<<setw(15)<<t
				<<setw(15)<<bl
				<<setw(15)<<luongCB()<<endl;
		}
		
		friend istream& operator>>(istream &is, GV &i)
		{
			
			i.setInfor();
			return is;
		}
		
		friend ostream& operator<<(ostream &os, GV &o)
		{
				o.showInfor();
				return os;
		}
		
		char *getHt()
		{
			return ht;
		}
		
		
		void title()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(25)<<"CHUYEN NGANH"
				<<setw(20)<<"BANG CAP"
				<<setw(15)<<"TUOI"
				<<setw(15)<<"BAC LUONG"
				<<setw(15)<<"LUONG CO BAN"<<endl;
		}
};

main()
{
	int n;
	float lcb;
	cout<<"Nhap so luong giao vien: ";
	cin>>n;
	GV *giaovien = new GV[n];
	cout<<"*Nhap thong tin giao vien: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\n\tGiao vien thu "<<i+1<<": "<<endl;
		cin>>giaovien[i];
	}
	cout<<"*Danh sach giao vien co tien luong < 2000: \n";
	for(int i = 0; i < n; i++)
	{
		if(giaovien[i].luongCB() < 2000)
		{
			giaovien[i].title();
			cout<<giaovien[i];
		}
	}
	char h[30];
	int count = 0;
	cout<<"Nhap ho ten 1 giao vien: ";
	cin.getline(h,30);
	for(int i = 0; i < n; i++)
	{
		if(strcmpi(giaovien[i].getHt(),h) == 0 )
		{
			cout<<"Luong: "<<giaovien[i].luongCB()<<endl;
			count++;
		}
	}
		if(count == 0)
		{
			cin.ignore();
			n++;
			cin>>giaovien[n];
		}
		for(int i = 0; i < n; i++)
		{
			cout<<giaovien[i];	
		}
		
}