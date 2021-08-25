#include<iostream.h>
using namespace std;

class GV
{
	private:
		char ht[30];
		char bangCap[15];
		char chuyenNghanh[20];
		int tuoi;
		float bacLuong;
	public:
		GV(){}
		~GV(){}
		void set()
		{
			cin.ignore();
			cout<<"\nNhap ho ten: ";
			cin.getline(ht,30);
			cout<<"\nNhap bang cap duoc dao tao cao nhat: ";
			cin.getline(bangCap,15);
			cout<<"\nNhap chuyen nganh: ";
			cin.getline(chuyenNghanh,20);
			cout<<"\nNhap tuoi: ";
			cin>>tuoi;
			cout<<"\nNhap bac luong: ";
			cin>>bacLuong;
		}
		void get()
		{
			cout<<"\nHo ten: "<<ht;
			cout<<"\nBang cap duoc dao tao cao nhat: "<<bangCap;
			cout<<"\nChuyen nganh: "<<chuyenNghanh;
			cout<<"\nTuoi: "<<tuoi;
			cout<<"\nBac luong: "<<bacLuong;
		}
		int getBl()
		{
			return bacLuong;
		}
		int lcb()
		{
			return bacLuong*610;
		}
		string getHt()
		{
			return ht;
		}
};
int main()
{
	int n;
	cout<<"\nNhap so luong giao vien: ";
	cin>>n;
	GV gv[n];
	cout<<"\nNhap thong tin giao vien: \n";
	for(int i=0; i<n; i++)
	{
		gv[i].set();
	}
	cout<<"\nDanh sach giao vien co tien luong nho hon 2000: ";
	for(int i=0; i<n; i++)
	{
		if(gv[i].getBl() < 2000)
		{
			gv[i].get();
		}
	}
	cout<<endl;
	cout<<"\nDanh sach sau khi sap xep la: ";
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(gv[i].getHt().compare(gv[j].getHt()) > 0)
			{
				GV temp = gv[i];
					gv[i] = gv[j];
					gv[j] = temp;
			}
		}
		gv[i].get();
	}
	cout<<endl;
}