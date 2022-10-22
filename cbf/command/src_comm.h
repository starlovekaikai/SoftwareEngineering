/*
 *This file provides with functions to get command
 *from commandline or from a specific command file.
 *
 */
#if include _SRC_COMMAND_
#define _SRC_COMMAND_
#endif
// This lets the driver code override the image size if it needs to. Make sure
// you don't hard-code these values anywhere!
#ifndef SIZEX
#define SIZEX 512
#define SIZEY 512
#endif
/*---------------------------------------------------------------------------*/

/**
 * This struct contains one node of the linked list, which represents a single
 * command. It's field should include:
 *
 *  - name   : A char array of size 10 holding the command name
 *
 *  - data  : An pointer to a dynamic node buffer, where stores all the input
 *            args including points coordinates, length and radius.
 *
 *
 ****/
typedef struct cmd_node
{
  char name[10];
  void *data;
} cmd_node;
/**
 * This struct contains a buffer for 2 dimension data, namely vector data.
 * It's field should include:
 *
 *  - x_val   : A integar value for its first dimension.
 *
 *  - y_val   : A integar value for its second dimension.
 *
 *  - next    : A pointer to next potential data structure, it could be
 *              a same one or not.
 *
 *
 ****/
typedef struct data_buff
{
  int x_val;
  int y_val;
  struct data_buff *next;
} data_buff;

cmd_node new_cmd_node()
