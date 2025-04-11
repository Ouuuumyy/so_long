#include "../so_long.h"

int open_file(char *filename)
{
    int fd;
    int len;

    len = ft_strlen(filename);
    if(ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
    {
        exit_error("Error: Map file must have .ber extention\n");
    }
    fd = open(filename, O_RDONLY);
    if(fd < 0)
        exit_error("Error: can not open file\n");
    return fd;
}

char *allocate_buffer()
{
    char *buffer;

    buffer = malloc(1024 * sizeof(char));
    if(!buffer)
        exit_error("Error: malloc failed\n");
    return buffer;
}

char *reallocate_buffer(char *buffer, int old_size, int new_size)
{
    char *new_buffer;
    new_buffer = malloc(new_size);
    ft_memcpy(new_buffer, buffer, old_size);
    free(buffer);
    return new_buffer;
}

void check_read_bytes(int fd, char *buffer, int read_bytes)
{
    if (read_bytes < 0)
    {
        free(buffer);
        close(fd);
        exit_error("Error: Failed to read map file");
    }
}

char *read_file(char *file_name)
{
    int fd;
    char *buffer;
    int read_bytes;
    int total_bytes;
    int buffer_size;
    int new_size;

    total_bytes = 0;
    buffer_size = 1024;
    fd = open_file(file_name);
    buffer = allocate_buffer();
    while ((read_bytes = read(fd, buffer + total_bytes, buffer_size - total_bytes - 1)) > 0)
    {
        total_bytes += read_bytes;
        if (total_bytes >= buffer_size - 1)
        {
            new_size = buffer_size * 2;
            buffer = reallocate_buffer(buffer, buffer_size, new_size);
            buffer_size = new_size;
        }
    }
    check_read_bytes(fd, buffer, read_bytes);
    buffer[total_bytes] = '\0';
    close(fd);
    return buffer;
}

int main()
{
    char *map = read_file("./map.ber");
    free(map);
    return 0;
}
