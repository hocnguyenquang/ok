#include<iostream.h>
#include<iomanip.h>
using namespace std;

class GV{
	private:
		char ht[30];
		char cn[20];
		float bl;
		
	public:
		GV(){}
		GV(char *ht, char *cn, float bl)
		{
			strcpy(this ->ht, ht);
			strcpy(this ->cn, cn);
					this ->bl, bl;	
		}
		~GV(){}	
		
		void nhapGV(){
			cout<<"\tNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\tNhap chuyen nganh: ";
			cin.getline(cn, 25);
			cout<<"\tNhap bac luong: ";
			cin>>bl;
			cin.ignore();
		}
		void xuatGV(){
			cout<<setw(35)<<ht
				<<setw(25)<<cn
				<<setw(15)<<bl;
		}
		
		void tieuDe1(){
			cout<<setw(35)<<"HO TEN"
				<<setw(25)<<"CHUYEN NGANH"
				<<setw(15)<<"BAC LUONG";
		}
};

class GVDH : public GV{
	private:
		char cmk[20];
		float sn;
		
	public:
		GVDH(){}
		GVDH(char *cmk, float sn)
		{
			strcpy(this ->cmk, cmk);
					this ->sn, sn;
		}
		~GVDH(){}
		
		void nhapGVDH(){
			GV::nhapGV();
			cout<<"\tNhap chuyen mon khoa: ";
			cin.getline(cmk, 20);
			do{
			cout<<"\tNhap so nam cong tac: ";
			cin>>sn;
			if(sn <= 0)
			cout<<"\nNhap lai \n";
			}while(sn <= 0);
			cin.ignore();
		}
		
		string xepLoai(){
			if(sn >= 0.0 && sn <= 4.9){
				return "Giang vien tap su";
			}
			else if(sn >= 5.0 && sn <= 9.9){
				return "Giang vien chinh";
			}
			else{
				return "Giang vien cao cap";
			}
		}
		
		friend bool operator>=(GVDH &a, GVDH &b){
			return (a.sn > b.sn);
		}
		
		void xuatGVDH(){
			GV::xuatGV();
			cout<<setw(25)<<cmk
				<<setw(15)<<sn
				<<setw(30)<<xepLoai()<<endl;
		}
		
		void tieuDe2(){
			GV::tieuDe1();
			cout<<setw(25)<<"CHUYEN MON"
				<<setw(15)<<"SO NAM"
				<<setw(30)<<"XEP LOAI"<<endl;
		}
};

main(){
	int n;
	do{
		cout<<"\nNhap so luong giao vien: ";
		cin>>n;
		if(n <= 0)
		cout<<"\nNhap lai \n";
	}while(n <= 0);
	GV *giaovien = new GV[n];
	cin.ignore();
	cout<<"\nNhap thong tin cac giao vien: \n";
	for(int i = 0; i < n; i++){
		cout<<"\nGiao vien thu "<<i+1<<": \n";
		giaovien[i].nhapGV();
	}
	cout<<"\nXuat thong tin cac giao vien: \n";
	giaovien->tieuDe1();
	for(int i = 0; i < n; i++){
		cout<<"\nGiao vien thu "<<i+1<<": \n";
		giaovien[i].xuatGV();
	}
	cout<<endl;
	
	do{
		cout<<"\nNhap so luong giao vien dai hoc: ";
		cin>>n;
		if(n <= 0)
		cout<<"\nNhap lai \n";
	}while(n <= 0);
	GVDH *giangvien = new GVDH[n];
	cin.ignore();
	cout<<"\nNhap thong tin cac giang vien dai hoc: \n";
	for(int i = 0; i < n; i++){
		cout<<"\nGiang vien dai hoc thu "<<i+1<<": \n";
		giangvien[i].nhapGVDH();
	}
	cout<<"\nDanh sach giang vien dai hoc la giang vien cao cap: \n";
	giangvien->tieuDe2();
	for(int i = 0; i < n; i++){
		if(giangvien[i].xepLoai()== "Giang vien cao cap"){
			giangvien[i].xuatGVDH();
		}
	}
	cout<<endl;
}