#include "src_comm.h"
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
 * - cmd : the name of command, there are only four enumerate classes.
 * - buf : the structure stored data.
 */
cmd_node *new_cmd_node(char cmd[10], data_buff *buf)
{

  if ((GSTRCmp(cmd, "points") == 0) || (GSTRCmp(cmd, "line") == 0) || (GSTRCmp(cmd, "circle") == 0) || (GSTRCmp(cmd, "polygon") == 0)) /*这里或许需要修改一下，我已经使用上了枚举的方法*/
  {
    cmd_node *new_node = (cmd_node *)calloc(1, sizeof(cmd_node));
    GSTRCpy(new_node->name, cmd);
    new_node->data = buf;
    new_node->next = NULL;
    return new_node;
  }
  else
  {
    printf("Invaild Command\n");
    return NULL;
  }
}
/*
 *
 *
 */
void read_cmd_file(char *filename);