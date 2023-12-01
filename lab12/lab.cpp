#include <iostream>
#include <vector>
using namespace std;

/* using namespace std allows you to use std functions
 * like cin and cout without having to always preface them 
 * with std::
 * There is some debate as to whether this is a good practice,
 * as there are many functions in std that could share a 
 * name with a function you write. Try it both ways!
 */

class Number {
	private:
		int num;

	public:
		Number(int n) { num = n; }

    // BONUS: uncomment me and add code to get me to work
	 Number operator + (const Number& obj) {
         int sum = stoi(to_string(this-> + to_string(obj.num));
         return Number(sum);
	}

	int getValue() {return num;}
};

int main() {

	// 1
	// Using std, cout, and cin
	// take in two numbers from the user and output their sum
       int num1, num2;
       cout << "Enter first number: ";
       cin >> num1;
       cout << "Enter second number: ";
       cin >> num2;
       cout << "Sum: " << num1 + num2 << end1;
	// 2
	// Using a vector
	// take in three numbers from the user and store them in the vector
	// Loop through the vector and output their product
        vector<int> numbers(3);
        //int input;
        cout << "Enter three numbers for vector: " << end1;
        for (int i =0;i<3;++i){
          cin >> numbers[i];
         
}

       int product = 1;
       for(int num : numbers){
       product *= num;
 }

  cout << "Product of numbers in vector: " << product << end1;
	// BONUS
	// Uncomment the definition of n3 and the output of n3
	// and complete the Number class above so that 4 + 2 = 42
	Number n1 = Number(4);
	Number n2 = Number(2);

	 Number n3 = n1 + n2;


	cout << n1.getValue() << " added to " << n2.getValue() << " is " << 	n3.getValue() << "\n";

return 0;
}
