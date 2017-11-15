#ifndef CFGDATA_H
#define CFGDATA_H

#include <QObject>

#include "icdelib_global.h"

class ICDELIBSHARED_EXPORT CfgData : public QObject
{
    Q_OBJECT
public:
    explicit CfgData(QString name, QString value,QObject *parent = 0);
    void setName(QString name);
    void setValue(QString value);
    QString name();
    QString value();
private:
    QString m_name;
    QString m_value;
};

#endif // CFGDATA_H
