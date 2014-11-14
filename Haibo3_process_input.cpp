#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream fin("E://TDDOWNLOAD//fugailv//201407//duowan_100w.txt");
	ofstream fout("E://TDDOWNLOAD//fugailv//20140919//duowan_100w_alpha_tmp.txt");
	if (!fin)
		cout << "dakaishibai" << endl;
	char str[100];
	int cnt = 1000000;
//	int tmpcnt= cnt;
	while(fin >> str){
	//	cout<<cnt-tmpcnt<<endl;
			
		
		int len = strlen(str);
		bool lianxu = false ;
		bool pure=true;
		for(int j=0; j<len; j++)
		{
			if(str[j] < '0' || str[j] > '9'){
				pure = false;
				break;
			}
		}
		if(pure){  //all digits
			continue;
		}
		for(int i=0; i<len; i++)
		{
			if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )
			{
				lianxu= true;
				fout<<str[i];
			}
			else
			{				
				if(lianxu==true){
					fout<<endl;
				}
				lianxu = false;
			}
		}
		fout<<endl;	
	}
	//cout<<tmpcnt<<endl;
	
	ifstream fin2("E://TDDOWNLOAD//fugailv//20140919//duowan_100w_alpha_tmp.txt");
	if (!fin2)
		cout << "dakaishibai" << endl;
	ofstream fout2("E://TDDOWNLOAD//fugailv//20140919//duowan_100w_alpha.txt");
	char str2[100];
	while(fin2>>str2){
		if(strlen(str2)>0){
			fout2<<str2<<endl;
		}
	}
	return 0;
}
