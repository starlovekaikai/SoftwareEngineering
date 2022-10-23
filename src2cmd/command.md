|序号|名称|说明|类型|范围|
|:---:|:---:|:---:|:---:|:---:|
|1|图形坐标|图形界面上的坐标|整型|0~1024|
|2|用户坐标|用户界面上的坐标|浮点型|（视情况决定）|
|3|图形类型|预定义的不同类型的图形形状|枚举型|数量有限|
|4|图形点|在图形界面上的点|结构体||
|5|用户点|在用户界面上的点|结构体||
|6|图形方向向量|在图形界面上的单位方向向量|结构体||
|7|用户方向向量|在用户界面上的单位方向向量|结构体||
-------
|命令名称|数据项1|数据项2|数据项3|数据项4|数据项5|数据项6|数据项7|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|画点命令|点数量|用户点列表|
|画线命令|起始用户点|用户方向向量|长度||
|画圆命令|圆心用户点|半径|
|画正多边形命令|圆心用户点|半径|起始点用户向量|
命令的格式：名字:2,2,0,
换行代表下一个命令或者无命令