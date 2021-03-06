#ifndef __FF_HOOK_H__
#define __FF_HOOK_H__

#include <stdint.h>

#define FF_FD_BITS 16
#define CHK_FD_BIT(fd)          (fd & (1 << FF_FD_BITS))
#define CLR_FD_BIT(fd)          (fd & ~(1 << FF_FD_BITS))

void ff_hook_new_fd(int fd);
bool ff_hook_find_fd(int fd);

void ff_hook_free_fd(int fd);
int ff_hook_socket(int domain, int type, int protocol);
int ff_hook_close(int fd);

int ff_hook_connect(int fd, const struct sockaddr *address, socklen_t addrlen_len);

ssize_t ff_hook_read(int fd, void *buf, size_t nbyte);

ssize_t ff_hook_write(int fd, const void *buf, size_t nbyte);
ssize_t ff_hook_sendto(int fd, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
ssize_t ff_hook_recvfrom(int fd, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len);
ssize_t ff_hook_recv(int fd, void *buffer, size_t length, int flags);
ssize_t ff_hook_send(int fd, const void *buf, size_t nbyte, int flags);
int ff_hook_setsockopt(int fd, int level, int option_name, const void *option_value, socklen_t option_len);
int ff_hook_ioctl(int fd, int cmd, void *arg);

int ff_hook_fcntl(int fd, int cmd, void *arg);

int ff_hook_listen(int fd, int backlog);

int ff_hook_bind(int fd, const struct sockaddr *addr, socklen_t addrlen);
int ff_hook_accept(int fd, struct sockaddr *addr, socklen_t *addrlen);

#endif

