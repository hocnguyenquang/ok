#include<iostream.h>
#include<iomanip.h>
using namespace std;
class MatHang{
	private:
		char maHang[15];
		char tenHang[30];
		float donGia;
		
	public:
		MatHang(){}
		MatHang(char *maHang,char *tenHang, float donGia)
		{
		 	strcpy(this ->maHang, maHang);
			strcpy(this ->tenHang, tenHang);
					this ->donGia, donGia;
		}
		~MatHang(){}
		
		void setInforMatHang(){
			cout<<"\tNhap ma hang: ";
			cin.getline(maHang, 15);
			cout<<"\tNhap ten hang: ";
			cin.getline(tenHang, 30);
			cout<<"\tNhap don gia: ";
			cin>>donGia;
			cin.ignore();
		}
		
		friend istream& operator>>(istream &is, MatHang &a){
			
			a.setInforMatHang();
			return is;
		}
		
		float getDonGia(){
			return donGia;
		}
		
		string getMaHang(){
			return maHang;
		}	
};

class BanhKeo : public MatHang{
	private:
		char noiSx[40];
		
	public:
		BanhKeo(){}
		BanhKeo(char *maHang,char *tenHang, float donGia,char *noiSx)
		:MatHang(maHang, tenHang, donGia)
		{
			this ->noiSx, noiSx;
		}
		~BanhKeo(){}
		
		float chietKhau(){
			return getDonGia()*0,01; 
		}
		
		friend istream& operator>>(istream &is, BanhKeo &a){
			a.setInforMatHang();
			cout<<"\tNhap noi san xuat: ";
			cin.getline(a.noiSx, 40);
			return is;
		}
		
		friend ostream& operator<<(ostream &os, BanhKeo &b){
			cout<<setw(40)<<b.noiSx<<endl;
			return cout;
		}
		
		
};

main(){
	int m;
	BanhKeo *bk = new BanhKeo[m];
	cout<<"\nNhap so luong banh keo: ";
	cin>>m;
	cin.ignore();
	cout<<"\nNhap thong tin cac banh keo: \n";
	for(int i = 0; i < m; i++){
		cout<<"\nBanh keo thu "<<i+1<<": \n";
		cin>>bk[i];
	}
	cout<<"\nCac mat hang co ma MO1	la: \n";
	for(int i = 0; i < m; i++){
		if(bk[i].getMaHang()== "MO1")
		cout<<"\nBanh keo thu "<<i+1<<": \n";
		cout<<bk[i];
		bk[i].chietKhau();
	}
	
}