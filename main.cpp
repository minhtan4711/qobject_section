#include <QCoreApplication>
#include <QDebug>
#include <QMetaProperty>
#include <QMetaObject>
#include "myqobject.h"
#include "connection_type.h"

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

    // MyQObject *grandParent = new MyQObject("Grand parent");

    // MyQObject *parent = new MyQObject("Parent", grandParent);

    // MyQObject *child1 = new MyQObject("child 1", parent);

    // MyQObject *child2 = new MyQObject("child 2", parent);

    // MyQObject *child3 = new MyQObject("child 3");

    // child3->setParent(parent);

    // delete grandParent;

    // 1. CHUẨN BỊ BỐI CẢNH
    QThread::currentThread()->setObjectName("Main Thread");
    QThread thread;
    thread.setObjectName("Separate Thread");

    // 2. KHỞI TẠO ĐỐI TƯỢNG (Dùng 'new' nên cần quản lý bộ nhớ)
    ConnectionType *source = new ConnectionType(nullptr, "source");
    ConnectionType *destination = new ConnectionType(nullptr, "destination");

    // 3. THIẾT LẬP "DI CHÚC" (Dọn dẹp tự động ngay sau khi tạo)
    // Gom nhóm các lệnh quản lý vòng đời vào một chỗ để dễ kiểm soát
    QObject::connect(&thread, &QThread::finished, source,      &QObject::deleteLater);
    QObject::connect(&thread, &QThread::finished, destination, &QObject::deleteLater);

    // 4. CẤU HÌNH ĐA LUỒNG & KẾT NỐI LOGIC
    destination->moveToThread(&thread); // Di chuyển 'destination' sang luồng mới

    // Nối dây giữa 2 đối tượng (Dùng BlockingQueued vì chúng khác luồng)
    QObject::connect(source, &ConnectionType::event,
                     destination, &ConnectionType::onEvent,
                     Qt::BlockingQueuedConnection);

    // 5. BẮT ĐẦU VẬN HÀNH
    thread.start();

    qInfo() << "\nEmitting signal event() from" << QThread::currentThread();
    emit source->event(); // Main Thread sẽ đứng đợi ở đây cho đến khi bên kia xong

    // 6. KẾT THÚC (Dừng luồng an toàn)
    thread.quit();
    thread.wait(); // Chờ luồng tắt hẳn để kích hoạt tín hiệu 'finished' đã nối ở bước 3

    return a.exec();
}
