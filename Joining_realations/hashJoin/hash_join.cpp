#include <bits/stdc++.h>
#include "readFiles.h"

using namespace std;

#define MOD 1000000007
#define MOD2 1000003
#define PB push_back
#define INS insert
#define MP make_pair
#define LL long long int
#define II int
#define SS string
#define sortArray(n) sort(begin(n), end(n))
#define sortVector(n) sort(n.begin(), n.end()) 

II a[100002];
vector<vector<pair<string,string> > > v_rel1, v_rel2;
vector< pair<string, string> > temp;
vector<vector<string > > toHash;
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

LL calculate_hash(string s){
	LL ans=0,val=1;
	reverse(s.begin(), s.end());
	for(II i=0;i<s.size();i++){
		ans += ((s[i]-'a')*val)%MOD2;
		val = (val*27)%MOD2;
	}
	reverse(s.begin(), s.end());
	return ans;
}

II main(II argc, char * argv[]){
	if(argc == 4){
		ofstream myfile;
        myfile.open ("out.txt");
		for(II i=0;i<2000003;i++) {v_rel2.PB(temp);v_rel1.PB(temp);}
		string rel1 = argv[1], rel2 = argv[2];
		II flag=0, sz=2;
		II osz=(262144/sz),isz=(atoi(argv[3])-1)*(262144/sz);
		while(1){
			toHash = readFiles(isz,rel1,flag);
			trace(toHash.size());
			if(toHash.size() == 0) break;
			for(II i=0;i<toHash.size();i++){
				string s1=toHash[i][0], s2 = toHash[i][1];
				LL hsh = calculate_hash(s2);
				v_rel1[hsh].PB(MP(s1,s2));
			}
			flag++;
		}
		flag=0;
		while(1){
			toHash = readFiles(isz,rel2,flag);
			trace(toHash.size());
			v_rel2.clear();
			for(II i=0;i<2000003;i++) {v_rel2.PB(temp);}
			if(toHash.size() == 0) break;
			for(II i=0;i<toHash.size();i++){
				string s1=toHash[i][1], s2 = toHash[i][0];
				LL hsh = calculate_hash(s2);
				v_rel2[hsh].PB(MP(s2,s1));
			}
			for(II i=0;i<v_rel2.size();i++){
				for(II j=0;j<v_rel2[i].size();j++){
					for(II k=0;k<v_rel1[i].size();k++){
						if(v_rel2[i][j].first == v_rel1[i][k].second){
							vector<string> te;
							te.PB(v_rel1[i][k].first);
							te.PB(v_rel1[i][k].second);
							te.PB(v_rel2[i][j].second);
							toFlush.PB(te);
							if(toFlush.size() == osz){
								for(II j=0;j<toFlush.size();j++) myfile << toFlush[j][0] << " " << toFlush[j][1] << " " << toFlush[j][2] << endl;
			                    toFlush.clear();
		            		}
	            		}
					}
				}
			}
			flag++;
		}
		// for(II i=0;i<v_rel1.size();i++){
		// 	for(II j=0;j<v_rel1[i].size();j++){
		// 		for(II k=0;k<v_rel2[i].size();k++){
		// 			if(v_rel1[i][j].second == v_rel2[i][k].first){
		// 				vector<string> te;
		// 				te.PB(v_rel1[i][j].first);
		// 				te.PB(v_rel1[i][j].second);
		// 				te.PB(v_rel2[i][k].second);
		// 				toFlush.PB(te);
		// 				if(toFlush.size() == osz){
		// 					for(II j=0;j<toFlush.size();j++) myfile << toFlush[j][0] << " " << toFlush[j][1] << " " << toFlush[j][2] << endl;
		//                     toFlush.clear();
	 //            		}
  //           		}
		// 		}
		// 	}
		// }
		for(II j=0;j<toFlush.size();j++) myfile << toFlush[j][0] << " " << toFlush[j][1] << " " << toFlush[j][2] << endl;
		toFlush.clear();
	} else{
		cout << "Some error occurred!\n";
	}
	return 0;
}	