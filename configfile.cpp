#include "configfile.h"
#include <QTextStream>

ConfigFile::ConfigFile(QString fileName, QObject *parent) : QObject(parent)
{
    this->m_fileName = fileName;
}

bool ConfigFile::open(){
    QFile file(m_fileName);
    if(!file.exists()){
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return false;
    }
    m_list = new QList<CfgData*>;
    QTextStream in(&file);
    while(!in.atEnd()){
        QString ln = in.readLine();
        QStringList lnt = ln.split("÷");
        CfgData *cfg = new CfgData(lnt.at(0),lnt.at(1));
        m_list->append(cfg);
    }
    file.close();
    return true;
}

int ConfigFile::cfgCount(){
    return m_list->length();
}

CfgData* ConfigFile::getCfgAt(int pos){
    return m_list->at(pos);
}

bool ConfigFile::save(){
    QFile file(m_fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        return false;
    }
    QTextStream out(&file);
    for(int i=0;i<m_list->length();i++){
        out<<m_list->at(i)->name()+"÷"+m_list->at(i)->value()+"\n";
    }
    file.close();
    return true;
}

bool ConfigFile::add(CfgData* cfg, int pos){
    if(pos<-1||pos>m_list->length()||findByName(cfg->name())==0){
        return false;
    }else{
        if(pos==-1){
            m_list->append(cfg);
        }else{
            m_list->insert(pos,cfg);
        }
    }
    return true;
}

void ConfigFile::qdebug(){
    for(int i=0;i<m_list->length();i++){
        qDebug(m_list->at(i)->name().toLatin1()+":"+m_list->at(i)->value().toLatin1());
    }
}

CfgData* ConfigFile::findByName(QString cfgName){
    CfgData *cfg = 0;
    for(int i=0;i<m_list->length();i++){
        if(m_list->at(i)->name()==cfgName){
            return m_list->at(i);
        }
    }
    return cfg;
}

void ConfigFile::createOrModify(QString cfgName, QString cfgValue){
    CfgData *cfg = findByName(cfgName);
    if(!cfg==0){
        cfg->setValue(cfgValue);
    }else{
        m_list->append(new CfgData(cfgName,cfgValue));
    }
}

