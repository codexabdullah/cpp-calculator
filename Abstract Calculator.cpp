#include<iostream>
using namespace std;

// Base class for all operations
class Operation{
	public:
		virtual int compute(int a, int b) = 0;
};

// Addition class
class Add : public Operation{
	public:
		int compute(int a, int b) override{
			return a + b;
		}
};

// Subtraction class
class Subtract : public Operation{
	public:
		int compute(int a, int b) override{
			return a - b;
		}
};

// Multiplication class
class Multiply : public Operation{
	public:
		int compute(int a, int b) override{
			return a * b;
		}
};

// Division class
class Divide : public Operation{
	public:
		int compute(int a, int b) override{
			if(b == 0){
				cout << "Cannot divide by 0 !" << endl;
				return 0;
			}
			return a / b;
		}
};

int main() {
	char again = 'y';

	while(again == 'y' || again == 'Y'){
		Operation* o = nullptr;
		int choice, a, b;
		
		// Taking input
		cout << "Enter Two numbers : ";
		cin >> a >> b;
		cout << endl;
		
		// Menu
		cout << "Choose the Operation to perform : " << endl;
		cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
		cout << "Enter choice : ";
		cin >> choice;
		
		// Object creation
		switch (choice){
			case 1: o = new Add(); break;
			case 2: o = new Subtract(); break;
			case 3: o = new Multiply(); break;
			case 4: o = new Divide(); break;
			default:
				cout << "Invalid Choice !" << endl;
				continue;
		}
		
		// Compute result
		int result = o->compute(a, b);
		cout << "Result : " << result << endl;
		
		delete o;
		
		// Ask user to continue
		cout << "\nDo you want to perform another calculation? (y/n): ";
		cin >> again;
		cout << endl;
	}
	
	cout << "Program ended." << endl;
	return 0;
}
