/*
     Linux shell command ls	 
	 List all of files under current directory
*/

#include <stdio.h>
#include <dirent.h>	
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/stat.h>	// 这个头文件用来得到文件的详细信息
#include <time.h>	    // 时间头文件
#include <pwd.h>	    // 用来得到用户名
#include <grp.h>	    // 用来取得组名
 
// argv, argc 
// 结构体，用来存储要输出的每个属性值。
//
struct attribute
{
	char mode[10];		 // 文件属性和权限
	int  links;		     // 链接数
	char user_name[20];	 // 用户名
	char group_name[20]; // 所在的用户组group
	long size;		     // 文件大小
	char mtime[20];		 // 最后修改的时间
	char filename[255];	 // 文件名
	char extra[3];		 // 用来显示时候要加 "*"(可以执行的文件) 或者 "/" (目录) 的额外字符串
};
 
// 计算整数 n 有几位
int f(long n) {
	int ret = 0;
	while(n) {
		n = n / 10;
		++ ret;
	}
	return ret;
}
 
// 得到终端的列数和行数
void getTerminatorSize(int *cols, int *lines) {
 
#ifdef TIOCGSIZE  
    struct ttysize ts;  
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);  
    *cols = ts.ts_cols;  
    *lines = ts.ts_lines;  
#elif defined(TIOCGWINSZ)  
    struct winsize ts;  
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);  
    *cols = ts.ws_col;  
    *lines = ts.ws_row;  
#endif /* TIOCGSIZE */  
 
}
 
// 由 int 型的 mode，得到实际要显示的字符串。
void mode2str(int mode, char str[])
{
    strcpy(str, "----------\0"); 
    if(S_ISDIR(mode)) str[0] = 'd';
    if(S_ISCHR(mode)) str[0] = 'c';
    if(S_ISBLK(mode)) str[0] = 'b';
    if(S_ISLNK(mode)) str[0] = 'l';
 
    if(mode & S_IRUSR) str[1] = 'r';
    if(mode & S_IWUSR) str[2] = 'w';
    if(mode & S_IXUSR) str[3] = 'x';
 
    if(mode & S_IRGRP) str[4] = 'r';
    if(mode & S_IWGRP) str[5] = 'w';
    if(mode & S_IXGRP) str[6] = 'x';
 
    if(mode & S_IROTH) str[7] = 'r';
    if(mode & S_IWOTH) str[8] = 'w';
    if(mode & S_IXOTH) str[9] = 'x';
}
 
// 根据用户的 id 值，得到用户名 user name。
void uid2str(uid_t uid, char *user_name) /* 将uid转化成username */
{
	struct passwd *pw_ptr;
	pw_ptr = getpwuid(uid);
 
	if( pw_ptr == NULL) {
		sprintf(user_name, "%d", uid);
	} else {
		strcpy(user_name, pw_ptr->pw_name);
	}
}
 
// 根据用户组的 id 值，得到用户组名 group name。
void gid2str(gid_t gid, char *group_name) /* 将uid转化成username */
{
	struct group *grp_ptr;
	grp_ptr = getgrgid(gid);
 
	if( grp_ptr == NULL) {
		sprintf(group_name, "%d", gid);
	} else {
		strcpy(group_name, grp_ptr->gr_name);
	}
}
 
/*
    时间的格式化字符串，注意这里把前面的星期和后面的年份都去掉了。
*/
void time2str(time_t t, char *time_str)
{
	strcpy( time_str, ctime(&t) + 4);
	time_str[12] = '\0';
}
 
// 要显示的某一个文件详细信息，并把信息放在结构体 attribute 中。
void ls_long_file(char *dirname, char *filename, struct attribute *file_attri) 
{
	// 根据文件夹名和文件名得到全名
	char fullname[256];
	strcpy(fullname, dirname);
	strcpy(fullname + strlen(dirname), filename);
 
	struct stat mystat;
	if ( stat(fullname, &mystat) == -1) {
		printf("ls_long_file: stat error\n");		
	} else {
		// 这里参考 <stat.h> 头文件
		int mode   = (int)  mystat.st_mode;
		int links  = (int)  mystat.st_nlink;
		int uid    = (int)  mystat.st_uid;
		int gid    = (int)  mystat.st_gid;
		long size  = (long) mystat.st_size;
		long mtime = (long) mystat.st_mtime;
 
		char str_mode[10];			/* 文件类型和许可权限, "drwxrwx---" */
		char str_user_name[20];
		char str_group_name[20];
		char str_mtime[20];
 
		mode2str(mode, str_mode);
		uid2str(uid, str_user_name);
		gid2str(gid, str_group_name);
		time2str(mtime, str_mtime);
		
		char extra[3] = "\0\0";
		if (str_mode[0] == 'd') {
			extra[0] = '/';
		} else if (str_mode[0] == '-' && str_mode[3] == 'x') {
			extra[0] = '*';
		}
			
		// 存储在结构体中
		strcpy(file_attri->mode, str_mode);
		file_attri->links = links;
		strcpy(file_attri->user_name, str_user_name);
		strcpy(file_attri->group_name, str_group_name);
		file_attri->size = size;
		strcpy(file_attri->mtime, str_mtime);
		strcpy(file_attri->filename, filename);
		strcpy(file_attri->extra, extra);
	} 	
}

// struct
struct attribute file_attribute[200]; // maximum 200
 
void lsLong(char *dirname)
{
	
	DIR *mydir = opendir( dirname );			/* directory */	
 
	char filename[20];
	int file_num = 0;
 
	if (mydir == NULL) {
		// 显示单个文件的详细信息
		strcpy(filename, dirname);
		ls_long_file("./", filename, &file_attribute[0]);
		++ file_num;
	} else {
		// 考虑用户输入文件夹没有输入反斜杠的情况
		int len = strlen(dirname);
		if (dirname[len - 1] != '/')
		{
			dirname[len] = '/';
			dirname[len+1] = '\0';
		}
 
		// 循环得到当前目录下的所有文件名，并存储在自定义的结构体中。
		struct dirent *mydirent;			/* file */
		while ( (mydirent = readdir( mydir )) != NULL) {
			char filename[20];
			strcpy(filename, mydirent->d_name);
			// 不能为隐藏文件
			if (!strcmp(filename, ".") || !strcmp(filename, ".") || filename[0] != '.') {
				ls_long_file(dirname, filename, &file_attribute[file_num ++]);
			}	
			
		}
		closedir( mydir );
	}
 
	// 按照文件名排序
	struct attribute temp;
	char filename1[20];
	char filename2[20];
	int i, j;
 
	for (i = 0; i < file_num; ++i)
	{
		for (j = i + 1; j < file_num; ++ j)
		{
			strcpy(filename1, file_attribute[i].filename);
			strcpy(filename2, file_attribute[j].filename);
			if ( strcmp(filename1, filename2) > 0)
			{
				temp = file_attribute[i];
				file_attribute[i] = file_attribute[j];
				file_attribute[j] = temp;
			}
		}			
	}
 
	// 格式化输出时,考虑每个属性值的范围
	int max_mode = 0;
	int max_links = 0;
	int max_user_name = 0;
	int max_group_name = 0;
	int max_size = 0;
	int max_mtime = 0;
	int max_filename = 0;
	int max_extra = 0;
 
	for (i = 0; i < file_num; ++ i)
	{
		if ( max_mode < strlen(file_attribute[i].mode) ) {
			max_mode = strlen(file_attribute[i].mode);
		}
 
		if (max_links < f(file_attribute[i].links)) {
			max_links = f(file_attribute[i].links);
		}
 
		if ( max_user_name < strlen(file_attribute[i].user_name) ) {
			max_user_name = strlen(file_attribute[i].user_name);
		}
 
		if ( max_group_name < strlen(file_attribute[i].group_name) ) {
			max_group_name = strlen(file_attribute[i].group_name);
		}
 
		if (max_size < f(file_attribute[i].size)) {
			max_size = f(file_attribute[i].size);
		}
 
		if ( max_mtime < strlen(file_attribute[i].mtime) ) {
			max_mtime = strlen(file_attribute[i].mtime);
		}
 
		if ( max_filename < strlen(file_attribute[i].filename) ) {
			max_filename = strlen(file_attribute[i].filename);
		}
 
		if ( max_extra < strlen(file_attribute[i].extra) ) {
			max_extra = strlen(file_attribute[i].extra);
		}	
	}
 
	for (i = 0; i < file_num; ++i)
	{
		char format[50];
		// 定义输出的格式
		sprintf(format, "%%%ds %%%dd %%%ds %%%ds %%%dld %%%ds %%s%%s\n", 
			max_mode, max_links, max_user_name, max_group_name, max_size,
			max_mtime);
		// 按照定义的输出格式输出
		printf(format, file_attribute[i].mode, file_attribute[i].links, 
			file_attribute[i].user_name, file_attribute[i].group_name, file_attribute[i].size, 
			file_attribute[i].mtime, file_attribute[i].filename, file_attribute[i].extra);
	}
 
}
 
// 处理不带 -l 参数的 ls 命令
void lsShort(char *dirname) {
 
	DIR *mydir = opendir(dirname);			/* directory */	
 
	// 用来暂时存储要显示的目录下的所有文件名,可以看到最大可以支持200个文件,但是每个文件名最长为20
	char filenames[200][20];
	int file_num = 0;
 
	if (mydir == NULL) {
		// 直接显示该文件
		printf("%s\n\n", dirname);
		return ;
	} else {
		// 循环检查下面有多少文件,并把文件名全部放到filenames数组里
		struct dirent *mydirent;			/* file */
		while ( (mydirent = readdir( mydir )) != NULL) {
			char fname[20];
			strcpy(fname, mydirent->d_name);	
			if (fname[0] != '.' ) {
				strcpy(filenames[file_num], mydirent->d_name);
				file_num ++;
			}	
		}
		closedir( mydir );
	}
 
	// 文件名排序
	int i, j;
	char temp[20];
	for(i = 0; i < file_num; ++ i) {
		for(j = i+1; j < file_num; ++ j) {
			if(strcmp(filenames[i], filenames[j]) > 0) {
				strcpy(temp, filenames[i]);
				strcpy(filenames[i], filenames[j]);
				strcpy(filenames[j], temp);
			}
		}
	}
 
	// 确定所有文件里面最长的文件名的长度
	int max_len = 0;
	
	for(i = 0; i < file_num; ++ i) {
		int len = strlen(filenames[i]);
		if(len > max_len) {
			max_len = len;
		}
	}
 
	// 得到当前终端的分辨率
	int cols = 80;
	int lines = 24;
	getTerminatorSize(&cols, &lines);
	
	char format[20];
	sprintf(format, "%%-%ds  ", max_len);
 
	// 格式化输出,当长度大于终端的列数时,换行
	int current_len = 0;
	for(i = 0; i < file_num; ++ i) {
		printf(format, filenames[i]);
		current_len += max_len + 2;
		if(current_len + max_len + 2 > cols) {
			printf("\n");
			current_len = 0;
		}	
	}
	printf("\n");
} 
 
int main(int argc, char **argv) {
	int i;
	if (argc == 1) {						/* ls . */
		lsShort("./");				
		return 0;
	}
	if (argc == 2 && !strcmp(argv[1], "-l") ) {			/* ls -l . */
		lsLong("./");
		return 0;
	}
	if (argc > 2 && !strcmp(argv[1], "-l") ) {			/* ls -l directory name */
		for(i = 2; i < argc; ++ i) {
			printf("%s:\n", argv[i]);
			lsLong(argv[i]);
			if(i != argc - 1)
				printf("\n");	
		}
		return 0;	
	} else {							/* ls directory name */
		for (i = 1; i < argc; ++ i) {
			printf("%s:\n", argv[i]);
			lsShort(argv[i]);
			if(i != argc - 1)
				printf("\n");	
		}
		return 0;
	}
	
	return 0;
}
