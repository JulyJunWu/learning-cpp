#include<iostream>
#include <thread>

#include "winsock2.h"

#pragma comment(lib, "ws2_32.lib")

using namespace std;
/**
 * 处理socket数据
 * @param clientSocket
 */
void loopRead(SOCKET clientSocket) {
    char receiveBuff[BUFSIZ];
    int retVal;
    while (1) {
        //进行阻塞,返回读取的字节数
        retVal = recv(clientSocket, receiveBuff, BUFSIZ, 0);
        if (!retVal) {
            thread::id main_thread = this_thread::get_id();
            cout << "线程退出" << main_thread << endl;
            break;
        }
        cout << "接收自客户端数据：长度:" << retVal << " | 数据:" << receiveBuff << endl;
    }
}

int main() {
    cout << "开始" << endl;
    int retVal;
    WORD socketVersion = MAKEWORD(2, 2);
    WSADATA wsd;
    if (WSAStartup(socketVersion, &wsd) != 0) {
        cout << "绑定Socket库失败" << endl;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cout << "创建服务器套接字失败" << endl;
        WSACleanup();
        return -1;
    }

    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8889);
    serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
    retVal = bind(serverSocket, (SOCKADDR *) &serverAddr, sizeof(SOCKADDR_IN));
    if (retVal == SOCKET_ERROR) {
        cout << "套接字绑定失败" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }
    //backlog : 指定等待队列的大小
    retVal = listen(serverSocket, 2);
    if (retVal == SOCKET_ERROR) {
        cout << "套接字监听失败" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    SOCKET clientSocket;
    SOCKADDR_IN clientAddr;
    int clientAddrLen = sizeof(clientAddr);
    while (true) {
        // 进行阻塞,等待客户端的连接
        clientSocket = accept(serverSocket, (SOCKADDR *) &clientAddr, &clientAddrLen);
        cout << "新增客户端" << clientSocket << endl;
        //单独启动一个线程对应一个socket,也就是阻塞IO
        thread t(loopRead, clientSocket);
        t.detach();
    }
}
