#include <stdio.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <netdb.h>
// #include <arpa/inet.h>
// #include <unistd.h>

// Some Service Functions
struct servent *getserverbyname(char *name, char *proto);
struct servent *getserverbyport(char *port, char *proto);
// each of these functions will return a structure:
struct servent
{
    char *s_name;
    char **s_aliases;
    int s_port;
    char *s_proto;
};

// IP Address Functions
int inet_aton(const char *strptr, struct in_addr *addrptr); /*convert string to network address, store in structure*/
in_addr_t inet_addr(const char *strptr); /*convert string to integer address, use as an internet address*/
char *inet_ntoa(struct in_addr inaddr); /*convert internet host address to a string*/

// Structures used for support of the main functions
struct sockaddr
{
    unsigned short sa_family;
    char sa_data[14];
};
struct in_addr
{
    unsigned long s_addr;
};
struct sockaddr_in
{
    short int sin_family;
    unsigned short int sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8];
};
struct hostent
{
    char *h_name;
    char **h_aliases;
    int h_addrtype;
    int h_length;
    char **h_addr_list;

    #define h_addr h_addr_list[0];
};


// Socket Functions
int socket(int family, int type, int protocol);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
int connect(int sockfd, struct sockaddr *serv_addr, int addrlen); // return 1 in success, 0 failure
int bind(int sockfd, struct sockaddr *my_addr, int addrlen); // sockfd = socket file description 
int listen(int sockfd, int backlog); // backlog = max number of allowed connection
int accept(int sockfd, struct sockaddr *cliaddr, socklen_t addrlen);
int recv(int sockfd, void *buf, int len, unsigned int flags);
int recvfrom(int sockfd, void *buf, int len, unsigned int flags, struct sockaddr *from, int *fromlen);
int write(int fildes, const void *buf, int nbyte);
int send(int sockfd, const void *msg, int len, int flags);
int sendto(int sockfd, const void *msg, int len, unsigned int flags, const struct sockaddr *to, int tolen);
int read(int fildes, const void *buf, int nbyte);
int close(int sockfd); // sending and receiving are not allowed 
int shutdown(int sockfd, int how); // how: 0-receiving not allowed, 1-sending not allowed, 2-same as close() 

