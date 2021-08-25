#include<iostream.h>
using namespace std;
class DIENTU{
	private:
		char ma[15];
		char ten[30];
		float donGa;
		
	public:
	DIENTU(){}
		DIENTU(char *ma, char *ten, float donGa)
		{
			strcpy(this ->ma, ma);
			strcpy(this ->ten, ten);
					this ->donGa = donGa;
		}
		
		void setData()
		{
			cin.ignore();
			cout<<"\nNhap ma: ";
			cin.getline(ma,15);
			cout<<"\nNhap ten: ";
			cin.getline(ten,30);
			do{
			cout<<"\nNhap don gia: ";
			cin>>donGa;
			if(donGa <= 0)
			cout<<"\nSai dieu kien!!!";
			}while(donGa <= 0);
		}
		
		void getData()
		{
			cout<<"\nMa: "<<ma<<endl;
			cout<<"\nTen: "<<ten<<endl;
			cout<<"\nDon gia: "<<donGa<<endl;
		}
		
		string getTen()
		{
			return this ->ten,ten;
		}		
};

class TULANH : public DIENTU
{
	private:
		float dungtich;
		float tieuthu;
		
	public:
		TULANH(){}
		TULANH(char *ma, char *ten, float donGa, float dungtich, float tieuthu)
		:DIENTU(ma,ten,donGa){
			this ->dungtich = dungtich;
			this ->tieuthu = tieuthu;
		}
	
	friend istream & operator>>(istream &is, TULANH &i)
	{
		cout<<"\nNhap dung tich(don vi: kg): ";
		is>>i.dungtich;
		cout<<"\nNhap tieu thu: ";
		is>>i.tieuthu;
		return is;
	}
	
	friend ostream & operator<<(ostream &os, TULANH &o)
	{
		cout<<"\nDung tich: "<<o.dungtich<<endl;
		cout<<"\nTieu thu: "<<o.tieuthu<<endl;
		cout<<"\nPhi van chuyen: "<<o.vanChuyen()<<endl;
		return cout;
	}
	
	int vanChuyen()
	{
		if(dungtich >= 70)
		{
			return 500000;
		}
		if(dungtich > 55)
		{
			return 400000;
		}
		else
		{
			return 100000;
		}
	}
	
	friend bool operator<(TULANH a, TULANH b)
	{
		return a.dungtich < b.dungtich;
	}
	bool operator ==(string x)
	{
		if(getTen()==x)
		return true;
		return false;
	}
	
};

main()
{
	int n;
	cout<<"\nNhap so luong tu lanh: ";
	cin>>n;
	TULANH *tl = new TULANH[n];
	cout<<"\n*****Nhap thong tin cua tu lanh*****\n"; 
	for(int i = 0; i < n; i++)
	{
		cout<<"\nTu lanh thu "<<i+1<<": "<<endl;
		cin>>tl[i];
	}
	cout<<"\n*****Xuat thong tin cua tu lanh*****\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nTu lanh thu "<<i+1<<": "<<endl;
		cout<<tl[i];
	}
	cout<<"\n*****Tu lanh co dung tich nho nhat*****\n";
	TULANH min = tl[0];
	for(int i = 0; i < n; i++)
	{
		if(tl[i]<min)
		{
			min = tl[i];
		}
	}
	cout<<min;
	cout<<"\n*****Danh sach tu lanh hang SamSung*****\n";
	for(int i = 0; i < n; i++)
	{
		if(tl[i]=="SamSung")
		{
			cout<<tl[i]<<endl;
		}
	}
}