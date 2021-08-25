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

class KHTG : public NGUOI{
	private:
		double st;
		float tg;
		
	public:
		KHTG(){}
		KHTG(double st, float tg)
		{
			this ->st, st;
			this ->tg, tg;
		}
		~KHTG(){}
		
		void nhapKHTG(){
			NGUOI::nhapNguoi();
			do{
			cout<<"\tNhap so tien: ";
			cin>>st;
			if(st <10000000)
			cout<<"Nhap lai";
			}while(st <10000000);
			do{
			cout<<"\tNhap thoi gian theo thang: ";
			cin>>tg;
			if(tg < 1 || tg > 12)
			cout<<"Nhap lai";
			}while(tg < 1 || tg > 12);
			cin.ignore();
		}
		
		void xepLoaiKHTG()
		{
			if(st >= 10000000 && st <= 999999999)
			{
				cout<<setw(15)<<"Loai TB";
			}
			else
			{
				cout<<setw(16)<<"Loai vip";
			}
		}
		
		friend bool operator>(KHTG &a, KHTG &b){
			return (a.tg > b.tg);
		}
		
		void xuatKHTG(){
			NGUOI::xuatNguoi();
			cout<<setw(15)<<st
				<<setw(15)<<tg;
		}
		
		void tieuDe2()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MING"
				<<setw(15)<<"GIOI TINH"
				<<setw(15)<<"SO TIEN"
				<<setw(15)<<"THOI GIAN"
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
	
	cout<<"\nNhap so luong KHTG: ";
	cin>>n;
	KHTG *khachhang = new KHTG[n];
	cin.ignore();
	cout<<"\nNhap cac thong tin cua KHTG: \n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nKHTG thu "<<i+1<<": \n";
		khachhang[i].nhapKHTG();
	}
	cout<<"\nDanh sach KHTG tang dan theo so thang gui: \n";
	khachhang->tieuDe2();
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(khachhang[i] > khachhang[j])
			{
				KHTG temp = khachhang[i];
					khachhang[i] = khachhang[j];
					khachhang[j] = temp;
			}
		}
		cout<<"\nKHTG thu "<<i+1<<": \n";
		khachhang[i].xuatKHTG();
		khachhang[i].xepLoaiKHTG();
	}
	cout<<endl;
}