#ifndef NETDEFINEDOBJECTPROPERTY_H
#define NETDEFINEDOBJECTPROPERTY_H

#include <string>

class NetDefinedObjectProperty
{
public:
    NetDefinedObjectProperty();

    int id;//���ڸ��������е�id
    std::string name;//��������
    std::string type;//������������ ����Ϊ�Զ����������
    std::string defaultValue;//Ĭ��ֵ ���δ���� ����Ĭ��Ϊ0  �ַ���Ĭ��Ϊ"" ����Ĭ��Ϊ0��1970��1��1��0��0�֣�
    std::string inType;//���typeΪ���� ���ʾ��ǰ�����е����������ַ���
};

#endif // NETDEFINEDOBJECTPROPERTY_H
