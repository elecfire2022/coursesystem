void search()
{
	int flag = 0;//�����ʶ�����ж��Ƿ��ѯ����Ӧ�γ� 
	string goal;//���ѯ�γ̵����� 
	course item;
	cin >> goal;//����γ����� 
    ifstream in("courseinformation.txt");
    while(read_course(in, item))
    {
    	if( item.course_name.compare(goal) == 0)
    	{
    		flag = 1;
			print_course(cout,item);
		}//���ҵ���Ӧ�� 
	}
	in.close();
	if(!flag)
	{
		cout<<"no this course.\n";
	}
}
int course_compare(course a,course b,int k)
{
	int t;
	switch(k)
	{
		case 1:
		t = a.course_name.compare(b.course_name);
		break;//kΪ1ʱ���ݿγ���������
		case 2:
		t = a.class_loc.campus.compare(b.class_loc.campus);//kΪ2ʱ����У����������
		if( t == 0 )
		{
			t = a.class_loc.position.compare(b.class_loc.position);//У����ͬʱ���ݿγ̵ص��������
		}
		break;
		case 3:
			
		break;
	
	}
	return t;
}//�γ̱Ƚ�
void quicksort(course *item,int begin,int end,int k)
{
   if(begin > end)return;
   int i , j ;
   course temp;
   temp = item[begin];
   i = begin;
   j = end ;
   while(i < j)
   {
   	while( i < j && course_compare(item[j] , temp , k) > 0)j--;
   	item[i] = item[j];
   	while( i < j && course_compare(item[i] , temp , k) <= 0 )i++;
   	item[j] = item[i];   
   }
   item[i] = temp;
   quicksort(item, begin, i-1,k);
   quicksort(item, i+1,end, k);	
}//��������
