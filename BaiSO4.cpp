#include<iostream.h>
#include<iomanip.h>
using namespace std;
 
class Nguoi{
	private:
		char hoTen[30];
		float ns;
 
	public:
		Nguoi(){}
		Nguoi(char *hoTen, float ns)
		{
			strcpy(this ->hoTen, hoTen);
					this ->ns, ns;
		}
		~Nguoi(){}
 
		void nhapthongtin(){
			cout<<"\tNhap ho ten: ";
			cin.getline(hoTen, 30);
			cout<<"\tNhap nam sinh: ";
			cin>>ns;
			cin.ignore();
		}
 
		void hienthi(){
			cout<<left<<setw(35)<<hoTen
				<<setw(15)<<ns;
		}
 
 
};
 
class ThiSinh : public Nguoi{
	private:
		char sbd[15];
		float toan, ly, hoa;
 
	public:
		ThiSinh(){}
		ThiSinh(char *hoTen, float ns, char *sbd, float toan, float ly, float hoa)
		:Nguoi(hoTen, ns)
		{
			strcpy(this ->sbd, sbd);
					this ->toan, toan;
					this ->ly, ly;
					this ->hoa, hoa; 
		}
		~ThiSinh(){}
 
		void nhapthongtinTS(){
			Nguoi::nhapthongtin();
			cout<<"\tNhap sbd: ";
			cin.getline(sbd, 15);
			cout<<"\tNhap toan: ";
			cin>>toan;
			cout<<"\tNhap ly: ";
			cin>>ly;
			cout<<"\tNhap hoa: ";
			cin>>hoa;
			cin.ignore();
		}
 
		void hienthiTS(){
			Nguoi::hienthi();
			cout<<setw(20)<<sbd
				<<setw(15)<<toan
				<<setw(15)<<ly
				<<setw(15)<<hoa
				<<setw(15)<<tinhTong3Mon()<<endl;
		}
 
		float tinhTong3Mon(){
			return (toan + ly + hoa);
		}
 
		friend bool operator>(ThiSinh &a, ThiSinh &b){
			return (a.tinhTong3Mon() > b.tinhTong3Mon());
		}
 
		char* getSBD(){
			return sbd;
		}
 
		bool kiemtraTS(){
			if(tinhTong3Mon()<5)
			{
				return 0;
			}
			return 1;
		}
};
 
void tieuDe2(){		
	cout<<left
		<<setw(35)<<"HO TEN"
		<<setw(15)<<"NAM SINH"
		<<setw(20)<<"SBD"
		<<setw(15)<<"TOAN"
		<<setw(15)<<"LY"
		<<setw(15)<<"HOA"
		<<setw(15)<<"TONG DIEM"<<endl;
}
 
bool timkiemtheoSBD(char a[20], char sbd[20])
{
	if(strcmpi(a,sbd) == 0){
		return 1;		
	}
	return 0;
}
 
main(){
	int n;
	cout<<"\nNhap so luong thi sinh: ";
	cin>>n;
	ThiSinh *ts = new ThiSinh[n];
	Nguoi a[100];
	cin.ignore();
 
	cout<<"\nNhap thong tin cac thi sinh: \n";
	for(int i = 0; i < n; i++){
		cout<<"\nThi sinh thu "<<i+1<<": \n";
		ts[i].nhapthongtinTS();
	}
 
	cout<<"\nDanh sach thi sinh co tong diem 3 mon tang dan: \n";
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(ts[i] > ts[j]){
				ThiSinh temp = ts[i];
						ts[i] = ts[j];
						ts[j] = temp;
			}
		}
	}
	cout<<"\nHien thi sau khi sap xep tong diem 3 mon tang dan: "<<endl;
	tieuDe2();
	for(int i=0; i<n; i++)
	{
		ts[i].hienthiTS();
	}
 
	// Tim kiem theo sbd: 
	char sbd[20];
	cout<<"\nNhap vao sbd can tim kiem: ";
	cin.getline(sbd, 20);
 
	int dem = 0, dem2=0;
	cout<<"\nTHONG TIN SAU KHI TIM KIEM: "<<endl;
	tieuDe2();
	for(int i=0; i<n;i++)
	{
		if(timkiemtheoSBD(ts[i].getSBD(), sbd) == 1){
			ts[i].hienthiTS();
			dem++;
		}
		if(ts[i].kiemtraTS()==1){
			dem2++;
		}
	}	
 
	if(dem==0){
		cout<<"\nKhong tim thay thi sinh co sbd: "<<sbd<<endl;
	}
 
	// Thong ke theo ty le
	int soTS_thoa_man = dem2;
	float tyle = (float)dem2/n * 100;
	if(soTS_thoa_man == 0){
		cout<<"\nTHONG KE TS CO TONG DIEM >=5 la: 0% "<<endl;
	}
	else{
		cout<<"\n THONG KE TS CO TONG DIEM >=5: "<<soTS_thoa_man<<"("<<tyle<<"%)"<<endl;	
	}	
}