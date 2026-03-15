#ifndef CONNECTION_TYPE_H
#define CONNECTION_TYPE_H

#include <QObject>
#include <QDebug>
#include <QThread>

class ConnectionType : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionType(QObject *parent = nullptr, const QString &name = QString());

signals:
    void event();

public slots:
    void onEvent();

};

#endif // CONNECTION_TYPE_H
