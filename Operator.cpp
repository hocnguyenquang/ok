lude <iomanip.h>
using namespace std;
class NGUOI
{
	private:
		char ht[30];
		char scm[10];
		char gt[3];
	public:
	NGUOI(char * ht "", char * scm = "", char * gt = "")
	{
		strcpy(this -> ht, ht);
		strcpy(this -> scm, scm);
		strcpy(this -> gt, gt);
	}
	void nhap()
	{
		cin.ignore();
		cout<<" nhap vao ho va ten: "; cin.getline(ht,30);
		cout<<" nhap vao so chung minh thu: ";cin.getline(scm,10);
		cout<<" nhap vao gioi tinh: "; cin.getline(gt,3);
	}
	void xuat()
	{
		cout <<"\t\t Ho va ten : "<<ht<<endl;
		cout <<"\t\t So chung minh thu: "<<scm<<endl;
		cout <<"\t\t Gioi tinh: "<<gt<<endl;
 
	}
 
};
class NV : public NGUOI
{
	private:
	char tdcm[10];
	float sn;
 
	public:
	NV(char * ht =" ", char * scm =" ", char * gt =" ",
		char * tdcm = " ", float sn = 0.0)
		:NGUOI(ht,scm)
		{
			strcpy(this ->tdcm, tdcm);
			this ->sn, sn;
		}
	//cin >> i;
	// + - * / < > != ==
	friend istream& operator >> (istream& is, NV &a)
	{
		a.nhap();
		cout <<" nhap vao trinh do chuyen mon: ";cin.getline(a.tdcm,10);
		cout <<" nhap vao so nam nop bh: ";cin>>a.sn;
		return is;
	}
	long chedo()
	{
		return 50*sn;
	}
	friend bool operator >= (NV& n, NV& m)
	{
		return(n.sn >= m.sn);
	}
	friend bool operator >(NV& n, NV& m)
	{
		return(n.chedo() > m.chedo());
	}
	//cout <<
	friend ostream & operator << (ostream& os, NV& a)
	{
		a.xuat();
		os<<"\t\t Trinh do chuye mon: "<<a.tdcm<<endl;
		os<<"\t\t So nam nop bao hiem: "<<a.sn<<endl;
		return os;
	}
};
 
int main()
{
	NGUOI * x; 
	int n; cout <<" nhap vao so nguoi: "; cin>>n;
	x = new NGUOI[n];
 
	for(int i=0; i<n; i++)
	{
		cout <<" nhap vao thong tin nguoi thu "<<i+1<<endl;
		x[i].nhap();
	}
 
	cout <<"\n======== DANH SACH NGUOI========="<<endl;
	for(int i=0; i<n; i++)
	{
		x[i].xuat();
		cout <<endl;
	}
 
	NV * y; 
	 cout <<" nhap vao so nhan vien: "; cin>>n;
	y = new NV[n];
 
	for(int i=0; i<n; i++)
	{
		cout <<" nhap vao thong tin nguoi thu "<<i+1<<endl;
		cin <> y[i];
	}
 
	cout <<"\n======== DANH SACH NGUOI========="<<endl;
	for(int i=0; i<n; i++)
	{
		cout <<y[i];
		cout <<endl;
	}
 
	cout <<"\n--------------------------------\n";
	cout <<"\n SAP XEP DANH SACH GIAO VIEN THEO CHE DO \n";
 
		for(int i=0; i<n-1; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(y[i] > y[j])
				{
					NV temp = y [i];
					y[i]= y[j];
					y[j]= temp;
				}
			}
			//cout <<y[i]<<endl;
		}
		for(int i =0 ; i<n; i++)
		{
			cout <<y[i]<<endl;
		}
 
 
	return 0;
}