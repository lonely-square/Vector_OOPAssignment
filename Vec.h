// Vec.h
#ifndef VEC_H
#define VEC_H
#include <iostream>
using namespace std;

template <typename T> class VECTOR			// ����������ģ�壨���������뽫��Ա������ʵ��ȫд��ͷ�ļ��У�
{
public:
	virtual ~VECTOR();						// �� �����������麯����
	VECTOR & operator=(const VECTOR &v);	// �� ��ֵ�����������ʵ���ֵ���㣩
	T & operator[](int index) const throw(int);
					// ��������������������÷��أ�������ֵ��;�±�Խ��ʱ�����쳣
	virtual void resize(int size) = 0;					// ����������ά������������ԭ�е����ݣ�

	virtual void Output(ostream &out) const = 0;// ���麯�����������������Ա����صĲ�����������ܶ�̬��
	virtual void Input(istream &in) = 0;		// ���麯�����Ա����صĲ�����������ܶ�̬��

protected:								// �ܱ����ģ��Ա�������ķ������ԣ�
	void baes_swap(VECTOR &Str);
	VECTOR(int size=0, const T *x=NULL);	// �� ���캯������Ĭ�ϵĹ��캯����ת�����캯����
	VECTOR(const VECTOR &Str, int pos, int n);
	VECTOR(const VECTOR &v);				// �� �������캯����ʵ��������죩
//	template <typename T2> int find(T2 &Str) const;				// ���Ҳ����� Str �ڱ����е�һ�γ��ֵ�λ��
//	template <typename T2> T2& substr(int pos, int n) const;
	int getsize() const;					// ��ȡ������ά����������Ա������
	int num;									// ������ά��
	T *p;										// ָ�루��sizeof(void*)�ֽڣ���4�ֽڣ�����Դ�ڶѿռ�
};

template <typename T>
VECTOR<T>::VECTOR(int size, const T *x)	// �� ���캯������Ĭ�ϵĹ��캯����ת�����캯����
{
	num = (size>0) ? size : 0;
	p = NULL;
	if(num>0)
	{
		p = new T[num];
		for(int i=0; i<num; i++)
			p[i] = (x==NULL)? 0 : x[i];
	}
}

template <typename T>
VECTOR<T>::VECTOR(const VECTOR &Str, int pos, int n)
{
	int i, m;
	m =Str.num;
	if(pos > m)
	{
		p = new T[1];
		p[0] = ' ';
		return;
	}
	if(m-pos < n) n = m-pos;
	if(n<0) n = 0;
	p = new T[n];
	for(i=0; i<n; i++)
		p[i] = Str.p[pos+i];
	num=n;
}
template <typename T>
VECTOR<T>::VECTOR(const VECTOR<T> &v)	// �� �������캯����ʵ��������죩
{
	num = 0;
	p = NULL;
	*this = v;
}

template <typename T>
VECTOR<T>::~VECTOR()						// �� �����������麯����
{
	num = 0;
	if(p!=NULL) delete [] p;
}

template <typename T>
VECTOR<T> & VECTOR<T>::operator=(const VECTOR<T> &v)// �� ��ֵ�����������ʵ���ֵ���㣩
{
	if(num!=v.num)
	{
		if(p!=NULL) delete [] p;
		p = new T[num=v.num];
	}
	for(int i=0; i<num; i++)
		p[i] = v.p[i];
	return *this;
}

template <typename T>
T & VECTOR<T>::operator[](int index) const throw(int)// ��������������������÷��أ�������ֵ��
{
	if(p==NULL)
		throw 0;							// ����ӵ��쳣
	if(index<0 || index>=num)
		throw -1;
	return p[index];
}

template <typename T>
int VECTOR<T>::getsize() const				// ��ȡ������ά����������Ա������
{
	return num;
}

template <typename T>
void VECTOR<T>::resize(int size)			// ָ��������ά������������ԭ�е����ݣ�
{
	if(size<0 || size==num)
		return;
	else if(size==0)
	{
		if(p!=NULL) delete [] p;
		p = NULL;
		num = 0;
	}
	else
	{
		T *temp = p;
		p = new T[size];
		for(int i=0; i<size; i++)
			p[i] = (i<num) ? temp[i] : 0;	// ��������ԭ������
		num = size;
		delete [] temp;	
	}
}

template <typename T>
ostream & operator<<(ostream &out, const VECTOR<T> &v)	// ��������Ԫ����
{
	v.Output(out);
	return out;
}

template <typename T>
istream & operator>>(istream &in, VECTOR<T> &v)			// ��������Ԫ����
{
	v.Input(in);
	return in;
}

/*template <typename T> 
template <typename T2>
int VECTOR<T>::find(T2 &Str) const
{
	int i, j, m, n, flag;
	m = getsize(Str.p);
	if (m > num) return -1;
	for (i = 0; i < num - m; i++)
	{
		flag = 1;
		for (j = 0; j < m; j++)
			if (p[i + j] != Str.p[j])
			{
				flag = 0;
				break;
			}
		if (flag == 1)
			return i;
	}
	return -1;
}*/

template <typename T> 
void VECTOR<T>::baes_swap(VECTOR<T> &Str)
{
	T *temp = Str.p;
	Str.p = p;
	p = temp;

	int aaa=num;
	num=Str.num;
	Str.num=aaa;
}


#endif
