// ModuleTest.cpp

#include <Module/Module.h>
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <gtest/gtest.h>

using namespace START_APP_NAMESPACE;

class TestModule1 : public Module {
public:
    TestModule1(ThreadingBehavior threadingBehavior = ThreadingBehavior::RunInNewThread, QObject *parent = nullptr)
        : Module(threadingBehavior, parent) {}

protected:
    void run() override {
        qDebug() << "TestModule1 running in thread:" << QThread::currentThreadId();
        // Do some work...
    }
};

class TestModule2 : public Module {
public:
    TestModule2(ThreadingBehavior threadingBehavior = ThreadingBehavior::RunInNewThread, QObject *parent = nullptr)
        : Module(threadingBehavior, parent) {}

protected:
    void run() override {
        qDebug() << "TestModule2 running in thread:" << QThread::currentThreadId();
        // Do some work...
    }
};

// Test fixture for Module tests
class ModuleTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up the environment before running each test
    }

    void TearDown() override {
        // Clean up the environment after running each test
    }
};

// Test that thread IDs of two instances of TestModule running in new threads are not equal
TEST_F(ModuleTest, ThreadIdsNotEqual) {
    try {
        TestModule1 module1;
        TestModule2 module2;

        // Start modules in new threads
        module1.start();
        module2.start();

        // Ensure that thread IDs are not equal
        ASSERT_NE(QThread::currentThreadId(), module1.thread()->currentThreadId());
        ASSERT_NE(QThread::currentThreadId(), module2.thread()->currentThreadId());
        ASSERT_NE(module1.thread()->currentThreadId(), module2.thread()->currentThreadId());
    } catch ( const PimplException &ex ) {
        qDebug() << ex.whatQStr();
    } catch ( ... ) {
        qDebug() << "Other exception";
    }
}
