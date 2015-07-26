/*
	$Id: httpdownload.h, v1.0.0, 2011.6.28, YellowBug $
	$@@: http下载 
*/
#ifndef PENQ_HTTP_DOWNLOAD_H_
#define PENQ_HTTP_DOWNLOAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#if defined(__GNUC__)
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#define PATH_SPLIT			'/'
typedef int	HSOCKET;
#define closesocket(s)		close(s)
#elif defined(_WIN32)
#include <windows.h>
#include <winsock2.h>
#define PATH_SPLIT			'//'	
typedef SOCKET HSOCKET;
#endif

#define DEF_HTTP_PORT			80
#define HTTP_MAX_PATH			260
#define HTTP_MAX_REQUESTHEAD	1024
#define HTTP_MAX_RESPONSEHEAD	2048
#define HTTP_DOWN_PERSIZE		128	
#define HTTP_FLUSH_BLOCK		1024

/*
	$@@ 下载状态
	$@ HDL_URLERR: 提供的url非法
	$@ HDL_SERVERFAL: 根据host地址无法找到主机 
	$@ HDL_TIMEOUT: 连接下载地址超时
	$@ HDL_READYOK: 连接下载地址成功,准备下载
	$@ HDL_DOWNING: 正在下载
	$@ HDL_DISCONN: 断开连接了
	$@ HDL_FINISH: 下载完成
*/
enum 
{
	HDL_URLERR = 0xe0,
	HDL_SERVERFAL = 0xe1,
	HDL_SOCKFAL = 0xe2,
	HDL_SNDREQERR = 0xe3,
	HDL_SERVERERR = 0xe4,
	HDL_CRLOCFILEFAL = 0xe5,
	HDL_TIMEOUT = 0x100,
	HDL_NORESPONSE = 0x101,
	HDL_READYOK = 0x104,
	HDL_DOWNING = 0x105,
	HDL_DISCONN = 0x106,
	HDL_FINISH = 0x107
};

/*
	$@@ 下载回调函数,主要用于监听下载过程
	$@ 第一个参数: 下载标识符号(上面枚举中的值)
	$@ 第二个参数: 需要下载的总字节数
	$@ 第三个参数: 已经下载的总字节数
	$@ 第四个参数: 距离上一次下载的时间戳(毫秒)
	$@ 返回值: 下次下载的字节数(0: 表示默认值, 小于0则下载中断, 大于0则位下次下载指定的字节)
*/
typedef int (*HTTPDOWNLOAD_CALLBACK)(int, unsigned int, unsigned int, unsigned int);

/*
	$@@ 通过指定的url下载资源
	$@ url: 下载资源地址
	$@ filepath: 存储在本地的路径(如果为NULL则存储在当前目录)
	$@ filename: 存储的文件名(如果为NULL则位url中分析的文件名)
	$@ http_func: 下载过程监听函数(如果为NULL则不监听下载过程)
*/
void pq_http_download(const char *url, const char *filepath, const char *filename, HTTPDOWNLOAD_CALLBACK http_func);
#endif /* #ifndef PENQ_HTTP_DOWNLOAD_H_ */
/* END */
