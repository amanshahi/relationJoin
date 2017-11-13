#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define PB push_back
#define INS insert
#define MP make_pair
#define LL long long int
#define II int
#define SS string
#define sortArray(n) sort(begin(n), end(n))
#define sortVector(n) sort(n.begin(), n.end()) 

LL offset2=0;


vector<vector<string> > readFiles2(II isz, string fileName, II flag){
	if(flag == 0) offset2 = 0;
	vector<vector<string> > ret;
	vector<string> temp;
	string line;
	ifstream myfile (fileName);
	myfile.seekg(offset2);
	if (myfile.is_open()){
		while (getline (myfile,line)){
			offset2 += line.length()+1;
			char sub[100];
			std::strcpy(sub, line.c_str());
			char *br = strtok(sub," ");
			temp.clear();
			while(br != NULL){
				string str(br);
				temp.PB(br);br = strtok(NULL," ");
			}
			ret.PB(temp);
			if(ret.size() ==  isz) {
				myfile.close();
				return ret;
			}
		}
		myfile.close();
	}
	return ret;
}	
