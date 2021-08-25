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

class KHTV : public NGUOI{
	private:
		double st;
		float tg;
		
	public:
		KHTV(){}
		KHTV(double st, float tg)
		{
			this ->st, st;
			this ->tg, tg;
		}
		~KHTV(){}
		
		void nhapKHTV(){
			NGUOI::nhapNguoi();
			do{
			cout<<"\tNhap so tien: ";
			cin>>st;
			if(st <= 0)
			cout<<"\nNhap lai \n";
			}while(st <= 0);
			do{
			cout<<"\tNhap thoi gian vay tinh theo thang: ";
			cin>>tg;
			if(tg <= 0)
			cout<<"\nNhap lai \n";
			}while(tg <= 0);
			cin.ignore();
		}
		
		string phanLoai(){
			if(tg >= 1 && tg <= 12){
				return "Loai ngan han";
			}
			else if(tg >= 13 && tg <= 36){
				return "Loai trung han";
			}
			else{
				return "Loai dai han"; 
			}
				
		}
		
		friend bool operator>(KHTV &a, KHTV &b){
			return (a.tg > b.tg);
		}
		
		void xuatKHTV(){
			NGUOI::xuatNguoi();
			cout<<setw(15)<<st
				<<setw(15)<<tg
				<<setw(15)<<phanLoai()<<endl;
		}
		
		void tieuDe2(){
			NGUOI::tieuDe1();
			cout<<setw(15)<<"SO TIEN"
				<<setw(15)<<"THOI GIAN"
				<<setw(15)<<"PHAN LOAI"<<endl;
		}
		
		
};

main(){
	int n;
	do{
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	if(n <= 0)
	cout<<"\nNhap lai \n";
	}while(n <= 0);
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
	
	do{
	cout<<"\nNhap so luong KHTV: ";
	cin>>n;
	if(n <= 0)
	cout<<"\nNhap lai \n";
	}while(n <= 0);
	KHTV *khachhang = new KHTV[n];
	cin.ignore();
	cout<<"\nNhap thong tin cac KHTV: \n";
	for(int i = 0; i < n; i++){
		cout<<"\nKHTV thu "<<i+1<<": \n";
		khachhang[i].nhapKHTV();
	}
	cout<<"\nDanh sach KHTV loai dai han: \n";
	khachhang->tieuDe2();
	for(int i = 0; i < n; i++){
		if(khachhang[i].phanLoai() == "Loai dai han")
		{
			khachhang[i].xuatKHTV();
		}
	}
	cout<<endl;
}