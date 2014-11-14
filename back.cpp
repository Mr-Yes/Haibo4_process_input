#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define POINT_NUM  4000
#define TRIAN_NUM  3000
#define LARGT_NUM  3000
struct Point  //������� 
{
      double X;
      double Y;
};
struct Triangle		//�����εĶ��� 
{
      int points[3];
      int optris[3];
      double maxlen;
      int maxnum[2];//��ߵ������˵��� 
};
struct PointList	//��� ���� 
{
      Point points[POINT_NUM];
      int     pt_num;
};
struct TrianList	//������  ���� 
{
      Triangle trians[TRIAN_NUM];
      int         tr_num;
};
struct LargTrianList	//�������� ���� 
{
      double lengs[LARGT_NUM];
      int       trians[LARGT_NUM];
      int       locats[LARGT_NUM];
      int       ltr_num;
};


double dist(Point* a,Point* b) //dist between a b
{
	return sqrt( ((*a).X-(*b).X)* ((*a).X-(*b).X)  +  ((*a).Y-(*b).Y)*((*a).Y-(*b).Y) );
}

bool sameside(Point* a ,Point* b ,Point* c)  //c�Ƿ���ֱ��ab ͬ��
{
	//printf("(%lf %lf) (%lf %lf) (%lf %lf) \n",(*a).X,(*a).Y,(*b).X,(*b).Y,(*c).X,(*c).Y);
	if(   ( ((*b).X-(*a).X)*((*c).Y-(*a).Y) - ((*b).Y-(*a).Y)*((*c).X-(*a).X) )    >  0	)
	{
		//printf(" (%lf,%lf) is in (%lf,%lf) (%lf,%lf) the same side\n",c.X,c.Y,a.X,a.Y,b.X,b.Y)  ;
		return true;
	}
	else if(  ( ((*b).X-(*a).X)*((*c).Y-(*a).Y) - ((*b).Y-(*a).Y)*((*c).X-(*a).X) )    ==  0   )
	{
		printf("WARING:3 point in the same line\n");
		return true;
	}
	else
	{
		//printf(" (%lf,%lf) is in (%lf,%lf) (%lf,%lf) the different side\n",c.X,c.Y,a.X,a.Y,b.X,b.Y)  ;
		return false;
	}
} 

int swaptwo(Point* a,Point* b)
{
//	printf("(%lf,%lf) (%lf,%lf) \n",(*a).X,(*a).Y,(*b).X,(*b).Y)  ;
	Point t;
	t.X=(*a).X;
	t.Y=(*a).Y;
	(*a).X=(*b).X;
	(*a).Y=(*b).Y;
	(*b).X=t.X;
	(*b).Y=t.Y;
//	printf("(%lf,%lf) (%lf,%lf) \n\n",(*a).X,(*a).Y,(*b).X,(*b).Y)  ;
	
	return 0;
}

int InitialGrid(PointList* lp, TrianList*lt)
{
	(*lt).tr_num = (*lp).pt_num - 2;
	int i=0;
	for(i=0;i<(*lt).tr_num;i++)
	{
		(*lt).trians[i].points[0] = 0;
		(*lt).trians[i].points[1] = i+1;
		(*lt).trians[i].points[2] = i+2;
		//printf("the % d trians points %d %d %d\n",i,(*lt).trians[i].points[0],(*lt).trians[i].points[1],(*lt).trians[i].points[2]);
		
		if(i==0)
		{
			(*lt).trians[i].optris[0] = -1;
			(*lt).trians[i].optris[1] = -1;
			(*lt).trians[i].optris[2] = i+1;
		}
		else if(i == ( (*lt).tr_num - 1 ) )
		{
			(*lt).trians[i].optris[0] = i-1;
			(*lt).trians[i].optris[1] = -1;
			(*lt).trians[i].optris[2] = -1;
		}
		else
		{
			(*lt).trians[i].optris[0] = i-1;
			(*lt).trians[i].optris[1] = -1;
			(*lt).trians[i].optris[2] = i+1;
		}
		//printf("the % d trians optris %d %d %d\n",i,(*lt).trians[i].optris[0],(*lt).trians[i].optris[1],(*lt).trians[i].optris[2]);
	}
	
} 


int main()
{
	PointList listPoint;
	listPoint.pt_num = 0;
	
	TrianList listTrian;
	listTrian.tr_num = 0;
	
	int samepoints = 0;
	
	// �������� 
	ifstream infile;
	infile.open("skew.txt",ios::in);
	ofstream outfile;
	outfile.open("result.txt",ios::out) ;
	infile >> listPoint.pt_num;	
	int i=0;
	while( i < listPoint.pt_num )
	{
		infile >> listPoint.points[i].X >> listPoint.points[i].Y;
		//outfile << listPoint.points[i].X <<" " << listPoint.points[i].Y<<endl;
		i++;
	}
	
	
	//��������˳�򣬹���͹�� 
	int inlist =1;//�Ѿ���ŵĽڵ���
	i=0;
	int j;
	bool upside; //����ֱ���ϲ� 
	bool allsame;//���е���ͬһ�� 
	while(inlist < listPoint.pt_num)//�ڵ㰴͹��˳�����±�� 
	{
		//printf("come to %d point \n",inlist);			
		for(j=inlist;j<listPoint.pt_num;j++)
		{
			//printf("%d  %d \n",inlist-1,j);
				allsame = true;
				int scnt=0;
				for(int k=0;k<listPoint.pt_num;k++)
				{
					if(k==(inlist-1) || k==j )	
						continue;
					else
					{
						scnt++;				
						if(scnt == 1 )
						{
							upside = sameside(&listPoint.points[inlist-1],&listPoint.points[j],&listPoint.points[k]);
						//	printf("first one \n");	
						//	system("pause");
						}
						else
						{
							if(  upside == sameside(&listPoint.points[inlist-1],&listPoint.points[j],&listPoint.points[k])  )
							{
								//printf("same \n");	
								if(scnt == (listPoint.pt_num -2) )
								{
									swaptwo( &listPoint.points[inlist], &listPoint.points[j] );//���е���ͬһ�࣬�ҵ���һ���� 								
									//printf("find the %d point : (%lf,%lf)  (%lf,%lf) \n",inlist,listPoint.points[inlist-1].X,listPoint.points[inlist-1].Y,listPoint.points[j].X,listPoint.points[j].Y);
									inlist++;
									break;
								}
								continue;
							}
							else
							{
							//	printf("different\n");	
								allsame = false;
								break;
							}
						}
					}
					
				}
				if(allsame == true)
					break;
			
		}
	}
	
	//��ʼ�������� 
	InitialGrid(&listPoint, &listTrian);
/*	for(i=0;i<listPoint.pt_num-2;i++)
	{
		printf("%d   %d %d %d    %d %d %d \n",i,listTrian.trians[i].points[0],listTrian.trians[i].points[1],listTrian.trians[i].points[2],listTrian.trians[i].optris[0],listTrian.trians[i].optris[1],listTrian.trians[i].optris[2] );
	}
*/	

	//�ҵ�����
	int maxtrnum;//�������ڵ������α�� 
	double maxtrlen;//�������������߳��� 
	int parsecnt=0;
oneparse:	
	printf("the %d parse\n",++parsecnt);
	maxtrnum=0;
	maxtrlen=0;
	for(i=0;i<listTrian.tr_num;i++)
	{	
		double len[3];
		len[0]=dist( &listPoint.points[ listTrian.trians[i].points[0] ],&listPoint.points[ listTrian.trians[i].points[1] ]);
		len[1]=dist( &listPoint.points[ listTrian.trians[i].points[1] ],&listPoint.points[ listTrian.trians[i].points[2] ]);
		len[2]=dist( &listPoint.points[ listTrian.trians[i].points[2] ],&listPoint.points[ listTrian.trians[i].points[0] ]);
		int lencnt=0;
		double lentmp=0;
	//	printf("the %d tran points\n",i);
		for(j=0;j<3;j++)
		{			
	//		printf("%d %d  len is %lf\n",listTrian.trians[i].points[j],listTrian.trians[i].points[ ((j+1)%3) ],len[j]);
			if(len[j] > lentmp)
			{
				lencnt =j;
				lentmp = len[j];				
			}
		}
		listTrian.trians[i].maxlen=lentmp;
		listTrian.trians[i].maxnum[0]=listTrian.trians[i].points[lencnt];
		listTrian.trians[i].maxnum[1]=listTrian.trians[i].points[( (lencnt+1)%3 )];
		if(listTrian.trians[i].maxnum[0] > listTrian.trians[i].maxnum[1] )//��֤�߶ζ˵㰴��ֵ��С�������� 
		{
			int daxiao;
			daxiao =  listTrian.trians[i].maxnum[0];
			listTrian.trians[i].maxnum[0] = listTrian.trians[i].maxnum[1];
			listTrian.trians[i].maxnum[1] = daxiao;
		}		
		//printf("the %d tran maxlen is %lf with p %d %d\n",i,lentmp,listTrian.trians[i].maxnum[0],listTrian.trians[i].maxnum[1]);
		if(listTrian.trians[i].maxlen > maxtrlen )
		{
			maxtrnum = i;
			maxtrlen = listTrian.trians[i].maxlen;
		}
	}
	
	//�����ߵ��е㿪ʼ�и�
	if (maxtrlen > 1)
	{
		//����һ���� 
		listPoint.points[listPoint.pt_num].X = ( listPoint.points[ listTrian.trians[maxtrnum].maxnum[0] ].X  + listPoint.points[ listTrian.trians[maxtrnum].maxnum[1] ].X  ) / 2;
		listPoint.points[listPoint.pt_num].Y = ( listPoint.points[ listTrian.trians[maxtrnum].maxnum[0] ].Y  + listPoint.points[ listTrian.trians[maxtrnum].maxnum[1] ].Y  ) / 2;
		
		//printf("the mid of (%lf %lf)",listPoint.points[ listTrian.trians[maxtrnum].maxnum[1] ].X,listPoint.points[ listTrian.trians[maxtrnum].maxnum[1] ].Y);
	//	printf(" (%lf %lf) is",listPoint.points[ listTrian.trians[maxtrnum].maxnum[0] ].X,listPoint.points[ listTrian.trians[maxtrnum].maxnum[0] ].Y );
	//	printf(" (%lf %lf)\n",listPoint.points[listPoint.pt_num].X,listPoint.points[listPoint.pt_num].Y); 
		
		printf("the mid of %d %d is %d ,maxtrlen is %lf\n",listTrian.trians[maxtrnum].maxnum[0],listTrian.trians[maxtrnum].maxnum[1],listPoint.pt_num,maxtrlen);
		listPoint.pt_num++;
/*		bool same = false;
		for(i=0;i<listPoint.pt_num;i++)
		{
			if( (listPoint.points[listPoint.pt_num].X == listPoint.points[i].X ) && (listPoint.points[listPoint.pt_num].Y == listPoint.points[i].Y)  )
			{
				same = true;
				break;
			}
		}
		if(same == false)
		{
			listPoint.pt_num++;
		}
*/		
				
		//add a triangle
		if(listTrian.trians[maxtrnum].maxnum[0] == listTrian.trians[maxtrnum].points[0])
		{
			if(listTrian.trians[maxtrnum].maxnum[1] == listTrian.trians[maxtrnum].points[1])
			{
				listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[1];
				listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
				listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
								
				listTrian.trians[maxtrnum].points[1] = listTrian.trians[maxtrnum].points[2];
				listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
				
				listTrian.tr_num++;		
			}
			else
			{
				listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[1];
				listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
				listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
				
				listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
				
				listTrian.tr_num++;		
			}
		}
		else
		{
				listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[0];
				listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
				listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
				
				listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
				
				listTrian.tr_num++;		
		}
/*		if(listTrian.trians[maxtrnum].maxnum[0] > listTrian.trians[maxtrnum].points[0] )
		{
			if(listTrian.trians[maxtrnum].optris[1] == -1)
			{
				printf("1  ");
				listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[0];
				listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
				listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
				listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[2];
				listTrian.trians[listTrian.tr_num].optris[1] = -1;
				listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
				
				listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
				listTrian.trians[maxtrnum].optris[2] = listTrian.tr_num;
				
				listTrian.tr_num++;				
			}
			else
			{
				int optr = listTrian.trians[maxtrnum].optris[1];
				listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[0];
				listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
				listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
				
				listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
				
				if(listTrian.trians[maxtrnum].maxnum[0] > listTrian.trians[optr].points[0])
				{
					printf("2  ");
					//���ڵ�������Ҳ�и������������
					listTrian.trians[listTrian.tr_num +1 ].points[0] = listTrian.trians[optr].points[0];
					listTrian.trians[listTrian.tr_num +1 ].points[1] = listTrian.trians[optr].points[2];
					listTrian.trians[listTrian.tr_num +1 ].points[2] = listPoint.pt_num-1;
					listTrian.trians[listTrian.tr_num +1 ].optris[0] = listTrian.trians[optr].optris[2];
					listTrian.trians[listTrian.tr_num +1 ].optris[1] = listTrian.tr_num;
					listTrian.trians[listTrian.tr_num +1 ].optris[2] = optr;
					
					listTrian.trians[optr].points[2] = listPoint.pt_num-1;
					listTrian.trians[optr].optris[2] = listTrian.tr_num +1;
										
					listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[2];
					listTrian.trians[listTrian.tr_num].optris[1] = listTrian.tr_num +1;
					listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
					
					listTrian.trians[maxtrnum].optris[2] = listTrian.tr_num;
				}
				else
				{
					if(listTrian.trians[maxtrnum].maxnum[1] == listTrian.trians[optr].points[1])
					{
						printf("3  ");
						//���ڵ�������Ҳ�и������������
						listTrian.trians[listTrian.tr_num +1 ].points[0] = listTrian.trians[optr].points[1];
						listTrian.trians[listTrian.tr_num +1 ].points[1] = listTrian.trians[optr].points[2];
						listTrian.trians[listTrian.tr_num +1 ].points[2] = listPoint.pt_num-1;
						listTrian.trians[listTrian.tr_num +1 ].optris[0] = listTrian.trians[optr].optris[1];
						listTrian.trians[listTrian.tr_num +1 ].optris[1] = optr;
						listTrian.trians[listTrian.tr_num +1 ].optris[2] = listTrian.tr_num;
					
						listTrian.trians[optr].points[1] = listTrian.trians[optr].points[2];
						listTrian.trians[optr].points[2] = listPoint.pt_num-1;
						listTrian.trians[optr].optris[0] = listTrian.trians[optr].optris[2];
						listTrian.trians[optr].optris[1] = listTrian.tr_num +1;
						listTrian.trians[optr].optris[2] = maxtrnum;
										
						listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[2];
						listTrian.trians[listTrian.tr_num].optris[1] = listTrian.tr_num +1;
						listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
						
						listTrian.trians[maxtrnum].optris[2] = listTrian.tr_num;
					}
					else
					{
						printf("4  ");
						listTrian.trians[listTrian.tr_num +1 ].points[0] = listTrian.trians[optr].points[1];
						listTrian.trians[listTrian.tr_num +1 ].points[1] = listTrian.trians[optr].points[2];
						listTrian.trians[listTrian.tr_num +1 ].points[2] = listPoint.pt_num-1;
						listTrian.trians[listTrian.tr_num +1 ].optris[0] = listTrian.trians[optr].optris[1];
						listTrian.trians[listTrian.tr_num +1 ].optris[1] = listTrian.tr_num;
						listTrian.trians[listTrian.tr_num +1 ].optris[2] = optr;
						
						listTrian.trians[optr].points[2] = listPoint.pt_num-1;
						listTrian.trians[optr].optris[1] = listTrian.tr_num +1;
						listTrian.trians[optr].optris[2] = maxtrnum;
											
						listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[2];
						listTrian.trians[listTrian.tr_num].optris[1] = listTrian.tr_num +1;
						listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
						
						listTrian.trians[maxtrnum].optris[2] = listTrian.tr_num;
					}
				}
				listTrian.tr_num +=2;
			}
		}
		else
		{
			if(listTrian.trians[maxtrnum].maxnum[1] == listTrian.trians[maxtrnum].points[1]) 
			{
				if(listTrian.trians[maxtrnum].optris[0] == -1)
				{
					printf("5  ");
					listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[1];
					listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
					listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
					listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
					listTrian.trians[listTrian.tr_num].optris[1] = maxtrnum;
					listTrian.trians[listTrian.tr_num].optris[2] = -1;
					
					listTrian.trians[maxtrnum].points[1] = listTrian.trians[maxtrnum].points[2];
					listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
					listTrian.trians[maxtrnum].optris[0] = listTrian.trians[maxtrnum].optris[2];
					listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
					listTrian.trians[maxtrnum].optris[2] = -1;
					
					listTrian.tr_num++;				
				}
				else
				{
					int opt = listTrian.trians[maxtrnum].optris[0];
					listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[1];
					listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
					listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
					
					listTrian.trians[maxtrnum].points[1] = listTrian.trians[maxtrnum].points[2];
					listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
					
					if(listTrian.trians[maxtrnum].maxnum[0] > listTrian.trians[opt].points[0] )
					{
						printf("6  ");
						listTrian.trians[listTrian.tr_num +1].points[0] = listTrian.trians[opt].points[0];
						listTrian.trians[listTrian.tr_num +1].points[1] = listTrian.trians[opt].points[2];
						listTrian.trians[listTrian.tr_num +1].points[2] = listPoint.pt_num-1;
						listTrian.trians[listTrian.tr_num +1].optris[0] = listTrian.trians[opt].optris[2];
						listTrian.trians[listTrian.tr_num +1].optris[1] = listTrian.tr_num;
						listTrian.trians[listTrian.tr_num +1].optris[2] = opt;
						
						listTrian.trians[opt].points[2] = listPoint.pt_num-1;
						listTrian.trians[opt].optris[2] = listTrian.tr_num +1;
						
						
						listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
						listTrian.trians[listTrian.tr_num].optris[1] = maxtrnum;
						listTrian.trians[listTrian.tr_num].optris[2] = listTrian.tr_num +1;
						
						listTrian.trians[maxtrnum].optris[0] = listTrian.trians[maxtrnum].optris[2]; 
						listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
						listTrian.trians[maxtrnum].optris[2] = opt;
					}
					else
					{
						if(listTrian.trians[maxtrnum].maxnum[1] ==  listTrian.trians[opt].points[1])
						{
							printf("7  ");
							listTrian.trians[listTrian.tr_num +1].points[0] = listTrian.trians[opt].points[1];
							listTrian.trians[listTrian.tr_num +1].points[1] = listTrian.trians[opt].points[2];
							listTrian.trians[listTrian.tr_num +1].points[2] = listPoint.pt_num-1;
							listTrian.trians[listTrian.tr_num +1].optris[0] = listTrian.trians[opt].optris[1];
							listTrian.trians[listTrian.tr_num +1].optris[1] = opt;
							listTrian.trians[listTrian.tr_num +1].optris[2] = listTrian.tr_num;
							
							listTrian.trians[opt].points[1] = listTrian.trians[opt].points[2];
							listTrian.trians[opt].points[2] = listPoint.pt_num-1;
							listTrian.trians[opt].optris[0] = listTrian.trians[opt].optris[2];
							listTrian.trians[opt].optris[1] = listTrian.tr_num +1;
							listTrian.trians[opt].optris[2] = maxtrnum;
							
														
							listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
							listTrian.trians[listTrian.tr_num].optris[1] = maxtrnum;
							listTrian.trians[listTrian.tr_num].optris[2] = listTrian.tr_num +1;
							
							listTrian.trians[maxtrnum].optris[0] = listTrian.trians[maxtrnum].optris[2]; 
							listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
							listTrian.trians[maxtrnum].optris[2] = opt;
						}
						else
						{
							printf("8  ");
							listTrian.trians[listTrian.tr_num +1].points[0] = listTrian.trians[opt].points[1];
							listTrian.trians[listTrian.tr_num +1].points[1] = listTrian.trians[opt].points[2];
							listTrian.trians[listTrian.tr_num +1].points[2] = listPoint.pt_num-1;
							listTrian.trians[listTrian.tr_num +1].optris[0] = listTrian.trians[opt].optris[1];
							listTrian.trians[listTrian.tr_num +1].optris[1] = listTrian.tr_num;
							listTrian.trians[listTrian.tr_num +1].optris[2] = opt;
							
							
							listTrian.trians[opt].points[2] = listPoint.pt_num-1;
							listTrian.trians[opt].optris[1] = listTrian.tr_num +1;
							listTrian.trians[opt].optris[2] = maxtrnum;
							
														
							listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
							listTrian.trians[listTrian.tr_num].optris[1] = maxtrnum;
							listTrian.trians[listTrian.tr_num].optris[2] = listTrian.tr_num +1;
							
							listTrian.trians[maxtrnum].optris[0] = listTrian.trians[maxtrnum].optris[2]; 
							listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
							listTrian.trians[maxtrnum].optris[2] = opt;
						}
					}					
					listTrian.tr_num +=2;
				}
			}
			else
			{
				if(listTrian.trians[maxtrnum].optris[2] == -1)
				{
					printf("9  ");
					listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[1];
					listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
					listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
					listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
					listTrian.trians[listTrian.tr_num].optris[1] = -1;
					listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
					
					listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
					listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
					listTrian.trians[maxtrnum].optris[2] = -1;
					
					listTrian.tr_num++;				
				}
				else
				{
					int optri = listTrian.trians[maxtrnum].optris[2];
					listTrian.trians[listTrian.tr_num].points[0] = listTrian.trians[maxtrnum].points[1];
					listTrian.trians[listTrian.tr_num].points[1] = listTrian.trians[maxtrnum].points[2];
					listTrian.trians[listTrian.tr_num].points[2] = listPoint.pt_num-1;
					
					listTrian.trians[maxtrnum].points[2] = listPoint.pt_num-1;
					
					if(listTrian.trians[maxtrnum].maxnum[0] > listTrian.trians[optri].points[0] )
					{
						printf("10  ");
							listTrian.trians[listTrian.tr_num +1].points[0] = listTrian.trians[optri].points[0];
							listTrian.trians[listTrian.tr_num +1].points[1] = listTrian.trians[optri].points[2];
							listTrian.trians[listTrian.tr_num +1].points[2] = listPoint.pt_num-1;
							listTrian.trians[listTrian.tr_num +1].optris[0] = listTrian.trians[optri].optris[2];
							listTrian.trians[listTrian.tr_num +1].optris[1] = listTrian.tr_num;
							listTrian.trians[listTrian.tr_num +1].optris[2] = optri;
							
							listTrian.trians[optri].points[2] = listPoint.pt_num-1;
							listTrian.trians[optri].optris[1] = maxtrnum;
							listTrian.trians[optri].optris[2] = listTrian.tr_num +1;
							
														
							listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
							listTrian.trians[listTrian.tr_num].optris[1] = listTrian.tr_num +1;
							listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
							
							listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
							listTrian.trians[maxtrnum].optris[2] = optri;
					}
					else
					{
						if(listTrian.trians[maxtrnum].maxnum[1] == listTrian.trians[optri].points[1])
						{
							printf("11  ");
							listTrian.trians[listTrian.tr_num +1].points[0] = listTrian.trians[optri].points[1];
							listTrian.trians[listTrian.tr_num +1].points[1] = listTrian.trians[optri].points[2];
							listTrian.trians[listTrian.tr_num +1].points[2] = listPoint.pt_num-1;
							listTrian.trians[listTrian.tr_num +1].optris[0] = listTrian.trians[optri].optris[1];
							listTrian.trians[listTrian.tr_num +1].optris[1] = optri;
							listTrian.trians[listTrian.tr_num +1].optris[2] = listTrian.tr_num;
							
							listTrian.trians[optri].points[1] = listTrian.trians[optri].points[2];
							listTrian.trians[optri].points[2] = listPoint.pt_num-1;
							listTrian.trians[optri].optris[0] = listTrian.trians[optri].optris[2];
							listTrian.trians[optri].optris[1] = listTrian.tr_num +1;
							listTrian.trians[optri].optris[2] = maxtrnum;
							
														
							listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
							listTrian.trians[listTrian.tr_num].optris[1] = listTrian.tr_num +1;
							listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
							
							listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
							listTrian.trians[maxtrnum].optris[2] = optri;
						}
						else
						{
							printf("12  ");
							listTrian.trians[listTrian.tr_num +1].points[0] = listTrian.trians[optri].points[1];
							listTrian.trians[listTrian.tr_num +1].points[1] = listTrian.trians[optri].points[2];
							listTrian.trians[listTrian.tr_num +1].points[2] = listPoint.pt_num-1;
							listTrian.trians[listTrian.tr_num +1].optris[0] = listTrian.trians[optri].optris[1];
							listTrian.trians[listTrian.tr_num +1].optris[1] = listTrian.tr_num;
							listTrian.trians[listTrian.tr_num +1].optris[2] = optri;
							
							listTrian.trians[optri].points[2] = listPoint.pt_num-1;
							listTrian.trians[optri].optris[1] = listTrian.tr_num +1;
							listTrian.trians[optri].optris[2] = maxtrnum;
							
														
							listTrian.trians[listTrian.tr_num].optris[0] = listTrian.trians[maxtrnum].optris[1];
							listTrian.trians[listTrian.tr_num].optris[1] = listTrian.tr_num +1;
							listTrian.trians[listTrian.tr_num].optris[2] = maxtrnum;
							
							listTrian.trians[maxtrnum].optris[1] = listTrian.tr_num;
							listTrian.trians[maxtrnum].optris[2] = optri;
						}
					}
					listTrian.tr_num +=2;
				}
							
			}
		}
		//��д���˼��һ�飡�������������� 
		for(i=0;i<listTrian.tr_num;i++)
		{
			printf("the %d (%d %d %d)\n",i+1,listTrian.trians[i].points[0],listTrian.trians[i].points[1],listTrian.trians[i].points[2]);
		}
*/	//	system("pause");
		goto oneparse;
		
	}
	
	bool overlap[POINT_NUM];
	for(i=0;i<POINT_NUM;i++)
	{
		overlap[i] = false;
	}
	for(i=0;i<listPoint.pt_num;i++)
	{
		if( overlap[i] == true )
		{
			continue;
		}
		for(j=i+1;j<listPoint.pt_num;j++)
		{
			if(overlap[j] == true)
			{
				continue;
			}
			if(  dist(&listPoint.points[i],&listPoint.points[j]) == 0  )
			{
				overlap[j] = true;
				samepoints ++;
				int loop;
				for(loop=0;loop<listTrian.tr_num;loop++)
				{
					if(listTrian.trians[loop].points[0] == j)
					{
						listTrian.trians[loop].points[0] = i;
					} 
					if(listTrian.trians[loop].points[1] == j)
					{
						listTrian.trians[loop].points[1] = i;
					} 
					if(listTrian.trians[loop].points[2] == j)
					{
						listTrian.trians[loop].points[2] = i;
					} 
				}
			}
		}
	}
	
	outfile << listPoint.pt_num - samepoints<<endl;
	for(i=0;i<listPoint.pt_num;i++)
	{
		if(overlap[i] == false)
		{
			outfile << listPoint.points[i].X <<" " <<listPoint.points[i].Y<<endl;
		}
	}
	outfile << listTrian.tr_num <<endl;
	for(i=0;i<listTrian.tr_num;i++)
	{
		outfile << listTrian.trians[i].points[0] << " "<<listTrian.trians[i].points[1] << " "<<listTrian.trians[i].points[2]<<endl;
	}
	/*	FindLargTrians(&listPoint, &listTrian, &largtrs);

	if (!Triangular(&listPoint, &listTrian, &largtrs))
	{
	      printf("Triangular Error!\n");
	      exit(0);
	}

	char *outFile = "result.txt";
	if (!WriteFile(&listPoint, &listTrian, outFile))
	{
	      printf("Writing file failed!\n");
	      exit(0);
	}
	
*/
	infile.close();
	outfile.close();
	return 0;

}

/*
ReadFile(&listPoint, inFile)
WriteFile(&listPoint, &listTrian, outFile)
InitialGrid(&listPoint, &listTrian)
FindLargTrians(&listPoint, &listTrian, &largtrs)
Triangular(&listPoint, &listTrian, &largtrs)
*/

