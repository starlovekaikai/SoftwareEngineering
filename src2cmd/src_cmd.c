#include "src_cmd.h"
#include "wrapper.h"
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
    GSTRCpy(new_node->cmd_type, cmd);
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
cmd_node *new_cmd_list()
{
  cmd_node *new_node = (cmd_node *)calloc(1, sizeof(cmd_node));
  new_node->cmd_type = NOT_CMD;
  new_node->data = NULL;
  new_node->next = NULL;
  return new_node;
}
PGSTRV read_cmd_std() // 得到gstr类型的一个变量指针
{
  //在使用之前最好加一个Printf请求用户输入命令
  PGSTRV cmd = NewGSTR_Empty();
  char ch;
  while ((ch = getchar()) != '\n')
  {
    if (GSTRLen(cmd) > MAX_CMD_LEN)
    {
      printf("Sorry, your input command is too long to translate. Please try it again.");
      break;
    }
    else
    {
      PGSTRV temp_c = NewGSTR_ByStr(&ch);
      GSTRCat(cmd, temp_c);
    }
  }
  return cmd;
}
PGSTRV read_cmd_file(file_name) // 得到gstr类型的一个变量指针
{
  char *buffer = (char *)calloc(MAX_CMD_LEN, sizeof(char));
  //在使用之前最好加一个Printf请求用户输入命令
  FILE *file = fopen(file_name, "r");
  while (fgets(buffer, MAX_CMD_LEN, file) != NULL)
  { //一行一行地读取，直到读取到文件末尾
    PGSTRV = NewGSTR_ByStr(buffer);
    /*
     *
     * 这里将对读取得到的gstr进行处理，得到一个命令数据体，包含全部规范化数据的
     * 规范化是指，对于不同格式表达的同一形状，如用半径和用直径表达的圆，都应当对应于同一个数据形式
     * 这里应该进行计算并作初步的转化
     */
    //清空内存
    memset(buffer, MAX_CMD_LEN, sizeof(char));
  }
  fclose(file);
  return head;
}
void gstr_normalize(PGSTRV raw_gstr) //已知是一个gstr字符串，需要转换成一个对应名字枚举变量，对应数据的数据结构体
{                                    /* 这里是转化的第一步，将命令规范化，
                                      * 去掉多余的空格、查找命令是否符合要求，去掉行末多余的标点符号
                                      *
                                      *
                                      */
  GSTRFind
}