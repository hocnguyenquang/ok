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

class KH : public NGUOI{
	private:
		char th[30];
		float sl;
		float dg;
		
	public:
		KH(){}
		KH(char *th, float sl, float dg)
		{
			strcpy(this ->th, th);
					this ->sl, sl;
					this ->dg, dg;
		}
		~KH(){}
		
		void nhapKH(){
			NGUOI::nhapNguoi();
			cout<<"\tNhap ten hang: ";
			cin.getline(th, 30);
			do{
			cout<<"\tNhap so luong: ";
			cin>>sl;
			if(sl < 0)
			cout<<"Nhap lai";
			}while(sl < 0);
			do{
			cout<<"\tNhap don gia: ";
			cin>>dg;
			if(dg < 0)
			cout<<"Nhap lai";
			}while(dg < 0);
			cin.ignore();
		}
		
		float soTienPhaiTra(){
			return sl*dg;
		}
		
		friend bool operator>(KH &a, KH &b){
			return (a.soTienPhaiTra() > b.soTienPhaiTra());
		}
		
		void xuatKH(){
			NGUOI::xuatNguoi();
			cout<<setw(35)<<th
				<<setw(15)<<sl
				<<setw(15)<<dg
				<<setw(15)<<soTienPhaiTra()<<endl;
		}
		
		void tieuDe2(){
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MING"
				<<setw(15)<<"GIOI TINH"
				<<setw(35)<<"TEN HANG"
				<<setw(15)<<"SO LUONG"
				<<setw(15)<<"DON GIA"
				<<setw(15)<<"TIEN TRA"<<endl;
		}
};

main(){
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
	
	cout<<"\nNhap so luong KH: ";
	cin>>n;
	KH *khachhang = new KH[n];
	cin.ignore();
	cout<<"\nNhap thong tin cac khach hang: \n";
	for(int i = 0; i < n; i++){
		cout<<"\nKhach hang thu "<<i+1<<": \n";
		khachhang[i].nhapKH();
	}
	cout<<"\nDanh sach khach hang tang dan theo so tien phai tra: \n";
	khachhang->tieuDe2();
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(khachhang[i] > khachhang[j]){
				KH temp = khachhang[i];
					khachhang[i] = khachhang[j];
					khachhang[j] = temp;
			}
		}
		cout<<"\nKhach hang thu "<<i+1<<": \n";
		khachhang[i].xuatKH();
	}
}