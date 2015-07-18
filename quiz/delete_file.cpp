/* 
* @Author: root
* @Date:   2015-07-16 23:10:58
* @Last Modified by:   root
* @Last Modified time: 2015-07-16 23:32:44
  delete a file in dirction
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main(){

	char file[] ="/home/liujunqiang/intev/quiz/tmp.txt";
	FILE* fp = fopen(file,"w");
	if (fp ==NULL)
	{
		perror("open file error");
		exit(-1);
	}
	cout<<"creat file:"<<file<<endl;
	fputs(file,fp);
	sleep(10);
	cout<<"delete file:"<<file<<endl;
	unlink("/home/liujunqiang/intev/quiz/tmp.txt");
    return 0;
}