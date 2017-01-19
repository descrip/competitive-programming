#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

void quit(){
	cout << -1 << '\n';
	exit(0);
}

int main(){
	ostringstream oss;
	string s;
	cin >> s;
	int v = 0, last = 0, lastv = 0;

	if (s[0] == '#' || s[0] == ')' || s[s.length() - 1] == '(')
		quit();
	
	for (last = s.length() - 1; last >= 0; last--)
		if (s[last] == '#')
			break;
		else if (s[last] == '(')
			lastv++;
		else if (s[last] == ')')
			lastv--;
	
	if (lastv > 0)
		quit();
	
	for (int i = 0; i < s.length(); i++){
		if (s[i] == ')')
			v--;
		else if (s[i] == '(')
			v++;
		else if (i == last){
			//cout << v << ' ' << last << ' ' << lastv << endl;
			if (v + lastv <= 0)
				quit();
			else
				cout << oss.str() << v + lastv << '\n'; 
			return 0;
		}
		else if (s[i] == '#'){
			oss << "1\n";
			v--;
		}

		if (v < 0)
			quit();
	}
}
