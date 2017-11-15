#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QObject>
#include "cfgdata.h"
#include <QFile>

#include "icdelib_global.h"

class ICDELIBSHARED_EXPORT ConfigFile : public QObject
{
    Q_OBJECT

public:
    explicit ConfigFile(QString fileName, QObject *parent = 0);
    bool open();
    bool save();
    int cfgCount();
    bool add(CfgData* cfg, int pos = -1);
    CfgData* getCfgAt(int pos);
    void qdebug();
    CfgData* findByName(QString cfgName);
    void createOrModify(QString cfgName, QString cfgValue);

private:
    QString m_fileName;
    QList<CfgData*> *m_list;
};

#endif // CONFIGFILE_H
