#include <iostream>
using namespace std;
#include <string>
 
int main()
{
	string s;
	getline(cin, s);
	char c[2] = { s.at(0) };
	int num[2] = { 1 };
	for (int i = 1; i < s.length(); i++) {
		if (s.at(i) == c[0])
			num[0]++;
		else {
			if (num[0] > num[1] || (num[0] == num[1] && c[0] < c[1])) {
				c[1] = c[0];
				num[1] = num[0];
			}
			c[0] = s.at(i);
			num[0] = 1;
			
		}
	}
	if (num[0] > num[1] || (num[0] == num[1] && c[0] < c[1])) {
		c[1] = c[0];
		num[1] = num[0];
	}
	for (int i = 0; i < num[1]; i++)
		cout << c[1];
 
	cout << endl;
    return 0;
}