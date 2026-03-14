#ifndef MYQOBJECT_H
#define MYQOBJECT_H

#include <QObject>
#include <QDebug>

class MyQObject : public QObject
{
    Q_OBJECT
    // Q_PROPERTY(QString information MEMBER m_information NOTIFY informationChanged)
    // Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)

    Q_PROPERTY(QString myValue1 MEMBER m_myValue1 NOTIFY myValue1Changed)
    Q_PROPERTY(QString myValue2 MEMBER m_myValue2 NOTIFY myValue2Changed)
public:
    explicit MyQObject(QString objectName, QObject *parent = nullptr);
    ~MyQObject();

    enum MyEnum {
        Value1,
        Value2,
        Value3
    }; Q_ENUM(MyEnum);

    // int getValue() const;
    // void setValue(int newValue);

signals:
    // void informationChanged();

    // void valueChanged();

    void myValue1Changed();

    void myValue2Changed();

public slots:
    // void on_informationChanged();
    // void on_valueChanged();

private:
    // QString m_information;
    // int m_value;
    QString m_myValue1;
    QString m_myValue2;
};

#endif // MYQOBJECT_H
