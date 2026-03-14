#include <QCoreApplication>
#include <QDebug>
#include <QMetaProperty>
#include <QMetaObject>
#include "myqobject.h"



// #include "myqobject1.h"
// #include "myqobject2.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // MyQObject1 *object1 = new MyQObject1();
    // MyQObject2 *object2 = new MyQObject2();

    // QObject::connect(object1, &MyQObject1::mySignal, object1, &MyQObject1::mySlot1);
    // QObject::connect(object1, &MyQObject1::mySignal, object2, &MyQObject2::mySlot2);

    // emit object1->mySignal("Hello World!");

    // QObject::disconnect(object1, &MyQObject1::mySignal, object1, &MyQObject1::mySlot1);
    // QObject::disconnect(object1, &MyQObject1::mySignal, object2, &MyQObject2::mySlot2);

    // emit object1->mySignal("Hello World again!");


    // MyQObject *object = new MyQObject();
    // object->setProperty("information", "Hello World!");
    // object->setProperty("value", 50);

    // qInfo() << "Information property: " << object->property("information");
    // qInfo() << "Value property: " << object->property("value");


    // MyQObject *object = new MyQObject();
    // qInfo() << "--------------- OBJECT INFO ---------------";
    // qInfo() << "Class name: " << object->metaObject()->className();
    // qInfo() << "Super class name: " << object->metaObject()->superClass()->className();
    // qInfo() << "Property count: " << object->metaObject()->propertyCount();
    // qInfo() << "Method count: " << object->metaObject()->methodCount();
    // qInfo() << "Enumerator count: " << object->metaObject()->enumeratorCount();

    // qInfo() << "--------------- PROPERTIES ---------------";
    // const QMetaObject* metaObject = object->metaObject();
    // for (int i = 0; i < metaObject->propertyCount(); i++)
    //     qInfo() << "Property " << i << ":" << metaObject->property(i).name();

    MyQObject *grandParent = new MyQObject("Grand parent");

    MyQObject *parent = new MyQObject("Parent", grandParent);

    MyQObject *child1 = new MyQObject("child 1", parent);

    MyQObject *child2 = new MyQObject("child 2", parent);

    MyQObject *child3 = new MyQObject("child 3");

    child3->setParent(parent);

    delete grandParent;


    return a.exec();
}
