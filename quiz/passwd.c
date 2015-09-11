/* 
* @Author: jql
* @Date:   2015-08-25 21:31:04
* @Last Modified by:   jql
* @Last Modified time: 2015-08-25 21:48:07
	get /etc/passwd info
*/

#include <stdio.h>
#include <pwd.h>
#include <string.h>
struct passwd*
getpwname(const char *name)
{
	struct passwd *ptr;
	setpwent();
	while(NULL != (ptr=getpwent()))
	{
		if (strcmp(name,ptr->pw_name)==0)
		{
			printf("%s\n", ptr->pw_name);
			printf("%s\n", ptr->pw_passwd);
			printf("%s\n", ptr->pw_dir);
			printf("%s\n", ptr->pw_shell);
			printf("%d\n", ptr->pw_uid);
			printf("%d\n", ptr->pw_gid);
			break;
		}
	}
	endpwent();
	return ptr;
}

int main() {

	char name[] = "jql";
	getpwname(name);
    return 0;
}