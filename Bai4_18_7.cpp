#include<iostream.h>
using namespace std;
class VecTor3{
	private:
	
		int a,b,c;
	public:
	
	    VecTor3(int a =0, int b = 0, int c = 0)
		{
	    	this -> a = a;
	    	this -> b = b;
	    	this -> c = c;
		};
		
	    ~VecTor3(){};
	    
	    void set()
		{
	    	cout<<"\nNhap vao toa do x : ";
	    	cin>>a;
	    	cout<<"\nNhap vao toa do y : ";
	    	cin>>b;
	    	cout<<"\nNhap vao toa do z : ";
	    	cin>>c;
	    }
	    
	    void get()
		{
	    	cout<<" ( "<<a<<", "<<b<<", "<<c<<" ) ";
	    }
	    /* //cach 1 -> lam ham rieng
		double getA()
	   	{
	    	return a;
	    }
	    double getB()
	   	{
	    	return b;
	    }
    	double getC()
		{
	    	return c;
	    }*/
	    
	    //cach 2 -> lam trong ham main
	    double tinhTonga(VecTor3 a, VecTor3 b)
	    {
    		return (a.a + b.a);
    	}
	    double tinhTongb(VecTor3 a, VecTor3 b)
	    {
    		return (a.b + b.b);
    	}
    	double tinhTongc(VecTor3 a, VecTor3 b)
	    {
    		return (a.c + b.c);
    	}
};
int main()
	{
		
	VecTor3 vector3[2];
	for(int i=1;i<=2;i++)
	 {
	 	cout<< "\nNhap vecto thu "<< i<<" : ";
	 	vector3[i].set();
	 }
    for(int i=1;i<=2;i++)
	 {
	 	cout<< "\nVecto thu "<< i<<" : ";
	 	vector3[i].get();
	 }
	 cout<<endl;
	 
	     //cach 1 lam ham rieng
	 	int i=1;
 		cout<<"\nTong 2 vector: "<<"( "<<vector3[i].tinhTonga(vector3[i], vector3[i+1])
		    <<", "<<vector3[i].tinhTongb(vector3[i], vector3[i+1])
			<<", "<<vector3[i].tinhTongc(vector3[i], vector3[i+1])
			<<" )"<<endl;
	
     /*  //cach 2 -> lam trong ham main
cout <<"\nTong 2 vector ";
     vector3[1].get();
     cout << "\nVa vector:    ";
     vector3[2].get();
	 cout <<"\nLa:           ";
     cout 	<<" ( "<<vector3[1].getA() + vector3[2].getA()
	 		<<" , "<<vector3[1].getB() + vector3[2].getB()
	 		<<" , "<<vector3[1].getC() + vector3[2].getC()
	 		<<" ) "<<endl;
	 cout<<endl;*/
}