#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
int fd;
fd = creat("File1.txt", S_IREAD | S_IWRITE);
if (fd != -1){
printf("Created file opened for read/write access\n");
printf("File1 is currently empty\n");
}
else
printf("Error in opening file\n");

close(fd);
exit (0);
}


