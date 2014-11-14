#include <iostream>
#include<fstream>
#include<string.h>
#include<string> 
using namespace std;

//run this program using the console pauser or add your own getch, system("pause") or input loop 

	
	#define namesize  3000000
	string namestr[namesize];
	bool in_name[namesize];


int main(int argc, char** argv) {
	double namenum=2426841;
	double testnum=25698398;////////////////////////////////////
	int tmp = 0;

	ifstream fin0("E://TDDOWNLOAD//fugailv//sorted//name_pinyin_no_count_sort.txt");	//name
	if(!fin0){
		cerr << "open failed" << endl;
		return -1;
	}
	int i=0;
	while(fin0>>namestr[i]){
		in_name[i]=false;
		i++;		
	}
	
	
	bool ismatch = false;
	
	string ps;		
	///////////////////////////////////////////
	//7k7k_alpha2_sort
	//178_alpha2_sort 
	//csdn_alpha2_sort
	//dodonew_alpha2_sort 
	//tianya_alpha2_sort 
	//duowan_100w_rest_alpha2_sort 
	//name减去在训练集中出现的字母组件, 对测试集的字母组件的覆盖率
	int name_in_test=0;	
	ifstream fin2("E://TDDOWNLOAD//fugailv//sorted//rockyou_alpha2_sort.txt");  //test	
	if(!fin2){
		cerr << "open failed" << endl;
		return -1;
	}
	while(fin2>>ps){
		//		ismatch=false;	
		int head=0;
		int tail=namenum-1;
		while(1){
			if(head==tail){
				if(ps == namestr[head]){
						name_in_test++;
						break;
				}
				break;			
			}
			else if(head == tail-1){
				if(ps==namestr[head]){
						name_in_test++;
						break;
				}
				else if(ps==namestr[tail]){
						name_in_test++;
						break;
				}
				break;
			}
			else{
				if(ps==namestr[head]){
						name_in_test++;
						break;
				}
				else if(ps==namestr[tail]){
						name_in_test++;
						break;
				}
				else{
					int mid=(head+tail)/2;
					if(ps<=namestr[mid]){
						tail=mid;
						continue;
					}
					else{
						head=mid;
						continue;
					}
				} 
			}
		}
//		cout<<++tmp<<endl;
	}
	cout<<name_in_test<<"  "<<name_in_test/testnum<<endl;
	
	return 0;
}

/* 
#include <iostream>
#include<fstream>
#include<string.h>
#include<string> 
using namespace std;

//run this program using the console pauser or add your own getch, system("pause") or input loop 

	
	#define namesize  3000000
	string namestr[namesize];
	bool in_name[namesize];


int main(int argc, char** argv) {
//	ofstream fout("E://TDDOWNLOAD//fugailv//name_not_in_duowan_100w.txt");
	//174797
	// 229362 
	//331070 
	//294644
	// 205461 
	double namenum=2426841;
	double testnum=1251745;////////////////////////////////////
	int tmp = 0;

	ifstream fin0("E://TDDOWNLOAD//fugailv//sorted//name_pinyin_no_count_sort.txt");	//name
	if(!fin0){
		cerr << "open failed" << endl;
		return -1;
	}
	int i=0;
	while(fin0>>namestr[i]){
		in_name[i]=false;
		i++;		
	}
	
	//duowan_100w_alpha2_sort
	 //duowan_alpha2_sort 
	 //rockyou_100w_alpha2_sort 
	 //rockyou_400w_alpha2_sort 
	int name_in=0;
	bool ismatch = false;
	ifstream fin1("E://TDDOWNLOAD//fugailv//sorted//rockyou_400w_alpha2_sort.txt"); //practice
	if(!fin1){
		cerr << "open failed" << endl;
		return -1;
	}
	//训练集中字母组件对name的覆盖率 
	string ps;	
	while(fin1>>ps){
//		ismatch=false;	
		int head=0;
		int tail=namenum-1;
		while(1){
			if(head==tail){
				if(ps == namestr[head]){	
					name_in++;
//					ismatch=true;
					in_name[head]=true;
					break;
				}
				break;			
			}
			else if(head == tail-1){
				if(ps==namestr[head]){
					name_in++;
//					ismatch=true;
					in_name[head]=true;
					break;
				}
				else if(ps==namestr[tail]){
					name_in++;
//					ismatch=true;
					in_name[tail]=true;
					break;
				}
				break;
			}
			else{
				if(ps==namestr[head]){
					name_in++;
//					ismatch=true;
					in_name[head]=true;
					break;
				}
				else if(ps==namestr[tail]){
					name_in++;
//					ismatch=true;
					in_name[tail]=true;
					break;
				}
				else{
					int mid=(head+tail)/2;
					if(ps<=namestr[mid]){
						tail=mid;
						continue;
					}
					else{
						head=mid;
						continue;
					}
				} 
			}
		}
//		cout<<++tmp<<endl;
	}
	cout<<name_in<<"  "<<name_in/namenum<<endl;
		
	///////////////////////////////////////////
	//7k7k_alpha2_sort
	//178_alpha2_sort 
	//csdn_alpha2_sort
	//dodonew_alpha2_sort 
	//tianya_alpha2_sort 
	//duowan_100w_rest_alpha2_sort 
	//name减去在训练集中出现的字母组件, 对测试集的字母组件的覆盖率
	int name_in_test=0;	
	ifstream fin2("E://TDDOWNLOAD//fugailv//sorted//7k7k_alpha2_sort.txt");  //test	
	if(!fin2){
		cerr << "open failed" << endl;
		return -1;
	}
	while(fin2>>ps){
		//		ismatch=false;	
		int head=0;
		int tail=namenum-1;
		while(1){
			if(head==tail){
				if(ps == namestr[head]){
					if(in_name[head]==false){
						name_in_test++;
						break;
					}
					break;
				}
				break;			
			}
			else if(head == tail-1){
				if(ps==namestr[head]){
					if(in_name[head]==false){
						name_in_test++;
						break;
					}
					break;
				}
				else if(ps==namestr[tail]){
					if(in_name[tail]==false){
						name_in_test++;
						break;
					}
					break;
				}
				break;
			}
			else{
				if(ps==namestr[head]){
					if(in_name[head]==false){
						name_in_test++;
						break;
					}
					break;
				}
				else if(ps==namestr[tail]){
					if(in_name[tail]==false){
						name_in_test++;
						break;
					}
					break;
				}
				else{
					int mid=(head+tail)/2;
					if(ps<=namestr[mid]){
						tail=mid;
						continue;
					}
					else{
						head=mid;
						continue;
					}
				} 
			}
		}
//		cout<<++tmp<<endl;
	}
	cout<<name_in_test<<"  "<<name_in_test/testnum<<endl;
	
	return 0;
}
*/ 
/*
#include <iostream>
#include<fstream>
#include<string.h>
#include<string> 
using namespace std;

//run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv) {
	ofstream fout("E://TDDOWNLOAD//fugailv//name_not_in_duowan_100w.txt");
	double namenum=2426841;
	double testnum=3982730;////////////////////////////////////
	int tmp = 0;

	int namecnt=0;
	string name;
	int name_in=0;
	bool ismatch = false;
	ifstream fin1("E://TDDOWNLOAD//fugailv//duowan_100w_alpha2.txt"); //practice
	if(!fin1){
			cerr << "open failed" << endl;
			return -1;
	}
	string ps;	
	while(fin1>>ps){
		tmp++;
		
		ismatch=false;
		ifstream fin0("E://TDDOWNLOAD//fugailv//201407//name_pinyin.txt");	//name
		if(!fin0){
			cerr << "open failed" << endl;
			return -1;
		}
		
		while(fin0>>namecnt){
			fin0>>name;
			if(name == ps){	
				name_in++;
				ismatch=true;
				break;
			}			
		}
		if(! ismatch){
			fout<<namecnt<<'\t'<<name<<endl;
			cout<<tmp<<"  "<<name<<endl;			
		}
	}
	cout<<name_in/namenum<<endl;
	
	int name_in_test=0;
	ifstream fin00("E://TDDOWNLOAD//fugailv//name_not_in_duowan_100w.txt");	//name
	if(!fin00){
		cerr << "open failed" << endl;
		return -1;
	}
	
	while(fin00>>namecnt){
		fin00>>name;
		
		ifstream fin2("E://TDDOWNLOAD//fugailv//201407//duowan_100w_rest.txt");  //test	
		if(!fin2){
		cerr << "open failed" << endl;
		return -1;
		}
		string ps;
		while(fin2>>ps){
			if(name == ps){	
				name_in_test++;
			}			
		}
	}
	cout<<name_in_test/testnum<<endl;
	
	return 0;
}
*/ 
