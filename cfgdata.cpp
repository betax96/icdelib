#include "cfgdata.h"

CfgData::CfgData(QString name, QString value, QObject *parent) : QObject(parent)
{
    this->m_name = name;
    this->m_value = value;
}


void CfgData::setName(QString name){
    this->m_name = name;
}

void CfgData::setValue(QString value){
    this->m_value = value;
}

QString CfgData::name(){
    return this->m_name;
}

QString CfgData::value(){
    return this->m_value;
}
