void upload_data(string coursename,string dataname,int year,int month,int day)
{
	string temp = coursename;//��ʱ����γ����� 
	coursename += "_coursedatalist.txt";
	ofstream out;
	out.open(coursename.c_str(),ofstream::app);//�򿪿γ������ļ��嵥�����γ�������Ϣ�����ļ��� 
	out << dataname << " " << year << " " << month << " " << day << endl;
	out.close();//�ر��ļ������ 
	dataname = "coursedata/" + temp + "_" + dataname + ".txt";//����γ������ļ��д���γ�����
	out.open(dataname.c_str());//�򿪿γ������ļ����������ļ�
	out.close(); 
}
void upload_homework(string coursename,string homeworkname)
{
	string temp = coursename;//��ʱ����γ����� 
	coursename += "_homeworklist.txt";
	ofstream out;
	out.open(coursename.c_str(),ofstream::app);//����ҵ�ļ��嵥������ҵ��Ϣ�����ļ��� 
	out << "\n" << homeworkname << " 1" << endl;
	out.close();//�ر��ļ������ 
	homeworkname = "homework/" + temp + "_" + homeworkname + ".txt";//����γ������ļ��д���γ�����
	out.open(homeworkname.c_str());//�򿪿γ������ļ����������ļ�
	out.close(); 
} 
