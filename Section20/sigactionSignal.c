#include <signal.h>

/* 
void termination_handler(int signum){
    struct temp_file *p;
    
    for(p = temp_file_list; p; p = p->next)
        unlink(p->name);
}
 */

void main(){
    /* 
    struct sigaction new_action, old_action;
    // set up the structure to specify the new action
    new_action.sa_handler = termination_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;
    sigaction(SIGINT, NULL, &old_action);

    if (old_action.sa_handler != SIG_IGN) // SIG_IGN its signal ignore
        sigaction(SIGHUP, &new_action, NULL);

    sigaction(SIGHUP, NULL, &old_action);

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGHUP, &new_action, NULL);

    sigaction(SIGTERM, NULL, &old_action);

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGHUP, &new_action, NULL);
  */    
}