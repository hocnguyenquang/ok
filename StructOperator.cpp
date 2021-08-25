#include<iostream.h>
#include<string.h>
#include<iomanip.h>
using namespace std ; 
 
int stt=1;
struct Date{
	int ngay;
	int thang;
	int nam;
};
class KH{
	private:
 
		char ht[30];
		char cmt[10];
		char hk [30];
 
		Date date;
	public:
	    KH(){};
	    ~KH(){};
 
	    KH( char * ht, char * cmt , char * hk )
	    {
		//su dung hàm strcpy de sao chép noi dung tu bien nay sang bien kia
	    	strcpy( this -> ht,ht);
            strcpy( this -> cmt,cmt);
            strcpy( this -> hk,hk);
	    }
 
		void inputDate()
		{
	    	cout<<"\tNhap ngay sinh : ";
	      	cin>>date.ngay;
	      	cout<<"\tNhap thang sinh: ";
	      	cin>>date.thang;
	      	cout<<"\tNhap nam sinh : ";
	      	cin>>date.nam;
  		}
 
	    void inputInfo()
		{
	    	cout<<"\n\tNhap ho ten: ";
	    	cin.getline(ht,30);
	    	inputDate();
	    	cin.ignore();
	    	cout<<"\tNhap CMND: ";
	    	cin.getline(cmt,10);
	    	cout<<"\tNhap ho khau: ";
	    	cin.getline(hk,30);
    	}
 
	    void displayInfo()
		{
    		cout<<left<<setw(32)<<ht;
    		cout<<left<<setw(2)<<date.ngay
				<<"/"<<setw(2)<<date.thang
				<<"/"<<setw(6)<<date.nam;
			cout<<left<<setw(12)<<cmt;
			cout<<left<<setw(32)<<hk;
    	}
	    int getNs(){
        	return date.nam;
         }
 
	    char* getHk(){
    		return hk;
    	}
 
	    friend istream & operator >>(istream& is , KH &i)
	      {	      
		  	i.inputInfo();	  		
		  	return is;
	      }
 
        friend ostream & operator <<(ostream& os , KH &i)
          {       	
  			i.displayInfo();  				
         	return os;
          }
 
		friend bool operator >( KH &a , KH &b )
		{
			return( a.getNs() > b.getNs());
		}
 
		bool timKiem(){	
		if(strcmpi(hk,"HA NOI")==0)
			{
				return true;
			}
			return false;
		}	
 
};
 
void title(){
	cout<<left<<setw(5)<<"STT"
		<<setw(32)<<"HO TEN"
		<<setw(12)<<"NGAY SINH"
		<<setw(12)<<"SO CMND"
		<<setw(32)<<"HO KHAU"<<endl;
}
 
int tinhtuoi(int ns)
{
	return 2021-ns;
}
 
main(){
	int n;
 
	cout<<"\nNhap n: ";
	cin>>n;
	KH *khachHang = new KH();
 
	cin.ignore();
	cout<<"\nNhap du lieu khach hang: ";
	for(int i = 0; i < n; i++)
	{
		cout<<"\nKhach hang thu "<<i+1<<": ";
		cin>>khachHang[i];
	}
 
 
	cout<<"\nXuat du lieu khach hang: "<<endl;
	title();
	for(int i = 0 ;i < n; i++)
	{	cout<<left<<setw(5)<<stt++;
		cout<<khachHang[i]<<endl;
	}
 
	int count = 0;
 	stt = 0;
	cout<<"\n\nDanh sach khach hang co ho khau Ha Noi \n";
	title();
 
	for(int i = 0 ;i < n; i++)
	{
		if(khachHang[i].timKiem())
		{
			cout<<left<<setw(5)<<stt++<<khachHang[i]<<endl;
			count++;
		}	
	}
	if(count == 0){
		cout<<"\n\t [ Khong tim thay khach hang nao co ho khau HN ]"<<endl;
	}
 
	cout<<"\n\n ----------Sap xep tang dan theo tuoi---------- \n";
	title();
	stt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j=i+1; j<n; j++)
		if(khachHang[i] > khachHang[j])
		{
			KH 	temp = khachHang[i];
				khachHang[i] = khachHang[j];
				khachHang[j] = temp;
		}		
	}
	int tuoi = 0;
	for(int i = n-1; i >= 0; i--){	
		cout<<left<<setw(5)<<stt++<<khachHang[i]<<"Tuoi: "<<tinhtuoi(khachHang[i].getNs())<<endl;
	}
}