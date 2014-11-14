#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

//run this program using the console pauser or add your own getch, system("pause") or input loop 

bool pscmp(char* p ,char*q){
	int tp=0;
	while(p[tp]!='\0' && q[tp]!='\0'){
		if(p[tp] != q[tp]){
			return false;
		}
		else{
			tp++;
		}
	}
	if(p[tp] != q[tp]){
		return false;
	}
	else{
		return true;
	}
}

bool strcharcmp(char*p,string str){
	string q=p;
	if(q==str){
		return true;
	}
	return false;
}


int main(int argc, char** argv) {

//	ifstream in2("E://TDDOWNLOAD//7k//tianya_test.txt");

	ifstream in7("E://TDDOWNLOAD//7k//7k7k_1.txt");
	ifstream in2("E://TDDOWNLOAD//7k//tianya_2.txt");
	ifstream in3("E://TDDOWNLOAD//7k//tianya_3.txt");
	
	ofstream out71("E://TDDOWNLOAD//7k//7k7k_copy.txt");
//	ofstream out72("E://TDDOWNLOAD//7k//7k7k_not_copy.txt");
	ofstream out("E://TDDOWNLOAD//7k//tianya_copy.txt");
	if ( (!in3)  &&  (!in2) )
	{
		cerr << "open failed" << endl;
		return -1;
	}
	
	int tmp = 0;

	string name2;
	char ps2[100];
	while(in2>>name2){
		//cout<<++tmp<<endl;
		while(in2.peek()=='\t'){
			in2.get();
		}
		in2.getline(ps2,100,'\n');
				
		string mail7;
		char ps7[100];
		bool ismatch = false;
		ifstream in7("E://TDDOWNLOAD//7k//7k7k_1.txt");
		while(in7>>mail7){
			while(in7.peek()=='\t'){
				in7.get();
			}
			in7.getline(ps7,100,'\n');
			
			if(name2!=mail7){				
				continue;
			}
			else{
				if(!pscmp(ps2,ps7)){
					continue;
				}
				else{
					ismatch = true;
					out71<<mail7<<"  "<<ps7<<endl;
					out<<name2<<"  "<<ps2<<endl;
					break;
				}
			}
		}
		if(!ismatch){
			//out72<<mail7<<"  "<<ps7<<endl;
		}
	}
	
	string name3;
	string ps3; 
	char mail3[100];
	while(in3>>name3){
		//cout<<++tmp<<endl;
		in3>>ps3;
		while(in3.peek()=='\t'){
			in3.get();
		}
		in3.getline(mail3,100,'\n');		
		
		string mail7;
		char ps7[100];
		bool ismatch = false;
		ifstream in7("E://TDDOWNLOAD//7k//7k7k_1.txt");
		while(in7>>mail7){
			while(in7.peek()=='\t'){
				in7.get();
			}
			in7.getline(ps7,100,'\n');
			
			if(! strcharcmp(ps7,ps3)){
				continue;
			}
			else{
				if(name3 != mail7){
					continue;
				}
				else{
					if(strcharcmp(mail3,mail7)){
						ismatch=true;
						out71<<mail7<<"  "<<ps7<<endl;
						out<<name2<<"  "<<ps2<<endl;
						break;
					}
					else{
						continue;
					}
				}
			
			}			
			
		}
		if(!ismatch){
			//out72<<mail7<<"  "<<ps7<<endl;
		}
	}

	return 0;
}


/*the same part division
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

//run this program using the console pauser or add your own getch, system("pause") or input loop 

bool pscmp(char* p ,char*q){
	int tp=0;
	while(p[tp]!='\0' && q[tp]!='\0'){
		if(p[tp] != q[tp]){
			return false;
		}
		else{
			tp++;
		}
	}
	if(p[tp] != q[tp]){
		return false;
	}
	else{
		return true;
	}
}

bool strcharcmp(char*p,string str){
	string q=p;
	if(q==str){
		return true;
	}
	return false;
}


int main(int argc, char** argv) {
	ifstream in7("E://TDDOWNLOAD//7k//7k7k_test.txt");
	ifstream in2("E://TDDOWNLOAD//7k//tianya_test.txt");

//	ifstream in7("E://TDDOWNLOAD//7k//7k7k_1.txt");
//	ifstream in2("E://TDDOWNLOAD//7k//tianya_2.txt");
	ifstream in3("E://TDDOWNLOAD//7k//tianya_3.txt");
	
	ofstream out7111("E://TDDOWNLOAD//7k//7k7k_111.txt");
	ofstream out7222("E://TDDOWNLOAD//7k//7k7k_222.txt");
	ofstream out7tianya("E://TDDOWNLOAD//7k//7k7k_tianya.txt");
	ofstream out_tianya111("E://TDDOWNLOAD//7k//tianya_111.txt");
	ofstream out_tianya222("E://TDDOWNLOAD//7k//tianya_222.txt");
	ofstream out_tianyatianya("E://TDDOWNLOAD//7k//tianya_tianya.txt");
	
	ofstream out71("E://TDDOWNLOAD//7k//7k7k_copy.txt");
//	ofstream out72("E://TDDOWNLOAD//7k//7k7k_not_copy.txt");
	ofstream out("E://TDDOWNLOAD//7k//tianya_copy.txt");
	if ( (!in7)  && (!in3)  &&  (!in2) )
	{
		cerr << "open failed" << endl;
		return -1;
	}
	
	string mail77;
	char ps77[100];
	while(in7>>mail77){
		while(in7.peek()=='\t'){
			in7.get();
		}
		in7.getline(ps77,100,'\n');
		if(pscmp(ps77,"111") ){
			out7111<<mail77<<endl;
		}
		if(pscmp(ps77,"222")){
			out7222<<mail77<<endl;
		}
		if(pscmp(ps77,"tianya")){
			out7tianya<<mail77<<endl;
		}
		
	}
	
	string name2;
	char ps2[100];
	while(in2>>name2){
		while(in2.peek()=='\t'){
			in2.get();
		}
		in2.getline(ps2,100,'\n');
		
		if(pscmp(ps2,"111") ){
			out_tianya111<<name2<<endl;
		}
		if(pscmp(ps2,"222")){
			out_tianya222<<name2<<endl;
		}
		if(pscmp(ps2,"tianya")){
			out_tianyatianya<<name2<<endl;
		}
		
		string mail7;
		char ps7[100];
		bool ismatch = false;
		while(in7>>mail7){
			while(in7.peek()=='\t'){
				in7.get();
			}
			in7.getline(ps7,100,'\n');
			
			if(name2!=mail7){				
				continue;
			}
			else{
				if(!pscmp(ps2,ps7)){
					continue;
				}
				else{
					ismatch = true;
					out71<<mail7<<"  "<<ps7<<endl;
					out<<name2<<"  "<<ps2<<endl;
					break;
				}
			}
		}
		if(!ismatch){
			//out72<<mail7<<"  "<<ps7<<endl;
		}
	}
	string name3;
	string ps3; 
	char mail3[100];
	while(in3>>name3){
		in3>>ps3;
		while(in3.peek()=='\t'){
			in3.get();
		}
		in3.getline(mail3,100,'\n');
		
		if(strcharcmp("111",ps3) ){
			out_tianya111<<name3<<"  " <<mail3<<endl;
		}
		if(strcharcmp("222",ps3) ){
			out_tianya222<<name3<<"  " <<mail3<<endl;
		}
		if(strcharcmp("tianya",ps3) ){
			out_tianyatianya<<name3<<"  " <<mail3<<endl;
		}
		
		string mail7;
		char ps7[100];
		bool ismatch = false;
		while(in7>>mail7){
			while(in7.peek()=='\t'){
				in7.get();
			}
			in7.getline(ps7,100,'\n');
			
			if(! strcharcmp(ps7,ps3)){
				continue;
			}
			else{
				if(name3 != mail7){
					continue;
				}
				else{
					if(strcharcmp(mail3,mail7)){
						ismatch=true;
						out71<<mail7<<"  "<<ps7<<endl;
						out<<name2<<"  "<<ps2<<endl;
						break;
					}
					else{
						continue;
					}
				}
			
			}			
			
		}
		if(!ismatch){
			//out72<<mail7<<"  "<<ps7<<endl;
		}
	}

	return 0;
}

*/


/*Process the tianya with 2 and 3 colume
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

//run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv) {
	ifstream in7("E://TDDOWNLOAD//7k//7k7k_1.txt");
	ifstream in1("E://TDDOWNLOAD//7k//tianyaAll1.txt");
	ifstream in2("E://TDDOWNLOAD//7k//tianyaAll2.txt");
//	ofstream out7("E://TDDOWNLOAD//7k//7k7k_1.txt");
//	ofstream out7del("E://TDDOWNLOAD//7k//7k7k_2.txt");
	ofstream outpre2("E://TDDOWNLOAD//7k//tianya_2.txt");
	ofstream outpre3("E://TDDOWNLOAD//7k//tianya_3.txt");
	
	ofstream out71("E://TDDOWNLOAD//7k//7k7k_copy.txt");
	ofstream out72("E://TDDOWNLOAD//7k//7k7k_not_copy.txt");
	ofstream out("E://TDDOWNLOAD//7k//tianya_copy.txt");
	if ( (!in7)  && (!in1)  &&  (!in2) )
	{
		cerr << "open failed" << endl;
		return -1;
	}
	
	char t[200];
	char ty[3][70];
	int tmp=0;
	while(in1.getline(t,200,'\n')){
		tmp++;
		
		int tp=0;
		int typ=0;
		int off[3]={0,0,0};

			while(t[tp] != '\t'){
				tp++;
			}
			off[0]=tp-1;
			while(t[tp] == '\t'){
				tp++;
			}
			off[1]=tp;
			while(1){
				if(t[tp] == '\t'){
					outpre3<<t<<endl;
					break;
				}
				else if(t[tp] == '\0'){
					outpre2<<t<<endl;
//					cout<<tmp<<endl;
					break;
				}
				else{
					tp++;
				}
			}
	}
	
	while(in2.getline(t,200,'\n')){
		tmp++;
		
		int tp=0;
		int typ=0;
		int off[3]={0,0,0};

			while(t[tp] != '\t'){
				tp++;
			}
			off[0]=tp-1;
			while(t[tp] == '\t'){
				tp++;
			}
			off[1]=tp;
			while(1){
				if(t[tp] == '\t'){
					outpre3<<t<<endl;
					break;
				}
				else if(t[tp] == '\0'){
					outpre2<<t<<endl;
//					cout<<tmp<<endl;
					break;
				}
				else{
					tp++;
				}
			}
	}
	cout<<tmp<<endl;
/*	
	char str[100];	
//	int tmp=0;
	while(in7.getline(str,100,'\n')){
//		tmp++;
		if(str[0] != '\t'){
			out7<<str<<endl;
		}
		
		
	string name7;
	string ps7;
	while(in7>>name7){
		in7>>ps7;
		out7<<name7<<" "<<ps7<<endl;
	}
*/	
	
//	return 0;
//}

/*7k7k single line delete 
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

//run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv) {
	ifstream in7("E://TDDOWNLOAD//7k//7k7kAll.txt");
//	ifstream intianya1("E://TDDOWNLOAD//7k//tianyaAll1.txt");
//	ifstream intianya2("E://TDDOWNLOAD//7k//tianyaAll2.txt");
	ofstream out7("E://TDDOWNLOAD//7k//7k7k_1.txt");
	ofstream out7del("E://TDDOWNLOAD//7k//7k7k_2.txt");
	ofstream out71("E://TDDOWNLOAD//7k//7k7k_copy.txt");
	ofstream out72("E://TDDOWNLOAD//7k//7k7k_not_copy.txt");
	ofstream out("E://TDDOWNLOAD//7k//tianya_copy.txt");
	if (!in7)
	{
		cerr << "open failed" << endl;
		return -1;
	}
	int cnt7k=19138450;
	int tianya1=0;
	int tianya2=0;
	char str[100];
	
	int tmp=0;
	while(in7.getline(str,100,'\n')){
		tmp++;
		if(str[0] != '\t'){
			out7<<str<<endl;
		}
		else{
			out7del<<tmp<<"  llllllll"<<str <<endl;
		}
	}
	*/
/*	
	string name7;
	string ps7;
	while(in7>>name7){
		in7>>ps7;
		out7<<name7<<" "<<ps7<<endl;
	}
*/	
/*		
	return 0;
}
*/

/*
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv) {
	ifstream in7del("E://TDDOWNLOAD//7k//7k7kAll.txt");
	ofstream out7del("E://TDDOWNLOAD//7k//7k7k_1.txt");
//	ifstream intianya1("E://TDDOWNLOAD//7k//tianyaAll1.txt");
//	ifstream intianya2("E://TDDOWNLOAD//7k//tianyaAll2.txt");
//	ofstream out71("E://TDDOWNLOAD//7k//7k7k_copy.txt");
//	ofstream out72("E://TDDOWNLOAD//7k//7k7k_not_copy.txt");
//	ofstream out("E://TDDOWNLOAD//7k//tianya_copy.txt");
	if (!in7del)
	{
		cout << "open failed" << endl;
		return 0;
	}
//	int cnt7k=19138450;
//	int tianya1=0;
//	int tianya2=0;
	char str[100];
	bool endline = false;
	int cnt=0;
	while(in7del.getline(str,200)){
		cnt++;
		if(str[0] != ' '){
			out7del<<str<<endl;			
		}
		else{
			cout<<cnt<<endl;
		}
	}
		
	return 0;
}

*/

