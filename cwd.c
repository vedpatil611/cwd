#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct passwd* wd = getpwuid(getuid());
	
	// Current username
	const char* username = wd->pw_name;
	// Currnet user home direcotry
	const char* home_dir = wd->pw_dir;

	// Current working directory
	const char* current_dir = getenv("PWD");

	if(strcmp(home_dir, current_dir) == 0)          // If currrent working directory is same as user's home direcotry, print ~
	{
		printf("~");
		return 0;
	}
	else if(strcmp(current_dir, "/") == 0)         // If user is at root level print /
	{
		printf("/");
		return 0;
	}

	char dir[256];
	strcpy(dir, current_dir);
	char* tok = strtok(dir, "/");
	char* tmp;
	
	while(tok != NULL)                             // Keep tokenizing current dir path until you get current folder name
	{
		tmp = tok;
		tok = strtok(NULL, "/");
	}

	// print directory name
	printf("%s", tmp);

	return 0;
}
