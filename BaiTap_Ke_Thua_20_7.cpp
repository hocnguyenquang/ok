#include<iostream.h>
#include<string.h>
using namespace std;

class People
{
	private:
		char name[30];
		int age;
		char address[40];
		
	public:
		
		void set();
		void get()
		{
			cout<<"\nName: "<<name<<endl;
			cout<<"\nAddress: "<<address<<endl;
			cout<<"\nAge: "<<age<<endl;
		}
		
		People(){}
		~People(){}

};

void People::set()
{
	        cin.ignore();
			cout<<"\nInput name: ";
			cin.getline(name,30);
			cout<<"\nInput address: ";
			cin.getline(address,40);
			do{
			cout<<"\nInput age: ";
			cin>>age;
			}while(age <= 0);
}

class Students : public People
{
	private:
		char ID[30];
		float math,physical,chemistry;
	
	public:
	
	void set();
	void get();
	
	
	float GPA()
	{
		float gpa;
		gpa = (float)(math+physical+chemistry)/3;
		return gpa;
	}
};

void Students::set()
{
	People::set();
		cin.ignore();
		cout<<"\nInput id: ";	
		cin.getline(ID,30);
		do{
		cout<<"\nInput math: ";
		cin>>math;
		}while(math < 0 || math > 10);
		do{
		cout<<"\nInput physical: ";
		cin>>physical;
		}while(physical < 0 || physical > 10);
		do{
		cout<<"\nInput chemistry: ";
		cin>>chemistry;
		}while(chemistry < 0 || chemistry > 10);
}

void Students::get()
{
	People::get();
		cout<<"\nId: "<<ID<<endl;
		cout<<"\nMath: "<<math<<endl;
		cout<<"\nPhysical: "<<physical<<endl;
		cout<<"\nChemistry: "<<chemistry<<endl; 
}
	
main()
{
	int student;
	cout<<"\nInput amount students: ";
	cin>>student;
	
	Students *sv = new Students[student];
	for(int i = 0; i < student; i++)
	{
		cout<<"\nInput student oder"<<i+1<<": ";
		sv[i].set();
	}
	cout<<endl;
	
	for(int i = 0; i < student; i++)
	{
		cout<<"\nOutput student oder: "<<i+1<<": ";
		sv[i].get();
	}
	cout<<endl;
	
	
	for(int i = 0; i < student; i++)
	{
		cout<<"\nGPA student "<<i+1<<": ";
		cout<<sv[i].GPA();
	}
	cout<<endl;
}