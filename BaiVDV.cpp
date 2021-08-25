#include<iostream.h>
#include<string.h>
using namespace std;
class VanDongVien
{
	private:
	
		char hoten[30];
		int tuoi;
		char monthidau[15];
		float cannang;
		float chieucao;
	public: 
		VanDongVien(char * hoten = "", int tuoi = 0, char * monthidau = "", float cannang = 0.0,
					float chieucao = 0.0){
						strcpy(this ->hoten, hoten);
								this ->tuoi = tuoi;
						strcpy(this ->monthidau, monthidau);
								this ->cannang = cannang;
								this ->chieucao = chieucao;
		}
		
		void set()
		{
			cin.ignore();
			cout<<"\nNhap ho ten: ";
			cin.getline(hoten,30);
			cout<<"\nNhap mon thi dau: ";
			cin.getline(monthidau,15);
			cout<<"\nNhap tuoi: ";
			cin>>tuoi;
			cout<<"\nNhap can nang: ";
			cin>>cannang;
			cout<<"\nNhap chieu cao: ";
			cin>>chieucao;
		}
		
		void get()
		{
			cout<<"\nNhap ho ten: "<<hoten<<endl;
			cout<<"\nNhap mon thi dau: "<<monthidau<<endl;
			cout<<"\nNhap tuoi: "<<tuoi<<endl;
			cout<<"\nNhap can nang: "<<cannang<<endl;
			cout<<"\nNhap chieu cao: "<<chieucao<<endl;
		}	
};
main()
{
	
	int n;
	cout<<"\nNhap so luong vdv: ";
	cin>>n;
	
	VanDongVien *vdv = new VanDongVien[n];
	for(int i = 0; i < n; i++)
		{
			cout<<"\nNhap thong tin vdv thu "<<i+1<<": ";
			vdv[i].set();
		}
	cout<<endl;
	
	for(int i = 0; i < n; i++)
		{
			cout<<"\nXuat thong tin vdv thu "<<i+1<<": ";
			vdv[i].get();
		}
	cout<<endl;
}