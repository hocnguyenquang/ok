#include<iostream.h>
#include<iomanip.h>
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
		
		void nhapNGUOI()
		{
			cout<<"\nNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\nNhap so chung minh: ";
			cin.getline(scm, 10);
			cout<<"\nNhap gioi tinh(nam/nu): ";
			cin.getline(gt, 3);
		}
		
		void xuatNGUOI()
		{
			cout<<setw(35)<<ht
				<<setw(15)<<scm
				<<setw(15)<<gt<<endl;
		}	
		
		void tieuDe1()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MINH"
				<<setw(15)<<"GIOI TINH"<<endl;
		}	
};

class HS : public NGUOI{
	private:
		char cn[20];
		float dtk;
		
	public:
		HS(){}
		HS(char *ht, char *scm, char *gt, char *cn, float dtk)
		:NGUOI(ht, scm, gt)
		{
			strcpy(this ->cn, cn);
					this ->dtk = dtk;
		}
		~HS(){}
		
		void nhapHS()
		{
			NGUOI::nhapNGUOI();
			cout<<"\nNhap chuyen nganh: ";
			cin.getline(cn, 20);
			do{
				cout<<"\nNhap diem tong ket: ";
				cin>>dtk;
				if(dtk < 0 || dtk > 10)
				cout<<"\nNhap lai";
			}while(dtk < 0 || dtk > 10);
		}
		
		void xepLoai()
		{
			if(dtk >= 0.0 || dtk <= 4.9)
			{
				cout<<"\nLoai yeu "; 
			}
			else if(dtk >= 5.0 || dtk <= 7.9)
			{
				cout<<"\nLoai kha "; 
			}
			else
			{
				cout<<"\nLoai gioi ";
			}
		}
		
		friend bool operator > (HS &a, HS &b)
		{
			return a.dtk > b.dtk;
		}
		
		void xuatHS()
		{
			NGUOI::xuatNGUOI();
			cout<<setw(25)<<cn
				<<setw(15)<<dtk<<endl;
		}
		
		void tieuDe2()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MINH"
				<<setw(15)<<"GIOI TINH"
				<<setw(25)<<"CHUYEN NGANH"
				<<setw(15)<<"DIEM TONG KET"<<endl;
		}		
};

main()
{
	int n;
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	NGUOI *ng = new NGUOI[n];
	cout<<"\nNhap thong tin nguoi: ";
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu: "<<i+1<<": \n";
		ng[i].nhapNGUOI();
	}
	
	cout<<"\nXuat thong tin nguoi: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu: "<<i+1<<": \n";
		ng[i].tieuDe1();
		ng[i].xuatNGUOI();
	}
	
	cout<<"\nNhap so luong hoc sinh: ";
	cin>>n;
	HS *hocsinh = new HS[n];
	cout<<"\nNhap thong tin hoc sinh: ";
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		cout<<"\nHoc sinh thu: "<<i+1<<": \n";
		ng[i].nhapHS();
	}
	
	cout<<"\nDanh sach HS dat gioi: ";
	for(int i = 0; i < n; i++)
	{
		if(ng[i].dtk )
	}
}