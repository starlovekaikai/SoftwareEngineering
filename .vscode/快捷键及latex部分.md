## VScode代码快速格式化：shift + alt + F
## 快捷运行代码：ctrl + alt + N
## 快捷搜索功能：CTRL + SHIFT + P
.py转.exe：在cmd中利用D:和cd D:\code\python代码将路径转到.py文件下，然后使用pyinstaller -F 名字.py （-w）命令转之
latex代码遵从先后顺序，后出现的相同功能对先出现的进行覆盖。
Latex字体对应：

|字号| pt值| 宽度 |指令|
|:--:|:--:|:--:|:--:|
|七号 　|　5.25pt 　|　   1.845mm　　|　　\tiny|
|六号 　|　7.875pt 　|　 2.768mm　|　　　\scriptsize|
|小五号 |　9pt 　　　|　  3.163mm　|　\footnotesize|
|五号 　|　10.5pt 　　|   3.69mm　　|　　  \small|
|小四号 |　12pt 　　　|　4.2175mm　|　　 \normalsize|
|四号 　|　13.75pt 　　| 4.83mm　　|　　  \large|
|三号 　|　15.75pt 　|　 5.53mm　　|　　  \Large|
|二号 　|　21pt 　　　|　7.38mm 　|　　　  \LARGE|
|一号 　|　27.5pt 　　 |  9.48mm　|　　　  \huge|
|小初号| 　36pt 　　　|　12.65mm　|　　　\Huge|
|初号 |　　42pt 　　　|　14.76mm　|       \HUGE|

\mathrm可在数学模式下将公式字体改为TNR
部分cmd指令：
## cd "Path"：双引号内可包含空格，不含双引号不得有空格，将目录转移到同一磁盘下的另一目录处；
C:\Users\Boffee\AppData\Roaming\Code\User\workspaceStorage\41d6ec93befa2a7f1a9ac38e0e286f17
装得有VScode的Java类和Js类，如果不调试了，可以删了省内存
## Java调试不要点run java和debug java，只能点左下角的java调试器或者F5
## VScode C语言的数组比dev c++更小
python调用tex渲染的方法：加入头文件 matplotlib *,复制下列格式：
`config = {
    "font.family": 'serif',
    "font.size": 14,
    "mathtext.fontset": 'stix',
    "font.serif": ['SimSun']
}
rcParams.update(config)
_,axe=plt.subplots()
axe.set_title(title_name)
axe.bar(x=range(0,256),height=input_fig,width=1)
axe.set_xlabel('像素灰度值')
axe.set_ylabel('灰度出现频率数')
y=input_fig.max()
x=input_fig.tolist().index(y)
axe.text(x,y*2/3,'$\leftarrow$概率最大的灰度值为$%d$'%(x))
x1_label=axe.get_xticklabels()
[x1_label_temp.set_fontname('TimesNewRoman')
for x1_label_temp in x1_label]
y1_label=axe.get_yticklabels()
[y1_label_temp.set_fontname('TimesNewRoman')
for y1_label_temp in y1_label]
plt.savefig(save_url)
#plt.show()`

远程GPU服务器账号
xdy_cbf@10.134.52.156
密码
buaa_xdy_cbf@
### 把ipynb文件转换成py文件
jupyter nbconvert --to script *.ipynb