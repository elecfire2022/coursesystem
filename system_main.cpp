#include"course_defination.h"
#include"function1_search.cpp"
#include"function1_sort.cpp"
course item[1000];
int main()
{
	int m;
	cout<<"���ԣ�����0����������1���ң�����2����"<<endl;
	cin >> m;
	while(m != 0)
	{
	   if( m == 1)
	   {
	   	cout<<"������γ�����:\n"; 
	   	search();
		}	
		else if( m == 2)
		{
			
			
			int k,total = 0;
			cout<<"�����������ࣺ1���ƣ�2�Ͽεص�\n";
			cin >> k;
			ifstream in("courseinformation.txt");
			while(read_course(in, item[total]))total++;
			in.close();
			quicksort(item,0,total-1,k);
			for(int i = 0 ; i < total ; i++)
			{
				print_course(cout, item[i]);
				cout<<endl;
			}
		}
	   cout<<"���ԣ�����1"<<endl; 	
	   cin >> m;	
	} 
    
}
