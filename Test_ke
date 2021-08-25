#include<iostream.h>
#include<string.h>
using namespace std;
class Nguoi{
	private:
		int Ma;
		char ten[30];
		int gioiTinh;//1.nam 2.nu
	public:
		void nhap();
		void hienthi(){
			cout<<Ma<<", "<<ten<<", "<<gioiTinh;
		};	
};
void Nguoi::nhap(){
	cout<<"\nNhap id: ";
	cin>>Ma;
	cout<<"\nNhap ten: ";
	cin>>ten;
	cout<<"\nGioi tinh: ";
	cin>>gioiTinh;
}
class Sinhvien : public Nguoi{
	private:
		float diem;
		float hocphi;
		char nganh[20];
	public:
		void nhap();
		void hienthi();	
};
void Sinhvien::nhap(){
	Nguoi::nhap();
	cout<<"\nNhap diem: ";
	cin>>diem;
	cout<<"\nNhap hoc phi: ";
	cin>>hocphi;
	cout<<"\nNhap nganh: ";
	cin>>nganh;
}
void Sinhvien::hienthi(){
	Nguoi::hienthi();
	cout<<diem<<", "<<hocphi<<", "<<nganh;
}
main()
{
	Sinhvien n;
	n.nhap();
	n.hienthi();
}