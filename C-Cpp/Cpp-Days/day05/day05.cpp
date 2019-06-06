#include <iostream>
#include <string>
using namespace std;

int StrToInt(string str) {
	int ret = 0;
	for (char e : str) {
		if ( !(e >= '0' && e <= '9') && e != '+' && e != '-') {
			return 0;
		} else {
			ret *= 10;
			ret += e;
		}
	}
	return ret;
}

int main()
{
	string s;
	cin >> s;
	cout << StrToInt(s) << endl;

	return 0;}
