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

class CN : public NGUOI{
	private:
		char cv[20];
		float sn;
		
	public:
		CN(){}
		CN(char *ht, char *scm, char *gt, char *cv, float sn)
		:NGUOI(ht, scm, gt)
		{
			strcpy(this ->cv, cv);
					this ->sn = sn;
		}
		~CN(){}
		
		void nhapCN(){
			NGUOI::nhapNguoi();
			cout<<"\tNhap cong viec: ";
			cin.getline(cv, 20);
			do{
			cout<<"\tNhap so nam lam viec: ";
			cin>>sn;
			if(sn < 0)
			cout<<"Nhap lai";
			}while(sn < 0);
			cin.ignore();
		}	
		
		void xepLoaiCV(){
			if(sn >= 0.0 && sn <= 2.9)
			{
				cout<<setw(18)<<"Loai so cap";
			}
			else if(sn >= 3.0 && sn <= 9.9)
			{
				cout<<setw(21)<<"Loai trung cap";
			}
			else{
				cout<<setw(18)<<"Loai cao cap";
			}
		}
		
		friend bool operator>(CN &a, CN &b){
			return (a.sn > b.sn);
		}
		
		void xuatCN(){
			NGUOI::xuatNguoi();
			cout<<setw(25)<<cv
				<<setw(15)<<sn;
		}
		
		void tieuDe2(){
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MING"
				<<setw(15)<<"GIOI TINH"
				<<setw(25)<<"CONG VIEC"
				<<setw(15)<<"SO NAM"
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
	
	cout<<"\nNhap so luong cong nhan: ";
	cin>>n;
	CN *congnhan = new CN[n];
	cin.ignore();
	cout<<"\nNhap thong tin cac cong nhan: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nCong nhan thu "<<i+1<<": \n";
		congnhan[i].nhapCN();
	}
	cout<<"\nDanh sach tang dan cua cong nhan theo so nam: \n";
	congnhan->tieuDe2();
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(congnhan[i] > congnhan[j])
			{
				CN temp = congnhan[i];
					congnhan[i] = congnhan[j];
					congnhan[j] = temp;
			}
		}
		cout<<"\nCong nhan thu "<<i+1<<": \n";
		congnhan[i].xuatCN();
		congnhan[i].xepLoaiCV();
	}
	cout<<endl;
}