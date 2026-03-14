#include "myqobject.h"

MyQObject::MyQObject(QString objectName, QObject *parent)
    : QObject{parent}
{
    this->setObjectName(objectName);
    qInfo() << this->objectName() << "created";
    // QObject::connect(this, &MyQObject::informationChanged, this, &MyQObject::on_informationChanged);
    // QObject::connect(this, &MyQObject::valueChanged, this, &MyQObject::on_valueChanged);
}

// void MyQObject::on_informationChanged()
// {
//     qInfo() << "m_information member variable: " << m_information;
// }

// void MyQObject::on_valueChanged()
// {
//     qInfo() << "m_value member variable: " << m_value;
// }

// int MyQObject::getValue() const
// {
//     return m_value;
// }

// void MyQObject::setValue(int newValue)
// {
//     if (m_value == newValue)
//         return;
//     m_value = newValue;
//     emit valueChanged();
// }

MyQObject::~MyQObject()
{
    qInfo() << this->objectName() << "destroyed";
}
