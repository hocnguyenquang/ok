#include<iostream.h>
#include<string.h>
using namespace std;
class color
{
	private:
		char TenMau[30];
		char MaMau[15];
	
	public:
		color(){}
		color(char * TenMau = "", char * MaMau = "")
		{
			strcpy(this -> TenMau, TenMau);
			strcpy(this -> MaMau, MaMau);
		}
		~color(){}
		
		friend istream &operator>>(istream &is, color &i)
		{
			cin.ignore();
			cout<<"\nNhap ten mau: ";
			cin.getline(i.TenMau,30);
			cout<<"\nNhap ma mau: ";
			cin.getline(i.MaMau,15);
			return is;
		}
		friend ostream &operator>>(ostream &os, color &o)
		{
			os<<"\nTen mau: "<<o.TenMau<<endl;
			os<<"\nMa mau: "<<o.MaMau<<endl;
			return os;
		}
		string getTenMau()
		{
			return TenMau;
		}
		
		string getMaMa()
		{
			return MaMau;
		}
			
};
class Point
{
	private:
		int x,y;
	
	public:
		Point(){}
		Point(int x = 0, int y = 0)
		{
			this -> x = x;
			this -> y = y;
		}
		~Point(){}
		friend istream &operator>>(istream &is, Point &i)
		{
			cout<<"\nNhap x: ";
			cin>>i.x;
			cout<<"\nNhap y: ";
			cin>>i.y;
			return is;
		}
		friend ostream &operator>>(ostream &os, Point &o)
		{
			os<<"\nX = "<<o.x<<endl;
			os<<"\nY = "<<o.y<<endl;
			return os;
		}
		bool CheoChinh()
		{
			if(x == y)
				return true;
			else
				return false;
		}	
};
class Pixel : public color, public Point
{
	public:
		Pixel(){}
		Pixel(char * TenMau = "", char * MaMau = "", int x = 0, int y = 0 )
		{
			strcpy(this -> TenMau, TenMau);
			strcpy(this -> MaMau, MaMau);
					this -> x = x;
					this -> y = y;
		}
		~Pixel(){}
};