//
// Created by Administrator on 2020/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <assert.h>
#include <iostream>

using namespace std;

void *mythread(void *args) {
    printf("%s\n", (char *) args);
    return nullptr;
}

typedef struct Hello {
    int a;
    int b;
} Hello;

/**
 *   ���������Ĵ��벻�����ݳ�����������(��Ϊ�ڴ�ֵ�����ź�����ִ����϶������ͷ�)
    һ���ⲿʹ�øò����ᵼ��δ֪�Ĵ���!!

    ����ʹ������
 * @return
 */
Hello *test1() {

    Hello h;
    h.a = 10;
    h.b = 20;
    return &h;
}

/**
 * �Ƽ����ַ���,ֱ���ڶ��з����ڴ�,������Ϊ��������
 * @return
 */
Hello *test2() {
    auto *hello = static_cast<Hello *>(malloc(sizeof(Hello)));
    hello->b = 10;
    hello->a = 10;
    return hello;
}

int main() {

    // Hello *hello = test1();
    // ����,��Ϊhello�Ѿ����ͷ���!! �Ͻ�ʹ�ô˷�ʽ!!!
    //cout << hello->a << "|||" << hello->b << endl;

    // ��ȷʹ�÷�ʽ,ʹ�ö��Ϸ���
    Hello *hello2 = test2();
    cout << hello2->a << "|" << hello2->b << endl;


    return 0;
}