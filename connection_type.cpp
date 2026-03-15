#include "connection_type.h"

ConnectionType::ConnectionType(QObject *parent, const QString &name) : QObject{parent}
{
    setObjectName(name);
    qInfo() << this << "created on" << QThread::currentThread();
}

void ConnectionType::onEvent()
{
    qInfo() << "Executing slot onEvent() on" << QThread::currentThread();
}
