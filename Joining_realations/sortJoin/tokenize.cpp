#include <bits/stdc++.h>
using namespace std;
vector<string> tknze(string a,string delim, int flag){
	string s = a;
	string delimiter = delim;
	vector<string> parsed;
	size_t pos = 0;
	string empt;
	while ((pos = s.find(delimiter)) != -1) {
		empt = s.substr(0, pos);
		parsed.push_back(empt);
		s.erase(0, pos + delimiter.length());
	}
	if(flag == 1) {s = s.substr(0,s.size()-1);}
	parsed.push_back(s);
	return parsed;
}