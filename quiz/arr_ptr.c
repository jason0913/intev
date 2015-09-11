/* 
* @Author: jql
* @Date:   2015-08-15 10:44:05
* @Last Modified by:   jql
* @Last Modified time: 2015-08-15 10:45:26
*/

#include <stdio.h>

int function(const int src[16]){
    int val1=0;
    int dst[16]={0};
    int val2=0;
    const int *psrc=src;
    //问题1：如下代码行输出什么？
    fprintf(stdout,"size of src=%lu\n",sizeof(src));
    //问题2：如下代码有什么副作用？
    for(int i=0;i<=16;i++){
     dst[i]=*psrc+i;
     psrc++;
    }
    return 0;
}

int main() {

	const int src[16] ={1};
	function(src);
    return 0;
}