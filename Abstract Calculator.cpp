#include<iostream>
using namespace std;

// Base class for all operations
class Operation{
	public:
		// Pure virtual function (abstraction)
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
				return 0; // prevent crash
			}
			return a / b;
		}
};

int main() {
	Operation* o = nullptr; // pointer to base class
	int choice, a, b;
	
	// Taking input
	cout << "Enter Two numbers : ";
	cin >> a >> b;
	cout << endl;
	
	// Menu for user choice
	cout << "Choose the Operation to perform : " << endl;
	cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
	cout << "Enter choice : ";
	cin >> choice;
	
	// Creating object based on user choice (polymorphism)
	switch (choice){
		case 1: o = new Add(); break;
		case 2: o = new Subtract(); break;
		case 3: o = new Multiply(); break;
		case 4: o = new Divide(); break;
		default:
			cout << "Invalid Choice !" << endl;
			return 0;
	}
	
	// Performing operation
	int result = o->compute(a, b);
	cout << "Result : " << result << endl;
	
	// Free memory
	delete o;
	
	return 0;
}
