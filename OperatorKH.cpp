#include<iostream.h>
#include<string.h>
using namespace std;

struct Date{
	int ngay,thang,nam;
};
class KH{
	private:
		char ht[30];
		int date;
		char cmt[10];
		char hoKhauK[50];
	public:
		KH(){}
		KH(char *ht, char *cmt, char *hoKhauK)
		{
			strcpy(this ->ht, ht);
			strcpy(this ->cmt, cmt);
			strcpy(this ->hoKhauK, hoKhauK);		
		}
		~KH(){}
		/*
void setDate()
		{
			cout<<"\nNhap ngay: ";
			cin>>date.ngay;
			cout<<"\nNhap thang: ";
			cin>>date.thang;
			cout<<"\nNhap nam: ";
			cin>>date.nam;
		}*/
		friend istream& operator>>(istream& is, KH &i)
		{
			cin.ignore();
			cout<<"\nNhap ho ten: ";
			cin.getline(i.ht,30);
			do{
			cout<<"\nNhap chung minh thu: ";
			cin.getline(i.cmt,10);
			if(i.cmt <= 0)
			cout<<"\nKhong co cmt nao = 0 hoac la so am"<<endl;
			}while(i.cmt <= 0 );
			cout<<"\nNhao ho khau: ";
			cin.getline(i.hoKhauK,50);
			//i.setDate();
			return is;
		}
		
		friend ostream& operator<<(ostream& os, KH &o)
		{
			cout<<"\nHo ten: "<<o.ht<<endl;
			cout<<"\nCmt: "<<o.cmt<<endl;
			cout<<"\nHo khau: "<<o.hoKhauK<<endl;
			return cout;
		}
		void xuat()
		{
			cout<<"\nHo ten: "<<ht<<endl;
			cout<<"\nCmt: "<<cmt<<endl;
			cout<<"\nHo khau: "<<hoKhauK<<endl;
			
		}
		friend bool operator>(KH &a, KH &b)
		{
			return(a.date > b.date);
		}
		
		bool timKiem(){
			
				if(strcmpi(hoKhauK,"Ha Noi")==0)
					{	
						return (true);
					}
					return (false);		
			}		
};

main()
{
	int n;
	cout<<"\nNhap n: ";
	cin>>n;
	KH *khachHang = new KH();
	cout<<"\nNhap du lieu khach hang: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nKhach hang thu "<<i+1<<": ";
		cin>>khachHang[i];
	}
	
	cout<<"\nXuat du lieu khach hang: ";
	for(int i = 0 ;i < n; i++)
	{
		cout<<"\nKhach hang thu "<<i+1<<": ";
		cout<<khachHang[i];
	}
	cout<<"\nDanh sach khach hang co ho khau o ha noi la: ";
	for(int i = 0 ;i < n; i++)
	{
		if(khachHang[i].timKiem()==false)
		{
			if(i == n - 1)
			{
				cout<<"\nKhong co khach hang nao co ho khau o ha noi"<<endl;
			}
			continue;		
		}
		else{
			cout<<"\nKhach hang thu "<<i+1<<": ";
			cout<<khachHang[i];
		}
	}
	
	cout<<"\nSap xep tang dan theo tuoi: ";
	for(int i = 0; i < n; i++)
	{
		if(khachHang[i] > khachHang[i+1])
		{
			KH temp = khachHang[i];
				khachHang[i] = khachHang[i+1];
				khachHang[i+1] = temp;
		}
		cout<<khachHang[i];
	}
}