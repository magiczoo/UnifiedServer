
#include <QString>
#include <QtTest>

#include "utils/ByteArray.h"

class ByteArrayTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testCase1();
};

void ByteArrayTest::testCase1()
{
    ByteArray* a= new ByteArray();
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ByteArrayTest)

#include "tst_ByteArray.moc"
