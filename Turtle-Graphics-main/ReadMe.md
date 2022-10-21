An interactive application that is capable of reading a .txt file that has commands (with loops) to move the direction of the pen and draw “pen on” on a white background. In addition, the user is capable of choosing different gradients of black upon request. With the interactive driver, the user can easily manage the application and apply any preconfigured commands.

The user can compile the program with the interactive driver using the following command:

gcc -g -Wall -Werror Part2_interactive.c -lm -o Part2_interactive
这个小程序是我从github上clone过来的，具体使用方法如下所示：

1、将整个文件夹复制至本地能运行C程序的路径中，例如我使用的是vscode，则复制到vscode对应文件夹内，如果使用的是Visual Studio的编译工具，可新建一个项目repository，将本目录下全部的源文件.c导入至新建文件中；

2、运行`Part2_interactive.c`文件（VS下直接点击release或者debug，如果使用mingw编译工具，则可以在命令行中输入以下命令：
```
cd "复制后的文件夹目录，命名中有空格应该加双引号，如我的就是E:\Code\softwareCourse\Turtle-Graphics-main"
gcc Part2_interactive.c
```
3、进入程序页面中，输出如下所示：
```
------------------------------------------------
Please choose one of the following options:
0 - Insert a new command.
1 - Insert a loop command.
2 - Print list of commands.
3 - Query by command type.
4 - Load commands from file.
5 - Run commands and draw image.
6 - Reset the list.
7 - Delete list and exit.
Enter choice =
```
4、示例命令在文本文件`box-pro.txt`里面，因此这里在命令行中输入4，得到响应：
```
------------------------------------------------
Filename =
```
5、输入文件命名`box-pro.txt`，得到响应：
```
------------------------------------------------
Please choose one of the following options:
0 - Insert a new command.
1 - Insert a loop command.
2 - Print list of commands.
3 - Query by command type.
4 - Load commands from file.
5 - Run commands and draw image.
6 - Reset the list.
7 - Delete list and exit.
Enter choice =
```
6、输入绘图命令5，然后输入命令7退出绘图程序；

7、在同一目录下，产生了输出的`output-pro.pgm`文件，一般电脑没有打开这种格式的程序，这里提供[在线转换网站](https://convert.72wo.com/pgm-to-png)，在这里将刚才得到的pgm文件上传后转换，即可查看绘图结果，应该是一个白底黑边的矩形框。


