#include "src_comm.h"

cmd_node new_cmd_node(char cmd[10], data_buff buf)
{
  /**
   * This function allocates a new cmd_node struct and initializes it's values
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
  if ((strcmp(cmd, "points") == 0) || (strcmp(cmd, "line") == 0) || (strcmp(cmd, "circle") == 0) || (strcmp(cmd, "polygon") == 0))
  {

    cmd_node *new_node = (cmd_node *)calloc(1, sizeof(cmd_node));
    strcpy(new_node->cmd, cmd);
    new_node->val = val;
    new_node->next = NULL;
    new_node->loop_head = NULL;
    return new_node;
  }
  else
  {
    printf(" Invaild Command\n");
    return NULL;
  }
}
