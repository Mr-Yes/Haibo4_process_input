#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream in("E://TDDOWNLOAD//passwd//csdn.txt");
	ofstream outD("E://TDDOWNLOAD//passwd//csdn_digit.txt");
	ofstream outL("E://TDDOWNLOAD//passwd//csdn_azAZ.txt");
	ofstream outDL("E://TDDOWNLOAD//passwd//csdn_azAZ_digit.txt");
	if (!in)
		cout << "dakaishibai" << endl;
	char str[1000];
	int cnt = 6428277;
	int Dcnt=0;
	int Lcnt=0;
	int DLcnt=0;
	int tmpcnt= cnt;
	while(tmpcnt--)
	{		
		in >> str;
		int len = strlen(str);
		bool L = false ;
			bool D = false;
			bool S = false;
		for(int i=0; i<len; i++)
		{
			if( str[i] >= '0' && str[i] <= '9')
			{
				D=true;
			}
			else if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )
			{
				L = true;
			}
			else
			{
				S = true;
			}
			
			//string tmp = "";
					
		}
		if(D==true && L == false && S == false)
			{
				Dcnt++;				
				outD<<str<<endl;
			}
		if(D==false && L == true && S == false)
			{
				Lcnt++;			
				outL<<str<<endl;
			}
		if(D==true && L == true && S == false)
			{
				DLcnt++;			
				outDL<<str<<endl;
			}
			
	}
	cout<<"Digits Only"<<endl;
	cout<<Dcnt<<"  "<<cnt<<endl;
	cout << Dcnt/(double)cnt << endl;
	
	cout<<"azAZ Only"<<endl;
	cout<<Lcnt<<"  "<<cnt<<endl;
	cout << Lcnt/(double)cnt << endl;
	
	cout<<"azAZ and digits"<<endl;
	cout<<DLcnt<<"  "<<cnt<<endl;
	cout << DLcnt/(double)cnt << endl;
	return 0;
}
