#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define STORAGE_BUFFER_SIZE 50
#define FILE "open_this_file.txt"

int main(){
	int file_descriptor = -1;
	char buffer_to_store_data[STORAGE_BUFFER_SIZE];

	file_descriptor = open(FILE, O_RDONLY | O_WRONLY | O_CREAT, 0600);
	if (file_descriptor == -1){
		perror("Error opening file");
		printf("FD = %d\r\n",file_descriptor);
		return 1;
	}else{
		printf("FD = %d Successfully created file\r\n",file_descriptor);
	}

	const char* write_to_file = "Hello from outside the file\n\r";
	ssize_t bytes_written = write(file_descriptor,write_to_file,strlen(write_to_file));
	
	if (bytes_written == -1){
		perror("Error writing to file");
		return 1;
	}else if (bytes_written < strlen(write_to_file)){
		printf("Partial write: only %ld bytes written\r\n",bytes_written);
	}else {
		printf("Write successful, bytes written %ld\r\n",bytes_written);
	}
	close(file_descriptor);

	file_descriptor = open(FILE, O_RDONLY);

	if (file_descriptor == -1){
		perror("Error opening file");
		return 1;
	}

	ssize_t bytes_read = read(file_descriptor, buffer_to_store_data, sizeof(buffer_to_store_data)-1);

	if (bytes_read == -1){
		perror("Error reading file");
		close(file_descriptor);
		return 1;
	}

	buffer_to_store_data[bytes_read] = '\0';

	printf("File content: %s\r\n",buffer_to_store_data);

	close(file_descriptor);

	return 0;

}
