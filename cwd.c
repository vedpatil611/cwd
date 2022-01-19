#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct passwd* wd = getpwuid(getuid());
	const char* username = wd->pw_name;
	const char* home_dir = wd->pw_dir;

	const char* current_dir = getenv("PWD");

	if(strcmp(home_dir, current_dir) == 0) 
	{
		printf("~");
		return 0;
	}
	else if(strcmp(current_dir, "/") == 0)
	{
		printf("/");
		return 0;
	}

	char dir[256];
	strcpy(dir, current_dir);
	char* tok = strtok(dir, "/");
	char* tmp;
	
	while(tok != NULL) 
	{
		tmp = tok;
		tok = strtok(NULL, "/");
	}

	printf("%s\n", tmp);

	return 0;
}
