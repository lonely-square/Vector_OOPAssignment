// testString.cpp		
#include "MyString.h"
#include <fstream>
using namespace std;


void test1();
void test2();
void test3();
void test4();

int testString()
{   int n;
    cout << "\n=========================================================" << endl;
        cout<<  "����1���������ܲ���"       <<endl;
		cout<<  "����2���쳣�������"       <<endl;
		cout<<  "����3��string,intת������" <<endl;
		cout<<  "����4���ļ���д����" <<endl;
		cout<<  "����5���˳�" <<endl;
        cout << "\n=========================================================" << endl;
	while(cin>>n)
	{
		system("cls");
        cout << "\n=========================================================" << endl;
        cout<<  "����1���������ܲ���"       <<endl;
		cout<<  "����2���쳣�������"       <<endl;
		cout<<  "����3��string,intת������" <<endl;
		cout<<  "����4���ļ���д����" <<endl;
		cout<<  "����5���˳�" <<endl;
        cout << "\n=========================================================" << endl;
		if (n==5) break;
		switch(n){
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
		}
	}
	return 0;
}

void test2()        //�쳣�������
{
	String str1="world.", str2, str3;
	int n;
	char c;
	
	cout << "\"" << str1 << "\"" << endl;
	cout<<"�����滻�ڼ����ַ���"<<endl;
	cin>>n;
	cout<<"������ʲô�ַ������"<<endl;
	cin>>c;
	
	str2 = str1;
	try{
	str2[n-1] = c;
	cout << "\"" << str2 << "\"" << endl;
	}
	catch(int)
	{
			cout<<"��������"<<endl;
	}
}

void test1()          //�������ܲ���
{
	String str1="world.", str2;
	cout<<"���캯������"<<endl;
	cout <<"�ַ�������str1:"<<"\"" << str1 << "\"" << endl;
	cout <<"Ĭ�Ϲ���str2:"<< "\"" << str2 << "\"" << endl;
	cout<<endl;
    
	cout<<"��������"<<endl;
    String str5(str1);
	cout << "��str2������str5��str5��"<<"\"" << str5 << "\"" << endl;
	cout<<endl;
	
	cout<<"swap��������"<< str2<<endl;
	str2.swap(str1);
	cout << "str1��str2������"<<endl;
	cout<<"str2:\"" << str2 << "\"" << endl;
	cout<<"str1:\"" << str1 << "\"" << endl;
	cout<<endl;
	
	str1="world.";
	cout<<"str1��Ϊ��"<<str1<<endl;
	cout<<"insert��������"<<endl;
	str1="world.";
	str1.insert(0,"hello ");
	cout << "��hello����str1ǰ��\"" << str1 << "\"" << endl;
	cout<<endl;

	cout<<"substr��������"<<endl;
	cout<<"str1��Ϊ����λ��ȡ��λ��"<<str1.substr(2,2)<<endl;
	cout<<endl;
	
	cout<<"find��������:����str1��o��λ��"<<endl;
	String o="o";
	cout<<"o�ڵ�"<<str1.find(o)<<"��λ��"<<endl;
	cout<<endl;
	
	cout<<"length��������"<<endl;
	cout<<"str1�ĳ���Ϊ"<<str1.length()<<endl;
	cout<<endl;
	
	cout<<"c_str��������"<<endl;
	cout<<"str1ת��Ϊc�ַ���"<<str1.c_str()<<endl;
	cout<<endl;
	
	cout << "\"" << str1 << "\"" << endl;
	cout<<"getline�������ԣ�"<<endl;
	cout << "Input a string: "<<endl;
	fflush(stdin);       //cin.sync();
	getline(cin,str1,80);
	//cout<<str1<<endl;
	cout << "\"" << str1 << "\"" << endl;
	
	//getline(cin,str1,4);
	//cout << "\"" << str1 << "\"" << endl;
	getchar();
}

void test3()    //��ȡ����
{
	int pos,n,k;
	String str1;
	cout<<"������ӣ�"<<endl;
	cin>>str1;
	cout<<"����λ�ã�"<<endl;
	cin>>pos;
	cout<<"����λ����"<<endl;
	cin>>n;
	try{
		k=str1.stoi(pos,n);
		cout<<"String��תint�ͣ�"<<k<<endl;
	}
	catch(int)
	{
		cout<<"û�ҵ����֣�������"<<endl;
	}
	cout<<endl;
	cout<< "����123תString��:"<< itos(123)<<endl;
}

void test4()
{
	String str1 = "Hello", str2 = str1, str3;
			// ת������		�������� 	Ĭ�Ϲ���
	cout << "ԭʼ���ݣ�˫������������ӵģ���" << endl;
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;
	
	str3 = str2;				// ��ֵ����
	str1 = "C++ program.";
	str2 = str3 + ", world!";	// ƴ������
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n������д���ļ� string.txt ��..." << endl;
	ofstream outfile("string.txt");
	outfile << str1 << '\n'
			<< str2 << '\n'
			<< str3 << endl;
	outfile.close();

	cout << "\n�����������ݣ����������ȵ�0��..." << endl;
	str1.resize(0);
	str2.resize(0);
	str3.resize(0);
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n���ļ� string.txt �ж�ȡ�����ݣ�" << endl;
	ifstream infile("string.txt");
//	infile >> str1 >> str2 >> str3;		// �Կհ��ַ���Ϊ������ķָ���
	getline(infile, str1, 100);			// �����У��ɺ��հ��ַ���
	getline(infile, str2, 100);
	getline(infile, str3, 100);
	infile.close();
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;
	
}