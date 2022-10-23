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
/* This function reads from a given .txt file, which contains several
 * valid commands. It could transcribe these commands into specific
 * data structure, which will have a command name "cmd" and a node
 * list "buf" to store all the data provided by the user.
 *
 * - filename : the relative or absolute path of the txt file.
 *
 * - Output   : <cmd_node *> type, a pointer to a data structure typed
 *              in cmd_node.
 */
cmd_node *load_cmd_file(char *filename)
{
  // printf("Begin loading from \"%s\".",filename);
  //  CmdNode *head = NULL;
  // CmdNode *forN = NULL;
  // CmdNode *temp = NULL;

  // char buffer[1024];
  // char *buf;

  // FILE *f = fopen(fileName, "r");
  // while (fgets(&buffer[0], 1024, f) != NULL) {
  //   temp = NULL;
  //   buf = &buffer[0];

  //   if (strncmp(buf, "  ", 2) && forN != NULL) forN = NULL;
  //   if (forN != NULL) buf = buf + 2;  // Skip over indents

  //   if      (!strncmp(buf, "backward", 8)) temp = newCmdNode("backward", atoi(&buf[9]));
  //   else if (!strncmp(buf, "forward", 7)) temp = newCmdNode("forward", atoi(&buf[8]));
  //   else if (!strncmp(buf, "pendown", 7)) temp = newCmdNode("pendown", 0);
  //   else if (!strncmp(buf, "colour", 6)) temp = newCmdNode("colour", atoi(&buf[7]));
  //   else if (!strncmp(buf, "penup", 5)) temp = newCmdNode("penup", 0);
  //   else if (!strncmp(buf, "right", 5)) temp = newCmdNode("right", 0);
  //   else if (!strncmp(buf, "left", 4)) temp = newCmdNode("left", 0);
  //   if (!strncmp(buf, "loop", 4)) forN = newCmdNode("loop", atoi(&buf[5]));

  //   if (temp != NULL && forN != NULL) insertCommandLoop(forN, temp);
  //   else if (temp != NULL) head = insertCommand(head, temp);
  //   else if (forN != NULL) head = insertCommand(head, forN);
  // }
  // fclose(f);
  // return head;
  // printf("Success in loading!");
}
cmd_type new_cmd_list()
{
}