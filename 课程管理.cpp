#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct time
{
    string weekday,hour, minute;
};//����һ���࣬�������ڡ�ʱ����
struct location
{
    int x,y;
    string position;
    string campus;
};//����һ���࣬�����ص�����ƺ�����
struct homework
{
    int flag;
    string workname;
};//����һ���࣬������ҵ����Ϣ,flagΪ1��ʾ�ѽ���Ϊ0��ʾδ�� 
struct course_data
{
};
class course
{
    friend istream &read_course(istream &, course &);//���ļ��ж���γ���Ϣ
    friend ostream &print_course(ostream &, course &);//��ӡ�γ���Ϣ
    friend istream &read_homework(istream &, homework&);//���ļ��ж�ȡ�γ���ҵ��Ϣ
public:
    
private:
    string course_name;//�γ�����
    location class_loc;//�γ̵ص�
    time start_time;//�γ̿�ʼʱ��
    time end_time;//�γ̽���ʱ��
    string teacher_name;//��ʦ����
    int total_section;//�γ��ܽ���
    int cur_section;//��ǰ�γ̽���
    double progress_percent;//�γ̽��Ȱٷֱ�
    string course_group;//�γ�Ⱥ
    string homework_filename; //��ҵ�嵥�ļ�����
    string course_data_filename;//�γ������嵥�ļ�����
    homework course_work[100];//������ҵ��Ϣ������
    time exam_start_time;//���Կ�ʼʱ��
    time exam_end_time;//���Խ���ʱ��
    int exam_week;//����������
    location exam_loc;//���Եص�
};//����һ���γ��࣬�����γ̵���Ϣ
istream &read_homework(istream &is,homework &item)
{
    is >> item.workname >> item.flag;
    return is;
}//���ļ��е���ҵ���ƺͱ�ʶ����Ϣ������ҵ���������
istream &read_course(istream &is, course &item )
{
    is >> item.course_name //����γ�����
       >> item.class_loc.x >> item.class_loc.y >> item.class_loc.position >> item.class_loc.campus//����γ̵ص�����������
       >> item.start_time.weekday >> item.start_time.hour >> item.start_time.minute
       >> item.end_time.hour >> item.end_time.minute//����γ̵�ʱ����Ϣ
       >> item.teacher_name //�����ʦ����
       >> item.cur_section >> item.total_section//����γ̽���
       >> item.course_data_filename >> item.homework_filename//����γ����Ϻ���ҵ���嵥����
       >> item.course_group //����γ�Ⱥ
       >> item.exam_week >> item.exam_start_time.weekday >> item.exam_start_time.hour >> item.exam_start_time.minute
       >> item.exam_end_time.hour >> item.exam_end_time.minute//���뿼��ʱ��
       >> item.exam_loc.x >> item.exam_loc.y >> item.exam_loc.position;//���뿼�Եص�����������
    item.homework_filename += ".txt"; 
	ifstream in;
    in.open(item.homework_filename.c_str());
    int i = 0;
    while(read_homework(in,item.course_work[i]))
    {
        i++;
    }
    item.course_work[i].flag = -1;//����ҵ�嵥�е���Ϣ������ҵ�Ķ���������
    return is;
}//����γ̵ĸ�����Ϣ
ostream &print_course(ostream &os,course &item)
{
    os << "�γ����ƣ�" << item.course_name << "\t�Ͽεص㣺" << item.class_loc.position << "\t�Ͽ�У����" << item.class_loc.campus
       << "\t�Ͽ�ʱ�䣺" << item.start_time.weekday << " " << item.start_time.hour<< ":" << item.start_time.minute<< "-"
       << item.end_time.hour <<":"<< item.end_time.minute
       << "\t��ʦ������" << item.teacher_name << "\t��ǰ������" << item.cur_section << "\t�γ��ܽ�����" << item.total_section
       << "\t�γ�Ⱥ��" << item.course_group 
       << "\t����ʱ�䣺" <<item.exam_week << "��\t" << item.exam_start_time.weekday << " " << item.exam_start_time.hour << ":" << item.exam_start_time.minute
       << "-" << item.exam_end_time.hour << ":" << item.exam_end_time.minute
       << "\t���Եص㣺" << item.exam_loc.position; 
    int i = 0;
    while(item.course_work[i].flag!=-1)
    {
        os << "��ҵ���ƣ�" << item.course_work[i].workname << " "
           << "�ύ״̬��";
        if(item.course_work[i].flag==1)
        {
            os << "�ѽ�\t";
        }
        else
        {
            os << "δ��\t";
        }
        i++;
    }//����ҵ���ύ������
    os << endl; 
    return os;
}//����γ̵ĸ�����Ϣ
int main()
{
    course item;
    ifstream in("courseinformation.txt");
    read_course(in, item);
    in.close();
    print_course(cout, item);
}
