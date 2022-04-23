#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
static char message[] = "HELLO WORLD";
int main()
{
int fd;
char buffer[80];
fd = open("file2.txt",O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
if (fd != -1)
{
printf("File has been opened for READ/WRITE access\n");
write(fd, message, sizeof(message));
lseek(fd, 0, 0); /* go back to the beginning of the file */
if (read(fd, buffer, sizeof(message)) == sizeof(message))
printf("\"%s\" Message has been written to file \n", buffer);
else
printf("error in reading file \n");
close (fd);
}
else
printf("File already exists\n");

exit(0);
}
