#include<iostream>
using namespace std;

class Operation{
	public:
		virtual int compute(int a, int b) = 0;
};

class Add : public Operation{
	public:
		int compute(int a, int b) override{
			return a+b;
		}
};

class Subtract : public Operation{
	public:
		int compute(int a, int b) override{
			return a-b;
		}
};

class Multiply : public Operation{
	public:
		int compute(int a, int b) override{
			return a*b;
		}
};

class Divide : public Operation{
	public:
		int compute(int a, int b) override{
			if(b==0){
				cout<<"Cannot divide by 0 !";
			}
			return a/b;
		}
};

int main() {
	Operation* o = nullptr;
	int choice,a ,b;
	
	cout<<"Enter Two numbers : ";
	cin>>a>>b;
	cout<<endl;
	
	cout<<"Chose the Operation to perform : "<<endl;
	cout<<"1. Add\n 2. Subtract\n 3. Multiply\n 4. Divide\n";
	cout<<"Enter choice : ";
	cin>>choice;
	
	switch (choice){
		case 1: o = new Add(); break;
		case 2: o = new Subtract(); break;
		case 3: o = new Multiply(); break;
		case 4: o = new Divide(); break;
		default: cout<<"Invalid Choice !";
		
		return 0;
	}
	
	int result = o->compute(a, b);
	cout<<"Result : "<<result<<endl;
	delete o;
	
	return 0;
}