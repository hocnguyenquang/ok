#include<iostream.h>
#include<string.h>
using namespace std;
class sanpham{
	private:
	string masp;
	string tensp;
	string loaisp;
	float gia;
	public: 
	sanpham (string masp="", string tensp="", string loaisp="", float gia=0) {
		this->masp = masp;
		this->tensp = tensp;
		this->loaisp= loaisp;
		this->gia = gia;
	} 	
	
	~sanpham(){}
	
	friend ostream& operator <<(ostream& os,sanpham& s) {
		cout<<"Ma san pham: "<<s.masp<<endl;
		cout<<"Ten san pham: "<<s.tensp<<endl;
		cout<<"Loai san pham: "<<s.loaisp<<endl;
		cout<<"Don gia: "<<s.gia<<endl;
		return cout;
	}
	
	friend istream& operator >>(istream& is,sanpham& s){
		cout<<"ten:"; is>>s.tensp;
		cout<<"ma:"; is>>s.masp;
		cout<<"loai:"; is>>s.loaisp;
		cout<<"gia:"; is>>s.gia;
		return is;
	}
	
	float getgia(){
		return gia;
	}
};

class hoadon : public sanpham{
	private:
	string mahoadon;
	int ngaylap;
	int soluong;
	public:
	hoadon (string mahoadon="", int ngaylap= 0, int soluong	=0) {
		this->mahoadon = mahoadon;
		this->ngaylap = ngaylap;
		this->soluong= soluong;
	} 	
	
	~hoadon(){}
	
		friend ostream& operator<<(ostream& os,hoadon& s) {
		cout<<(sanpham&) s;
		cout<<"Ma hoa don: "<<s.mahoadon<<endl;
		cout<<"ngay lap: "<<s.ngaylap<<endl;
		cout<<"so luong: "<<s.soluong<<endl;
		return cout;
	}
	
		friend istream& operator>>(istream& is,hoadon& s){
		is>>(sanpham&)s;
		cout<<"ma:"; is>>s.mahoadon;
		cout<<"ngay lap:"; is>>s.ngaylap;
		cout<<"so luong:"; is>>s.soluong;
		return is;
	}
	float thanhtien(){
		return soluong * getgia();
	}
	
	bool hoadon:: operator < (hoadon &a){
		return (thanhtien() < a.thanhtien());
	} 
	
};

main()
{
	sanpham a[100];
	hoadon b[10];
	int n,m;
	cout<<"Nhap n: ";cin>>n;
	for(int i = 0;i< n;i++){
		cin>>a[i];
	}
	for(int i = 0;i< n;i++)
	{
	cout<<a[i]<<endl;
	}
	cout<<"so luong hoa don la: ";
	cin>>m;
	for(int i=0;i<m;i++){
		cout<<"---------nhap hoa don------------"<<endl;
		cin>>b[i];
	}
	cout<<endl;
	for(int i=0;i<m;i++){
	cout<<"---------xuat hoa don-------------"<<endl;
	cout<<b[i]<<endl;}
	for(int i=0;i<m;i++)
	{
	cout<<"thanh tien la: "<<b[i].thanhtien()<<endl;
	
	}
	hoadon max;
	max = b[0];
	for(int i=0;i<m;i++){
		if(max<b[i+1]){
		max = b[i+1] ;
		}
	}
	/*
cout<<"-----hoa don co thanh tien lon nhat la------"<<endl;
	for(int i=0;i<m;i++)
	{
		if(max == b[i].thanhtien())
		cout<<b[i];
		}*/
	
}