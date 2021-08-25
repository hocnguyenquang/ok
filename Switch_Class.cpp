#include<iostream.h>
#include<conio.h>
using namespace std;

class Student
{
	private:
	
		char Id[15];
		char name[30];
		int age;
		char address[40];
		float gpa;
		
	public:
		//Ham khoi tao khong tham so
		Student(){}
		
		//Ham khoi tao co tham so
		Student(char * Id, char * name, int age, char * address, float gpa)
		{
			strcpy(this -> Id, Id);
			strcpy(this -> name, name);
					this -> age = age;
			strcpy(this -> address, address);
					this -> gpa = gpa;
		}
		//Ham huy khong tham so
		~Student(){}
		
		void setID(char *Id)
		{
			strcpy(this -> Id, Id); 
		}
		
		char getID()
		{
			return char(Id);
		}
		
		void setName(char *name)
		{
			strcpy(this -> name, name);
		}
		string getName()
		{
			return string(name);
		}
		
		int setAge(int age)
		{
			this -> age = age; 
		}
		int getAge()
		{
			return age;
		}
		
		void setAddress(char *address)
		{
			strcpy(this ->address, address);
		}
		char getAddress()
		{
			return char(address);
		}
		
		float setGpa(float gpa)
		{
			this -> gpa = gpa;
		}
		float getGpa()
		{
			return gpa;
		}
		
		//Ham xuat thong tin
		void getInfor()
		{
			cout<<"\nId: "<<Id<<endl;
			cout<<"\nTen: "<<name<<endl;
			cout<<"\nDia chi: "<<address<<endl;
			cout<<"\nTuoi: "<<age<<endl;
			cout<<"\nGpa: "<<gpa<<endl;
			
		}
};

class StudentManagement
{
	
	public:
	//Ham Khoi tao khong tham so
	StudentManagement(){}
	
	//Ham them sinh vien
	void AddStudent(Student a[],int &n)
	{
			char Id[15],name[30],address[40];
			int age;
			float gpa;
			cout<<"\nNhap thong tin sinh vien thu "<<n+1<<": ";
			cin.ignore();
			cout<<"\nNhap id: ";
			cin.getline(Id,15);
			a[n].setID(Id);
			cout<<"\nNhap ten: ";
			cin.getline(name,30);
			a[n].setName(name);
			cout<<"\nNhap dia chi: ";
			cin.getline(address,40);
			a[n].setAddress(address);
			cout<<"\nNhap tuoi: ";
			cin>>age;
			a[n].setAge(age);
			cout<<"\nNhap gpa: ";
			cin>>gpa;
			a[n].setGpa(gpa);
			
	}
	
	//Ham xoa sinh vien
	void DeleteStudent(Student a[],int Id,int n)
	{
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i].getID() == Id)
			count = 1;
			for(int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			cout<<"\nXoa sinh vien co id la: "<<Id;
			
			if(count == 0)
			{
				cout<<"\nId khong ton tai";
				break;
			}
		}
	}
	
	//Ham sua thong tin sinh vien
	void EditStudent(Student a[],int Id, int n)
	{
		int count = 0;
		char name[30];
		int age;
		char address[40];
		float gpa;
		for(int i = 0; i < n; i++)
		{
			if(a[i].getID() == Id)
			count = 1;
			{
			cin.ignore();
			cout<<"\nEdit ten: ";
			cin.getline(name,30);
			a[i].setName(name);
			cout<<"\nEdit dia chi: ";
			cin.getline(address,40);
			a[i].setAddress(address);
			cout<<"\nEdit tuoi: ";
			cin>>age;
			a[i].setAge(age);
			cout<<"\nEdit gpa: ";
			cin>>gpa;
			a[i].setGpa(gpa);
			break;
			}
		}
		if(count == 0)
				{
					cout<<"\nId khong ton tai";	
				}
	}
	
	//Ham sap xep GPA sinh vien
	void sortGPA(Student a[],int n)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(a[i].getGpa() > a[j].getGpa())
				{
					Student temp = a[i];
							a[i] = a[j];
							a[j] = temp;
				}
			}
		}
			
	}
	
	//Ham sap xep ten sinh vien
	void sortName(Student a[],int n)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(a[i].getName().compare(a[j].getName()) > 0 )
				{
					Student temp = a[i];
							a[i] = a[j];
							a[j] = temp;
				}
			}
		}
	}
	
	//Ham hien thi thong tin sinh vien
	void ShowInfor(Student a[],int n)
	{
		for(int i = 0; i < n; i++)
		{
			cout<<"\nThong tin sinh vien thu "<<i+1<<": ";
			a[i].getInfor();
		}	
	}
	
	//Ham lua chon trong menu
	void Chosse()
	{
		cout << "          CHUONG TRINH QUAN LY SINH VIEN \n";
        cout << "*************************MENU**************************\n"<<endl;
        cout << "**  1. Add student.                                  **\n"<<endl;
        cout << "**  2. Delete student by ID.                         **\n"<<endl;
        cout << "**  3. Edit student by ID.                           **\n"<<endl;
        cout << "**  4. Sort student by gpa.                          **\n"<<endl;
        cout << "**  5. Sort student by name.                         **\n"<<endl;
        cout << "**  6. Show student.                                 **\n"<<endl;
        cout << "**  0. Exit                                          **\n"<<endl;
        cout << "*******************************************************\n"<<endl;
        cout << ">>              Nhap lua chon cua ban          	  <<\n"<<endl;
	}
};

//Ham clear screen
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}

main()
{
	int n = 0;
	StudentManagement *sv = new StudentManagement();
	Student student[1000];
	int menu;
	do{
		sv -> Chosse();
		cin>>menu;
	switch(menu)
		{
		case 1:
			sv -> AddStudent(student, n);
			cout<<"\nThem thanh cong!";
			n++;
			pressAnyKey();
			break;
			
		case 2:
			cout<<"\nDelete sinh vien co id la: ";
			int deleteId;
			cin>>deleteId;
			sv->DeleteStudent(student,deleteId,n);
			n--;	
			cout<<"\nXoa sinh vien thanh cong!";
			pressAnyKey();
			break;
			
		case 3:
			cout<<"\nBan muon sua sinh vien co id la: ";
			int editId;
			cin>>editId;
			sv->EditStudent(student, editId, n);
			cout<<"\nSua sinh vien thanh cong!";
			pressAnyKey();
			break;
			
		case 4:
			sv->sortGPA(student, n);
			cout<<"\nGPA sau khi sap xep: \n";
			sv->ShowInfor(student, n);
			pressAnyKey();
			break;
		
		case 5:
			sv->sortName(student, n);
			cout<<"\nName sau khi sap xep: \n";
			sv->ShowInfor(student, n);
			pressAnyKey();
			break;
		
		case 6: 
			sv->ShowInfor(student, n);
			pressAnyKey();
			break;
			
		case 0:
			cout<<"\nExit";
		default:
			cout<<"\nCam on ban da su dung menu"<<endl;
			cout<<"\nHay chon menu moi"<<endl;
		}
	}while(menu != 0);
	cout<<endl;
}