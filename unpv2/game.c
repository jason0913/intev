#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m_socket_id = -1;

/* 处理server的消息 */
int on_server_message(int length, const char* buffer)
{
	printf("Recieve Data From Server(%s)\n", buffer);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 6)
	{
		printf("Usage: ./%s server_ip server_port my_ip my_port my_id\n", argv[0]);
		return -1;
	}

	/* 获取输入参数 */
	in_addr_t server_ip = inet_addr(argv[1]);
	in_port_t server_port = htons(atoi(argv[2])); 
	in_addr_t my_ip = inet_addr(argv[3]);
	in_port_t my_port = htons(atoi(argv[4])); 
	int my_id = atoi(argv[5]);

	/* 创建socket */
	m_socket_id = socket(AF_INET, SOCK_STREAM, 0);
	if(m_socket_id < 0)
	{
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		return -1;
	}

	/* 设置socket选项，地址重复使用，防止程序非正常退出，下次启动时bind失败 */
	int is_reuse_addr = 1;
	setsockopt(m_socket_id, SOL_SOCKET, SO_REUSEADDR, (const char*)&is_reuse_addr, sizeof(is_reuse_addr));

	/* 绑定指定ip和port，不然会被server拒绝 */
	struct sockaddr_in my_addr;
	bzero(&my_addr, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = my_ip;
	my_addr.sin_port = my_port;
	if(bind(m_socket_id, (struct sockaddr*)&my_addr, sizeof(my_addr)))
	{
		printf("bind error: %s(errno: %d)\n", strerror(errno), errno); 
		return -1;
	}

	/* 连接server */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = server_ip;
	server_addr.sin_port = server_port;
	while(connect(m_socket_id, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		usleep(100*1000); /* sleep 100ms, 然后重试，保证无论server先起还是后起，都不会有问题 */
	}

	/* 向server注册 */
	/* reg: pid pname eol */
	char reg_msg[50] = {'\0'};
	snprintf(reg_msg, sizeof(reg_msg) - 1, "reg: %d %s \n", my_id, "sunflower"); 
	send(m_socket_id, reg_msg, strlen(reg_msg) + 1, 0);

	/* 接收server消息，进入游戏 */
	while(1)
	{
		char buffer[1024] = {'\0'};
		int length = recv(m_socket_id, buffer, sizeof(buffer) - 1, 0);
		if(length > 0)
		{ 
			/* on_server_message返回-1（比如收到game over消息），则跳出循环，关闭socket，安全退出程序 */
			if (-1 == on_server_message(length, buffer))
			{
				break;
			}
		} 
	}

	/* 关闭socket */
	close(m_socket_id);

	return 0;
}
