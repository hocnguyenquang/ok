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
		
		void nhapNguoi()
		{
			
			cout<<"\tNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\tNhap so chung minh: ";
			cin.getline(scm, 10);
			cout<<"\tNhap gioi tinh: ";
			cin.getline(gt, 3);
		}
		
		void xuatNguoi()
		{
			cout<<setw(35)<<ht
				<<setw(20)<<scm
				<<setw(15)<<gt;
		}
		
		void tieuDe()
		{
			cout<<setw(35)<<"HO TEN"
				<<setw(20)<<"SO CHUNG MINH"
				<<setw(15)<<"GIOI TINH";
		}	
};

class GV : public NGUOI{
	private:
		char tdcm[10];
		int tn;
		
	public:
		GV(){}
		GV(char *ht, char *scm, char *gt, char *tdcm, int tn)
		:NGUOI(ht, scm, gt)
		{
			strcpy(this ->tdcm, tdcm);
					this ->tn = tn;
		}
		~GV(){}
		
		void nhapGV()
		{
			cin.ignore();
			NGUOI::nhapNguoi();
			
			cout<<"\tNhap trinh do: ";
			cin.getline(tdcm, 10);
			cout<<"\tNhap tham nien: ";
			cin>>tn;
		}
		
		float thamNien()
		{
			return 100*tn;
		}
		
		friend  bool operator>=(GV &a, GV &b)
		{
			return (a.thamNien() > b.thamNien());
		}
		
		void xuatGV()
		{
			NGUOI::xuatNguoi();
			cout<<setw(25)<<tdcm
				<<setw(15)<<thamNien()<<endl;
		}
		
		void tieuDe2()
		{
			NGUOI::tieuDe();	
			cout<<setw(25)<<"TRINH DO"
				<<setw(15)<<"THAM NIEN"<<endl;
		}		
};

main()
{
	int n,m;
	cout<<"Nhap so luong nguoi: ";
	cin>>n;
	NGUOI *ng = new NGUOI[n];
	cout<<"Nhap thong tin nguoi: ";
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		cout<<"Nguoi thu "<<i+1<<": \n";
		ng[i].nhapNguoi();
	}
	cout<<"\nXuat thong tin nguoi: \n";
	ng->tieuDe();
	cout<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<": \n";
		ng[i].xuatNguoi();
	}
	
	cout<<"\nNhap so luong giao vien: ";
	cin>>m;
	GV *giaovien = new GV[m];
	cout<<"Nhap thong tin giao vien: ";
	for(int i = 0; i < m; i++)
	{
		cout<<"\nGiao vien thu "<<i+1<<": \n";
		giaovien[i].nhapGV();
	}
	cout<<"\nDanh sach tang dan theo tham nien: \n";
	cin.ignore();
	giaovien->tieuDe2();
	for(int i = 0; i < m; i++)
	{
		for(int j = i+1; j<m; j++)
		{
			if(giaovien[i] >= giaovien[j])
				{
					GV temp = giaovien[i];
						giaovien[i] = giaovien[j];
						giaovien[j] = temp;
				}
		} 
		cout<<"\nGiao vien thu "<<i+1<<": \n";
		giaovien[i].xuatGV();
	}		
}