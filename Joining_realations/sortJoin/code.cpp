#include <bits/stdc++.h>
#include <string>
#include "tokenize.h"
#include "readData.h"
using namespace std;
int ncols;
string order,output;
vector<string > out;
vector<int> OF;
int argument=0;
map<string,int> column_names;
struct compHeap{
	bool operator() (const pair<string,int> &l1, const pair<string,int> &l2){
		string cp1=l1.first,cp2=l2.first;
		if(order=="asc")
			return cp1>cp2;
		else
			return cp1<=cp2;
	}
};
struct compare{
	bool operator() (const string &l1, const string &l2){
		string cp1=l1,cp2=l2;
		if(order=="asc")
			return cp1<cp2;
		else
			return cp1>=cp2;
	}
};  
priority_queue< pair<string,int> ,vector<pair<string,int> >,compHeap> myH;
void merge(int num_rows,int spl, vector<int> kol){
	vector<pair<string,int> > jst;
	vector<ifstream*> IF;
	int i;
	int rl[120];
	for(int i=0;i<kol.size();i++){
		rl[kol[i]]=i;
	}
	for(int i=0;i<spl;i++){
		int temp = i+1;
		ifstream *file = new ifstream(("dump/file" + to_string(temp)).c_str());
        IF.push_back(file);
	}
	string line;
	int linecnt=0;
	for (int j=0;j<spl;j++){
		ifstream *f = IF[j];
		if(getline(*f,line)){
			vector<string> wrds;
			int start=0;
			wrds = tknze(line, " ",0);

			string oj=wrds[0];
			for(int i=1;i<kol.size();i++){
				oj=oj + "," + wrds[i];
			}
			myH.push(make_pair(oj,j+1));
			linecnt++;
		}
	}
	ofstream FF;
	FF.open(output);
	while(!myH.empty()){
		string mini = myH.top().first;
		out.push_back(mini);
		int pg_no = myH.top().second;
		myH.pop();
		if(getline(*IF[pg_no-1],line)){
			string oj="";
			vector<string> wrds;
			int start=0;
			wrds = tknze(line, " ",0);

			oj=wrds[0];
			for(int i=1;i<kol.size();i++){
				oj=oj + "," + wrds[i];
			}
			myH.push(make_pair(oj,pg_no));
			linecnt++;
		}
		if(out.size()==num_rows){
			string outline;
			vector<string> wrds;
			int j;
			for(int i=0;i<out.size();i++){
				int start=0;
				char sub[100];
				wrds = tknze(out[i], ",",0);

				outline=wrds[rl[0]];
				for(int j=1;j<kol.size();j++){
					outline+=" "+wrds[rl[j]];
				}
				FF << outline << endl;
				// cout << outline << endl;
				wrds.clear();
			}
			out.clear();
		}
	}
	if(out.size()>0){
		string outline;
		vector<string> wrds;
		int j;
		for(int i=0;i<out.size();i++){
			int start=0;
			wrds = tknze(out[i], ",",0);
			outline=wrds[rl[0]];
			for(int j=1;j<kol.size();j++){
				outline+=" "+wrds[rl[j]];
			}
			FF << outline << endl;
			// cout << outline << endl;
			wrds.clear();
		}
		out.clear();
	}
	FF.close();
}
void sorT(int NR,string ag,vector<int> cl){
	int rw=0,i,j;
	string ln,Oln;
	vector<string> temp;
	string jst="";
	int act[120];i=0,j=0;
	while(i<cl.size()){
		act[cl[i]]=i;
		i++;
	}
	vector<string> sml;
	ifstream file(ag.c_str());
	if(file.is_open()){
		int spl=0;
		ofstream tempf;
		while(getline(file,ln)){
			// temp.clear();
			// int start=0;
			// for(int i=0;i<column_names.size();i++){
			// 	int offset=OF[i];
			// 	string sf="";
			// 	sf = ln.substr(start,offset);
			// 	temp.push_back(sf);
			// 	start=offset+2+start;
			// }
			// cout << ln << endl;
			temp = tknze(ln, " ",0);
			// temp[1] = temp[1].substr(0,temp[1].size() - 1);
			i=1;
			jst=temp[cl[0]];
			while(i<cl.size()){
				jst+="," + temp[cl[i]];
				i++;
			}
			sml.push_back(jst);
			rw+=1;
			if(rw==NR){
				spl++;
				tempf.open(("dump/file" + to_string(spl)).c_str());
				sort(sml.begin(),sml.end());
				i=0;
				while(i<sml.size()){
					Oln="";j=0;
					j=1;
					temp.clear();
					int start=0;
					temp = tknze(sml[i], ",",0);
					// temp[1] = temp[1].substr(0,temp[1].size() - 1);

					// for(int kk=0;kk<column_names.size();kk++){
					// 	int offset=OF[cl[kk]];
					// 	string sf="";
					// 	sf = sml[i].substr(start,offset);
					// 	temp.push_back(sf);
					// 	start=offset+1+start;
					// }
					Oln=temp[0];
					while(j<cl.size()){
						Oln+=" "+temp[j];
						cout << "Onl " << (Oln) << endl;
						j++;
					}
					if(Oln != ""){
						tempf << Oln << endl;
					}
					temp.clear();
					i++;
				}
				tempf.close();
				sml.clear();
				rw=0;
			}
		}
		if(sml.size()>0){
			spl++;
			tempf.open(("dump/file" + to_string(spl)).c_str());
			sort(sml.begin(),sml.end(),compare());
			i=0;
			while(i<sml.size()){
				Oln="";
				j=1;
				temp.clear();
				int start=0;
				temp = tknze(sml[i], ",",0);
				// temp[1] = temp[1].substr(0,temp[1].size() - 1);

				Oln=temp[0];
				// cout << temp[0] << " " << temp[1] << " asd \n"; 
				while(j<cl.size()){
					Oln+=" "+temp[j];
					j++;
				}
				if(Oln != ""){
					cout << Oln << endl;
					tempf << Oln << endl;
				}
				i++;
			}
			tempf.close();
			sml.clear();
		} 
		file.close();
		merge(NR,spl,cl);
	}
	else{
		cout << "Couldn't open file." << endl;
		exit(0);
	}
}
int main(int argc,char *argv[]){
	int i,j,k,l,m,n;
	int main_memory;
	string ag;
	vector<string> tosort_columns;
	
	map<string,int> :: iterator it;
	string c,ln;
	if(argc<5){
		cout << "Error in arguments!" << endl;
		exit(0);
	}
	ag=argv[1];
	output=argv[2];
	main_memory=atoi(argv[3]);
	order=argv[4];i=5;
	while(i<argc){
		tosort_columns.push_back(argv[i]);  i++;
	}
	ncols=tosort_columns.size();
	column_names=readVal();  
	vector<int> cl;i=0;
	while(i<tosort_columns.size()){
		c=tosort_columns[i];
		j=0;it=column_names.begin();
		while(it!=column_names.end()){
			if(c==it->first){
				cl.push_back(j);
				break;
			}
			it++;
			j+=1;
		}
		i++;
	}
	int flag;i=0;
	while(i<column_names.size()){
		flag=0;j=0;
		while(j<cl.size()){
			if(cl[j]==i){
				flag=1;
				break;
			}
			j++;
		}
		if(!flag)
			cl.push_back(i);
		i++;
	}
	int row_size=0;
	it=column_names.begin();
	while(it!=column_names.end()){
		row_size+=it->second;
		it++;
	}
	row_size+=(column_names.size()-1)*sizeof(' ');
	int NR=(main_memory*1024*716)/row_size;
	if(NR==0){
		cout << "Not sufficient memory!" << endl;
		exit(0);
	}
	for(std::map<string,int>::iterator iter=column_names.begin(); iter!=column_names.end(); ++iter){
		OF.push_back(iter->second);
	}
	sorT(NR,ag,cl);
	return 0;
}
