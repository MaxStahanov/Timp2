#include "ceaser.h"
#include "replace.h"
#include <iostream>
#include <string>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TextTestRunner.h>

using namespace std;

class CipherTest:public CppUnit::TestFixture
{
private:
 Ceaser * ceaser;
 Replace * replace;

public:
 void setUp()
 {
   this->ceaser = new Ceaser(4,string("Break my boring yellow brick"));
   this->replace = new Replace(string("Road so far"),string("zxcvbnmlkjhgfdsaqwertyuiop"));
 }
 void tearDown()
 {
   delete ceaser;
   delete replace;
 }
 void testVoidString() // Тест на нулевую строку корней
 {
   CPPUNIT_ASSERT_THROW_MESSAGE("Задана нулевая строка", Ceaser(4,string("")),CeaserException);
   CPPUNIT_ASSERT_THROW_MESSAGE("Задана нулевая строка", Replace(string(""),string("zxcvbnmlkjhgfdsaqwertyuiop")), ReplaceException);
 }
 void testLessKey() // Тест на ключ
 {
   CPPUNIT_ASSERT_THROW_MESSAGE("Ключ не равен 26 символам ", Replace(string("I wanna have perfect body, i wanna have perfect soul"),string("zxcvbnmlkjh")), ReplaceException );
   CPPUNIT_ASSERT_THROW_MESSAGE("Вырожденный ключ",Ceaser(0,string("Have u ever been in your inner hell?")),CeaserException);
 }
 void Dota2()
 {
   CPPUNIT_ASSERT_NO_THROW(this->ceaser);
   CPPUNIT_ASSERT_NO_THROW(this->replace);
 }
};

int main(void)
{

  CppUnit::TestSuite* suite = new CppUnit::TestSuite("CipherTest");

  suite->addTest(new CppUnit::TestCaller<CipherTest>
  ("testVoidString", &CipherTest::testVoidString ));

  suite->addTest(new CppUnit::TestCaller<CipherTest>
  ("testLessKey", &CipherTest::testLessKey ));

  suite->addTest(new CppUnit::TestCaller<CipherTest>
  ("Dota2", &CipherTest::Dota2 ));

  CppUnit::TextTestRunner runner;
  runner.addTest(suite);
  runner.run();
  return 0;

}
