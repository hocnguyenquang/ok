#include<iostream.h>
#include<iomanip.h>
using namespace std;

class NGUOI{
	private:
		char ht[30];
		char scm[10];
		char gt[3];
		
	public:
		NGUOI(){}
		NGUOI(char *ht, char *scm, char *gt)
		{
			strcpy(this ->ht, ht);
			strcpy(this ->scm, scm);
			strcpy(this ->gt, gt);
		}
		~NGUOI(){}
		
		void nhapNguoi(){
			cout<<"\tNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\tNhap so chung minh: ";
			cin.getline(scm, 10);
			cout<<"\tNhap gioi tinh: ";
			cin.getline(gt, 3);
		}
		
		void xuatNguoi(){
			cout<<setw(35)<<ht
				<<setw(15)<<scm
				<<setw(15)<<gt;
		}
		
		void tieuDe1(){
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MING"
				<<setw(15)<<"GIOI TINH";
		}
			
};

class SV : public NGUOI{
	private:
		char cn[20];
		float dtl;
		
	public:
		SV(){}
		SV(char *ht, char *scm, char *gt, char *cn, float dtl)
		:NGUOI(ht, scm, gt)
		{
			strcpy(this ->cn, cn);
					this ->dtl = dtl;
		}
		~SV(){}
		
		void nhapSV(){
			NGUOI::nhapNguoi();
			cout<<"\tNhap chuyen nganh: ";
			cin.getline(cn, 20);
			do{
			cout<<"\tNhap diem tich luy: ";
			cin>>dtl;
			if(dtl < 0 || dtl > 4)
			cout<<"Nhap lai ";
			}while(dtl < 0 || dtl > 4);
			cin.ignore();
		}
		
		void xepLoai()
		{
			if(dtl >= 0.0 && dtl <= 1.9)
			{
				cout<<setw(22)<<"Loai trung binh";
			}
			else if(dtl >= 2.0 && dtl <= 3.0)
			{
				cout<<setw(15)<<"Loai kha";
			}
			else
			{
				cout<<setw(15)<<"Loai gioi";
			}
		}
		
		void xuatSV(){
			NGUOI::xuatNguoi();
			cout<<setw(25)<<cn
				<<setw(15)<<dtl;
		}
		
		
		
		friend bool operator>(SV &a, SV &b)
		{
			return (a.dtl > b.dtl);
		}
		
		void tieuDe2()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MING"
				<<setw(15)<<"GIOI TINH"
				<<setw(25)<<"CHUYEN NGANH"
				<<setw(15)<<"DIEM TICH LUY"
				<<setw(15)<<"XEP LOAI"<<endl;
		}
};

main()
{
	int n;
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	NGUOI *ng = new NGUOI[n];
	cin.ignore();
	cout<<"\nNhap cac thong tin cua nguoi: \n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<": \n";
		ng[i].nhapNguoi();
	}
	cout<<"\nXuat cac thong tin cua nguoi: \n";
	ng->tieuDe1();
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<": \n";
		ng[i].xuatNguoi();
	}
	cout<<endl;
	
	cout<<"\nNhap so luong sinh vien: ";
	cin>>n;
	SV *sinhvien = new SV[n];
	cin.ignore();
	cout<<"\nNhap thong tin cua cac sinh vien: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nSinh vien thu "<<i+1<<": \n";
		sinhvien[i].nhapSV();
	}
	cout<<"\nDanh sach tang dan theo diem tich luy cua sinh vien: \n";
	sinhvien->tieuDe2();
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(sinhvien[i] > sinhvien[j])
			{
				SV temp = sinhvien[i];
					sinhvien[i] = sinhvien[j];
					sinhvien[j] = temp;
			}
		}
		cout<<"\nSinh vien thu "<<i+1<<": \n";
		sinhvien[i].xuatSV();
		sinhvien[i].xepLoai();
	}
	cout<<endl;
}