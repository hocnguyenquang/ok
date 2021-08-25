#include<iostream.h>
using namespace std;
class Dathuc3{
	
	private:
	   int a,b,c,d;
	   
	public:
	   Dathuc3(){};
	   ~Dathuc3(){};
	   void set()
	   	{
   		cout<<"\nHe so bac 3: ";
   		cin>>a;
   		cout<<"\nHe so bac 2: ";
   		cin>>b;
	    cout<<"\nHe so bac 1: ";
   		cin>>c;  	
		cout<<"\nHe so bac 0: ";
   		cin>>d;  
    	} 
		  
   	  void get()
 		{
  	   	cout <<a<<"x3 + " <<b<<"x2 + "<<c<<"x + "<<d<<" = 0"<<endl;
  	   	}
  	   	int getA()
  	   	{
	   	  	return a;
	  	}
	  	int getB()
	  	{
	  		return b;
	  	}
	  	int getC()
	  	{
	  		return c;
	  	}
	  	int getD()
	  	{
	  		return d;
	  	}
};

int main()
	{
	Dathuc3 dathuc3[2];
	for(int i=1 ; i<=2 ; i++)
	{
		cout<<"\nNhap vao so bac cua da thuc thu "<<i<<" la: ";
		dathuc3[i].set();
	}
	
	for(int i=1 ; i<=2 ; i++)
	{
		cout<<"\nDa thuc thu "<<i<<" la: ";
		dathuc3[i].get();
	}
	cout<<endl;
	
	cout<<"\nTong 2 da thuc: \n\t";
	dathuc3[1].get();
	cout<<"Va da thuc: \n\t";
	dathuc3[2].get();
	cout<<"La: \n\t";
	cout<<dathuc3[1].getA()+dathuc3[2].getA()
		<<"x3 + "<<dathuc3[1].getB()+dathuc3[2].getB()
		<<"x2 + "<<dathuc3[1].getC()+dathuc3[2].getC()
		<<"x + "<<dathuc3[1].getD()+dathuc3[2].getD()
		<<" = 0"<<endl;
		cout<<endl;
}