#include <iostream>
#include "integer.h"

using namespace std;

int main() {
	Integer i1, i2 = 10, i3 = 3, i4 = 10, i5, i6 = 10;
	bool result;

	cout << "i1: " << i1 << endl;
	cout << "i2: " << i2 << endl;
	cout << "i3: " << i3 << endl;
	cout << "i4: " << i4 << endl;
	cout << "i5: " << i5 << endl;
	cout << "i6: " << i6 << endl;
	
	
	cout << "i1 + i2: " << i1 + i2 << endl;
	
	i1 += i2;
	cout << "After i1 += i2 - i1: " << i1 << endl;

	//DEMO OF EXTRACTION OPERATOR
	cin >> i5;
	cout << "Value of i5 after input is " << i5 << endl << endl;

	//MULTIPLICATION
	i2 * i3;
	cout << "After i2 * i3: " << i2 * i3 << endl;
	cout << "After i2 *= i3: " << i2.operator*=(i3) << endl; 
	cout << "After operator *(i2, i3): " << operator *(i2, i3) << endl << endl;

	//DIVISION
	cout << "After i2 / i3: " << i2 / i3 << endl; 
	cout << "After i2 /= i3: " << i2.operator/=(i3) << endl;
	cout << "After operator /(i2, i3): " << operator /(i2, i3) << endl << endl;

	//SUBTRACTION
	cout << "After i2 - i3: " << i2 - i3 << endl; 
	cout << "After 12-=i3: " << i2.operator-=(i3) << endl;
	cout << "After operator-(i2, i3) " << operator -(i2, i3) << endl << endl;
	
	//RELATIONAL OPERATORS
	result = i2 == i3;
	cout << "After i2 == i3: " << result  << endl;
	result = operator ==(i2, i3); 
	cout << "After operator==(i2, i3): " << result << endl; 

	result = i6 == i4;
	cout << "After i6 == i4: " << result << endl << endl;

	result = i2 < i3;
	cout << "After i2 < i3: " << result << endl;
	result = operator <(i2, i3);
	cout << "After operator <(i2, i3): " << result << endl << endl;
	 
	
	result = i2 > i3;
	cout << "After i2 >i3: " << result << endl; 
	result = operator >(i2, i3);
	cout << "After operator >(i2, i3): " << result << endl << endl; 

	//DECREMENT
	operator --(i4);
	cout << "i4 after operator(i4) is " << i4 << endl;

	--i4;
	cout << "i4 after --i4 is " << i4 << endl;


	i4--;
	cout << "14 after i4-- is " << i4 << endl << endl;	

	//INCREMENT
	operator ++(i3);
	cout << "i3 after operator++(i3) is " << i3 << endl;

	++i3;
	cout << "i3 after ++i3 is " << i3 << endl;

	i3++;
	cout << "i3 after i3++ is " << i3 << endl << endl;

	//NEGATION
	cout << "After operator -(i3): " << operator -(i3) << endl;
	cout << "After -i5: " << -i5 << endl << endl;
		

	//Operators in functional form

	cout << "i1 + i2: " << operator +(i1,i2) << endl;

	i1.operator +=(i2);
	cout << "After i1.operator +=(i2) - i1: " << i1 << endl << endl;
	return 0;
}
