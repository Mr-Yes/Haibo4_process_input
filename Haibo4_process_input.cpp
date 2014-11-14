
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

// run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv) {
	ifstream fin("E://TDDOWNLOAD//fugailv//201407//facebook-lastnames-withcount.txt");
	ofstream fout("E://TDDOWNLOAD//fugailv//alpha_with_all_length//facebook-lastnames-nocount.txt");
	if (!fin)
		cout << "dakaishibai" << endl;
		
	int cnt;
	char str[100];
//	int cnt = 1000000;
//	int tmpcnt= cnt;
	while(fin >> cnt){
		fin>>str;
		fout<<str<<endl;	
	}
	return 0;
}

/*
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

// run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv) {
	ifstream fin("E://TDDOWNLOAD//fugailv//201407//7k7k.txt");
	ofstream fout("E://TDDOWNLOAD//fugailv//alpha_with_all_length//7k7k_alpha_tmp.txt");
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
	
	ifstream fin2("E://TDDOWNLOAD//fugailv//alpha_with_all_length//7k7k_alpha_tmp.txt");
	if (!fin2)
		cout << "dakaishibai" << endl;
	ofstream fout2("E://TDDOWNLOAD//fugailv//alpha_with_all_length//7k7k_alpha_with_all_length.txt");
	char str2[100];
	int len1=0;
	int len2=0;
	int len3=0;
	int len4=0;
	while(fin2>>str2){
		int passlen= strlen(str2);
		if(passlen>0){
			fout2<<str2<<endl;
		}
		if(passlen==1){
			len1++;
		}
		if(passlen==2){
			len2++;
		}
		if(passlen==3){
			len3++;
		}
		if(passlen>3){
			len4++;
		}
	}
	cout<<len1<<"  "<<len2<<"  "<<len3<<"  "<<len4<<endl;
	return 0;
}
*/
