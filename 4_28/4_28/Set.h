#define _CRT_SECURE_NO_WARNINGS

const int MAXLENGTH = 100;
struct set
{
	int data[MAXLENGTH];  //�ʼ�ļ��ϣ����Գ�ʼ����Ҳ���Բ���ʼ����
	unsigned count;  //count�Ǽ���Ԫ�صĸ���������ͬInitialize������ϣ��ɳ�ʼ����0 
};

void Initialize(set* pset);  //��ʼ�����ϣ�����count���0������data�����������ı�
void Add(int elem, set* pset);   //���Ԫ�ص����ϣ�����ԭ���ǿռ�
void Remove(int elem, set* pset);  //ɾ��ĳһԪ�أ������һ��Ԫ�طŵ���λ�ã��ٽ�����Ԫ�ظ���-1
int Isin(int elem, set* pset);