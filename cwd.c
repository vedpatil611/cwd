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


	// If currrent working directory is same as user's home direcotry, print '~'
	if(strcmp(home_dir, current_dir) == 0)
	{
		printf("~");
		return 0;
	}
	// If user is at root level print '/'
	else if(strcmp(current_dir, "/") == 0)
	{
		printf("/");
		return 0;
	}

	// Search last '/' and get the pointer
	const char* dir_name_ptr = (const char*) ((long) strrchr(current_dir, '/') + 1);

	// print directory name
	printf("%s", dir_name_ptr);

	return 0;
}
