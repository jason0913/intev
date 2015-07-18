#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int max = 0;
	int input[100];
	int c;
	int index = 0;
	while(scanf("%d",&input[index]) != 'EOF')
	{
		
	}
	index = 0;
	while(input[index])
	{
		if (input[index] > max)
		{
			max = input[index];
		}
	}
	printf("%d\n", max);
	printf("%s\n", input);
	system("pause");
	return 0;
}{
    // The tab key will cycle through the settings when first created
    // Visit http://wbond.net/sublime_packages/sftp/settings for help
    
    // sftp, ftp or ftps
    "type": "sftp",

    "sync_down_on_open": true,
    "sync_same_age": true,
    
    "host": "198.18.15.248",
    "user": "root",
    //"password": "password",
    //"port": "22",
    
    "remote_path": "/home/root/",
    //"file_permissions": "664",
    //"dir_permissions": "775",
    
    //"extra_list_connections": 0,

    "connect_timeout": 30,
    //"keepalive": 120,
    //"ftp_passive_mode": true,
    //"ftp_obey_passive_host": false,
    //"ssh_key_file": "~/.ssh/id_rsa",
    //"sftp_flags": ["-F", "/path/to/ssh_config"],
    
    //"preserve_modification_times": false,
    //"remote_time_offset_in_hours": 0,
    //"remote_encoding": "utf-8",
    //"remote_locale": "C",
    //"allow_config_upload": false,
}
