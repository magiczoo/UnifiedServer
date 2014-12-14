#ifndef NETDEFINEDOBJECTPROPERTY_H
#define NETDEFINEDOBJECTPROPERTY_H

#include <string>

class NetDefinedObjectProperty
{
public:
    NetDefinedObjectProperty();

    int id;//所在父级数组中的id
    std::string name;//属性名称
    std::string type;//属性数据类型 可以为自定义对象类型
    std::string defaultValue;//默认值 如果未传递 数字默认为0  字符串默认为"" 日期默认为0（1970年1月1号0点0分）
    std::string inType;//如果type为数组 则表示当前数组中的数据类型字符串
};

#endif // NETDEFINEDOBJECTPROPERTY_H
