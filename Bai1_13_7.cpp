#include<iostream.h>
#include<string.h>
using namespace std;
class KH{
	private:
		char ht[30];
		int ns,ts;
		char cmt[10];
		char hoKhauK[50];
	
	public:
		KH(char *ht =" ",int ns = 0, int ts = 0, char *cmt=" ",char *hoKhauK=" ")
		{
			strcmp(this -> ht,ht);
			this -> ns=ns,ts=ts;
			strcmp(this -> cmt,cmt);
			strcmp(this -> hoKhauK,hoKhauK);
		}
		
		~KH(){};
		
		friend ostream& operator<<(ostream& os, KH& s)
		{
			cout<<"\nHo ten: "<<s.ht;
			cout<<"\nChung minh thu: "<<s.cmt;
			cout<<"\nHo khau k: "<<s.hoKhauK;
			cout<<"\nNs: "<<s.ns;
			cout<<"\nTs: "<<s.ts;
			return cout;
		}
		
		void set()
		{
			cin.ignore();
			cout<<"\nHo ten: ";
			cin.getline(ht,30);
			cout<<"\nChung minh thu: ";
			cin.getline(cmt,10);
			cout<<"\nHo khau k: ";
			cin.getline(hoKhauK,50);
			cout<<"\nNs: ";
			cin>>ns;
			cout<<"\nTs: ";
			cin>>ts;
		}
		
		void get()
		{
			cout<<"\nHo ten: "<<ht;
			cout<<"\nChung minh thu: "<<cmt;
			cout<<"\nHo khau k: "<<hoKhauK;
			cout<<"\nNs: "<<ns;
			cout<<"\nTs: "<<ts;
		}
		string getHt()
		{
			return ht;
		}
		
		int getTs()
		{
			return ts;
		}
};
int main()
{
	int n;
	cout<<"\nNhap so luong khach hang: ";
	cin>>n;
	KH kh[n];
	for(int i=0; i<n; i++)
	{
		kh[i].set();
	}
	cout<<"\nDanh sach sau khi sap xep: \n";
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n;j++)
		{
			if(kh[i].getHt().compare(kh[j].getHt()) > 0)
			{
				KH temp = kh[i];
					kh[i] = kh[j];
					kh[j] = temp;
			}
		}
		kh[i].get();
	}
	cout<<"\nDanh sach khach hang sinh nhat thang 12: \n";
	for(int i=0; i<n; i++)
	{
		if(kh[i].getTs() == 12)
		{
			kh[i].get();
		}
	}
	cout<<endl;
}