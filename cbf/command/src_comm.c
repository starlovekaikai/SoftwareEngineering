#include "src_comm.h"

CmdNode *newCmdNode(char cmd[10], int val) {
  /** 
   * This function allocates a new CmdNode struct and initializes it's values 
   * based on the input paramaters given. The next pointer is always 
   * initialized to NULL.
   * 
   * If the 'cmd' parameter is not a correct command, then print
   * "Invalid command.\n" and return NULL.
   * 
   * Note that we will always pass in a value here, even if the 
   * command doesn't need one. In this case, we can just ignore 
   * it. It saves us from having to make separate functions to 
   * deal with this.
   * 
   * TODO: Implement this function
   */
    if((strcmp(cmd, "penup") == 0) || (strcmp(cmd, "pendown") == 0) || (strcmp(cmd, "colour") == 0) || (strcmp(cmd, "forward") == 0) || (strcmp(cmd, "backward") == 0) || (strcmp(cmd, "left") == 0) || (strcmp(cmd, "loop") == 0) || (strcmp(cmd, "right") == 0))
    {
        
        CmdNode *new_node = (CmdNode *) calloc(1, sizeof(CmdNode));
        strcpy(new_node -> cmd, cmd);
        new_node -> val = val;
        new_node -> next = NULL;
        new_node -> loop_head = NULL;
        return new_node;
    }
    else
    {
        printf(" Invaild Command\n");
        return NULL;
    }
}
