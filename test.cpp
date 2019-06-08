/* 
1.测试线程之间的数据传递
2.创建一个父线程，读取文件，并将文件保存到pipe中
3.创建一个子线程，从pipe中接收文件，并保存到磁盘中 
*/
#include <mutex>
#include <stdlib.h>

class Read{
    Read();
    ~Read();
private:
    int _fd_rd;  //读取文件的fd
    char * _buffer_rd;   //存放读取文件的buffer 
    pthread_t _Save;  //子线程，用于存储文件
    std::mutex _mutex;   //锁
public:
    int read_file();
 };