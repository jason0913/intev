#include <stdio.h>
#include "httpdownload.h"
int http_callback(int status, unsigned int total_bytes, unsigned int already_bytes, unsigned int tim)
{
	switch ( status ) {
		case HDL_READYOK:
			printf("ready to download, total.bytes=%u/n", total_bytes);
			break;
		case HDL_DOWNING:
			printf("downloading... (%u/%u) bytes/n", already_bytes, total_bytes);
			break;
		case HDL_FINISH:
			printf("download finish! download total.bytes=%u/n", already_bytes);
			break;
		default:
			printf("status: %#x/n", status);	
	}	
	return 0;
}

int main(int argc, char *argv[])
{
	pq_http_download(argv[1], argv[2], NULL, http_callback);
}
