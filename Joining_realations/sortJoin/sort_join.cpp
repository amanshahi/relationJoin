#include <bits/stdc++.h>
#include "readFiles1.h"
#include "readFiles2.h"


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

II a[100002];
vector<vector<string > > toHash1, toHash2;
vector<vector<string> > toFlush;


#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define trace(...)
#endif
	
II findInSet(set<II> setname, II element){
	if(setname.find(element) != setname.end()) return 1;
	return 0;
}

II findInVector(vector<II> vectorname, II element){
	if(find(vectorname.begin(), vectorname.end(), element) != vectorname.end()) return 1;
	return 0;
}

II findInMap(map<II,II> mapname, II element){
	if(mapname.find(element) != mapname.end()) return 1;
	return 0;
}

LL XpowerY(LL x, LL y, LL m){
	LL ans=1;
	x=x%m;
	while(y>0){
		if(y%2==1)
			ans=(ans*x)%m;
		x=((x%m)*(x%m))%m;
		y=y>>1;
	}
	return ans%m;
}

II main(II argc, char * argv[]){
	if(argc == 4){
		ofstream myfile;
		myfile.open ("sort_join.txt");
		string read1 = argv[1], read2 = argv[2];
		II sz = 2;
		II osz=(262144/sz),isz=(atoi(argv[3])-1)*(262144/sz);
		II flag1=0, flag2=0;
		while(1){
			flag2=0;
			toHash1 = readFiles1(isz, read1, flag1);
			if(toHash1.size() == 0) break;
			while(1){
				toHash2 = readFiles2(isz, read2, flag2);
				if(toHash2.size() == 0) break;
				for(II i=0;i<toHash1.size();i++){
					for(II j=0;j<toHash2.size();j++){
						if(toHash1[i][1] == toHash2[j][0]) {
							vector<string> tmp;
							tmp.PB(toHash1[i][0]);tmp.PB(toHash1[i][1]);tmp.PB(toHash2[j][1]);
							toFlush.PB(tmp);
							if(toFlush.size() == osz){
								for(II k=0;k<toFlush.size();k++) myfile << toFlush[k][0] << " " << toFlush[k][1] << " " << toFlush[k][2] << endl;
								toFlush.clear();
							}
						}
					}
				}
				flag2++;
			}
			flag1++;
		}
		for(II k=0;k<toFlush.size();k++) myfile << toFlush[k][0] << " " << toFlush[k][1] << " " << toFlush[k][2] << endl;
		toFlush.clear();

	}	
	else{
		cout << "Some error occurred!\n";
	}
	return 0;
}	