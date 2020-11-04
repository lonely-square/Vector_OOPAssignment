// Vector.h
// ע�⣺��ģ��̳��У���Ҫ�������ࣨ���ࣩ����this->����־�ӻ��ࣨ���ࣩ�м̳й��������ݳ�Ա�ͳ�Ա����
// ��Ȼ����ִ�����Ϣ��(if you use `-fpermissive', G++ will accept your code, but allowing the use of an undeclared name is deprecated)
#ifndef VECTOR_H
#define VECTOR_H

#include "Vec.h"

template <typename T> class Vector : public VECTOR<T>
{
public:
	Vector(int size=0, const T *x=NULL);
	Vector(const Vector a,int pos,int n);

	void Input(istream &in);
	void Output(ostream &out) const;
	void resize(int size);

	int length() const;
	void swap(Vector<T> &Str);
	Vector<T> subvector(int pos,int n) const;
	
	template <typename TYPE> friend Vector<TYPE> operator+(const Vector<TYPE> &v1, const Vector<TYPE> &v2) throw(double);
	template <typename TYPE> friend Vector<TYPE> operator-(const Vector<TYPE> &v1, const Vector<TYPE> &v2) throw(double);
	template <typename TYPE> friend Vector<TYPE> operator*(const T &x, const Vector<TYPE> &v);
	template <typename TYPE> friend Vector<TYPE> operator*(const Vector<TYPE> &v, const T &x);
	Vector<T> & operator+=(const Vector<T> &v) throw(double);
	Vector<T> & operator-=(const Vector<T> &v) throw(double);
	Vector<T> & operator*=(const T &x);
	template <typename TYPE> friend bool operator==(const Vector<TYPE>& v1, const Vector<TYPE>& v2);
	template <typename TYPE> friend bool operator!=(const Vector<TYPE>& v1, const Vector<TYPE>& v2);
};

template <typename T>
Vector<T>::Vector(int size, const T *x) : VECTOR<T>(size, x)		// ���캯��
{
}

template <typename T>
Vector<T>::Vector(const Vector a,int pos,int n) : VECTOR<T>(a,pos,n)	// ���캯��
{
}

template <typename T>
void Vector<T>::Output(ostream &out) const
{
	if(this->num==0)
		out << "()";
	else
	{
		out << "(" << this->p[0];
		for(int i=1; i<this->num; i++)
			out << ", " << this->p[i];
		out << ")";
	}
}

template <typename T>
void Vector<T>::Input(istream &in)	// �����Զ���չ���������Ĺ���
{
	const int M=1024, N = 1;//1024;	// Nȡ��Сֵ1��Ϊ�˵��ԣ�ʵ��ʹ��ʱȡ1024
	Vector<T> temp;
	char str[M], ch;				// ch��ʼ��Ϊһ����')'�ַ�����
	T buffer[N];
	int i, j, k;

	in.getline(str, M, '(');		// ���˵�'('��֮ǰ�������ַ�
	while(true)						// ���˵���Բ����֮��Ŀհ��ַ�
	{
		ch = in.peek();				// ͵����һ���ַ������Ƿ�Ϊ�հ��ַ�
		if(ch==' ' || ch=='\t' || ch=='\n' || ch=='\r')
			in.get(ch);				// ���ǿհ��ַ�������˵�������ȡ���ã�
		else
			break;					// ֱ�������ǿհ��ַ���������whileѭ��
	}

	if(in.peek()==')')				// ͵����һ���ַ�������')'
	{
		this->resize(0);			// ���������ά�����ó� 0 ά
		return;						// �˳�������������Ϊ 0 ά����
	}

	for(k=0; ch!=')'; k++)
	{
		for(i=0; i<N && ch!=')'; i++)
			in >> buffer[i] >> ch;
		temp.resize(k*N+i);			// ������resize������"����������ԭ������"�Ĺ���
		for(j=0; j<i; j++)
			temp[k*N+j] = buffer[j];// �����˷����������
	}
	*this = temp;					// �����˸�ֵ��������ֵ���㣩
}

template <typename T>
Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2) throw(double)
{
	if(v1.getsize() != v2.getsize())
		throw -1.0;					// ��������ʱ"һ����֮"����"ì���Ͻ�"��"�ϼ�����"���鴦��
	Vector<T> result(v1);
	for(int i=v1.getsize()-1; i>=0; i--)// �����ε���v1.getsize()����
		result[i] += v2[i];			// �����˷����������
	return result;
}

template <typename T>
Vector<T> operator-(const Vector<T> &v1, const Vector<T> &v2) throw(double)
{
	if(v1.getsize() != v2.getsize())
		throw -1.0;					// ��������ʱ"һ����֮"����"ì���Ͻ�"��"�ϼ�����"���鴦��
	Vector<T> result(v1);
	for(int i=v1.getsize()-1; i>=0; i--)// �����ε���v1.getsize()����
		result[i] -= v2[i];			// �����˷����������
	return result;
}

template <typename T>
Vector<T> operator*(const T &x, const Vector<T> &v)
{
	Vector<T> result(v);
	for(int i=v.getsize()-1; i>=0; i--)
		result[i] = x*v[i];
	return result;
}

template <typename T>
Vector<T> operator*(const Vector<T> &v, const T &x)
{
	return x*v;
}

template <typename T>
Vector<T> & Vector<T>::operator+=(const Vector<T> &v) throw(double)
{
	return *this = *this + v;
}

template <typename T>
Vector<T> & Vector<T>::operator-=(const Vector<T> &v) throw(double)
{
	return *this = *this - v;
}

template <typename T>
Vector<T> & Vector<T>::operator*=(const T &x)
{
	return *this = x * (*this);
}

//Done
template <typename T>
bool operator==(const Vector<T>& v1, const Vector<T>& v2)
{
	int i, n1 = v1.getsize(), n2 = v2.getsize();
	for (i = 0; i < n1 && i < n2 && v1[i] == v2[i]; i++)
		;
	if (i < n1 || i < n2)
		return false;
	else
		return true;
}

template <typename T>
bool operator!=(const Vector<T>& v1, const Vector<T>& v2)
{
	return !(v1 == v2);
}

template <typename T>
void Vector<T>::resize(int size)			// ָ��������ά������������ԭ�е����ݣ�
{
	if (size < 0 || size == this->num)
		return;
	else if (size == 0)
	{
		if (this->p != NULL) delete[] this->p;
		this->p = NULL;
		this->num = 0;
	}
	else
	{
		T* temp = this->p;
		this->p = new T[size];
		for (int i = 0; i < size; i++)
			this->p[i] = (i < this->num) ? temp[i] : 0;	// ��������ԭ������
		this->num = size;
		delete[] temp;
	}
}

template <typename T>
int Vector<T>::length() const
{
	return this->getsize();			// �˴�����this->num����ΪString������ģ��
}

template <typename T>
 Vector<T> Vector<T>::subvector(int pos, int n) const
{
	Vector temp(*this, pos, n);
	return temp;
}

template <typename T>
void Vector<T>::swap(Vector<T> &Str)
{
	this->baes_swap(Str);
}

#endif
