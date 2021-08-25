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

class NV : public NGUOI{
	private:
		char tdcm[10];
		float sn;
		
	public:
		NV(){}
		NV(char *ht, char *scm, char *gt, char *tdcm, float sn)
		:NGUOI(ht, scm, gt)
		{
			strcpy(this ->tdcm, tdcm);
					this ->sn = sn;
		}
		~NV(){}
		
		void nhapNV(){
			NGUOI::nhapNguoi();
			cout<<"\tNhap trinh do: ";
			cin.getline(tdcm, 10);
			cout<<"\tNhap so nam nop bao hiem: ";
			cin>>sn;
			cin.ignore();
		}
		
		void tieuDe2(){
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MING"
				<<setw(15)<<"GIOI TINH"
				<<setw(15)<<"TRINH DO"
				<<setw(15)<<"SO NAM"
				<<setw(15)<<"TIEN THUONG";
		}
		
		float tienThuongCheDo(){
			return 50*sn;
		}
		
		friend bool operator>=(NV &a, NV &b){
			return (a.sn > b.sn);
		}
		
		void xuatNV(){
			NGUOI::xuatNguoi();
			cout<<setw(15)<<tdcm
				<<setw(15)<<sn
				<<setw(15)<<tienThuongCheDo()<<endl;
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
	
	cout<<"\nNhap so luong nhan vien: ";
	cin>>n;
	NV *nhanvien = new NV[n];
	cin.ignore();
	cout<<"\nNhap cac thong tin cua nhan vien: \n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNhan vien thu "<<i+1<<": \n";
		nhanvien[i].nhapNV();
	}
	cout<<"\nDanh sach nhan vien tang dan theo tien thuong che do: \n";
	nhanvien->tieuDe2();
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(nhanvien[i] >= nhanvien[j])
			{
				NV temp = nhanvien[i];
					nhanvien[i] = nhanvien[j];
					nhanvien[j] = temp;
			}
		}
		cout<<"\nNhan vien thu "<<i+1<<": \n";
		nhanvien[i].xuatNV();
	}
}