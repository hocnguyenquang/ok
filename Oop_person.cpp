#include<iostream.h>
using namespace std;

class Person
{
	private:
		char ten[30];
		int gioiTinh; //1 la Nam con 2 la nu
		char ngaySinh[15];
		char diaChi[40];
	
	public:
		Person(){}
		Person(char *ten, int gioiTinh, char *ngaySinh, char *diaChi)
		{
			strcpy(this ->ten, ten);
					this -> gioiTinh = gioiTinh;
			strcpy(this ->ngaySinh, ngaySinh);
			strcpy(this ->diaChi, diaChi);
		}
		
		void setTen(char *ten)
		{
			strcpy(this ->ten, ten);
		}
		char getTen()
		{
			return char(ten);
		}
		void setGioiTinh(int gioiTinh)
		{
			this ->gioiTinh = gioiTinh;
		}	
		int getGioiTinh()
		{
			return gioiTinh;
		}
		void setNgaySinh(char *ngaySinh)
		{
			strcpy(this ->ngaySinh,ngaySinh);
		}
		char  getNgaySinh()
		{
			return char(ngaySinh);
		}
		void setDiaChi(char *diaChi)
		{
			strcpy(this ->diaChi,diaChi);
		}
		char getDiaChi()
		{
			return char(diaChi);
		}
		
		void inputInfor()
		{
			cin.ignore();
			cout<<"\nNhap ten: ";
			cin.getline(ten,30);
			cout<<"\nNhap ngay sinh: ";
			cin.getline(ngaySinh,15);
			cout<<"\nNhap dia chi: ";
			cin.getline(diaChi, 40);
			do{
			cout<<"\nNhap gioi tinh(1.Nam 2.Nu): ";
			cin>>gioiTinh;
			if(gioiTinh < 1 || gioiTinh > 2)
			cout<<"\nNhap lai";
			}while(gioiTinh < 1 || gioiTinh > 2);
		}
		
		void showInfor()
		{
			cout<<"\nTen: "<<ten<<endl;
			cout<<"\nNgay sinh: "<<ngaySinh<<endl;
			cout<<"\nDia chi: "<<diaChi<<endl;
			cout<<"\nGioi tinh: "<<gioiTinh<<endl;
		}
};

class student : public Person
{
	private:
		char maSinhVien[8];
		float diemTB;
		
};

main()
{
	int n;
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	Person *nguoi = new Person();
	
	cout<<"\nInput infor: "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<": ";
		nguoi[i].inputInfor();
	}
	
	cout<<"\nShow infor: "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<": ";
		nguoi[i].showInfor();
	}
}