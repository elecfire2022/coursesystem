#include "course.h"
#include "function_sort_and_search.cpp"
#include "function_upload_and_update.cpp"
course item[1000];
int main()
{
	int m;
	cout << "���ԣ�����0�������ܣ�����1������ҹ��ܣ�����2����������,����3�����ϴ�����" << endl;
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
			ifstream in("_course_information.txt");
			while(read_course(in, item[total]))
			{
				total++;
			}
			in.close();
			quicksort(item,0,total-1,k);
			for(int i = 0 ; i < total ; i++)
			{
				print_course(cout, item[i]);
			}
		}
		else if(m == 3)
		{
			cout << "��ѡ���ϴ�������:"
				 << "����1�ϴ���ҵ,����2�ϴ��γ�����" << endl; 
			int k;
			cin >> k; 
			if(k == 1)
			{
				string coursename,homeworkname;
				cout << "��������ҵ�����γ����ƣ�\n";
				cin >> coursename;
				cout << "��������ҵ���ƣ�\n" ;
				cin >> homeworkname;
				upload_homework(coursename,homeworkname);
			}
			else if(k == 2)
			{
				string coursename,dataname;
				int year,month,day;
				cout << "������γ����ƣ�\n" ;
				cin >> coursename; 
				cout << "������γ������������ϴ����ڣ�\n" ;
				cin >> dataname >> year >> month >> day;
				upload_data(coursename,dataname,year,month,day);	
			} 
		} 
		else
		{
			cout << "����ָ���ȷ\n" << endl;
		}
	   cout << "���ԣ�����0�������ܣ�����1������ҹ��ܣ�����2����������,����3�����ϴ�����" << endl; 	
	   cin >> m;	
	}
	return 0; 
}
