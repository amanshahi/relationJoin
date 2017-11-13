#include <bits/stdc++.h>
#include "tokenize.h"
using namespace std;
map<string,int> readVal(){
	string ln;
	map<string,int> RT;
	vector<string> col;
	ifstream file("metadata.txt");
	if(file.is_open()){
		while(getline(file,ln)){
			col=tknze(ln,",",0);
			// cout << col[0] << " " << col[1].c_str() << endl;
			RT[col[0]]=atoi(col[1].c_str());
		}
		return RT;
	} 
	else{
		printf("Error in metadata\n");
		exit(0);
	}
}
