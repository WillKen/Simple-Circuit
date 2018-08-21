# Simple-Circuit
A project for the C++ Course

【【【运行程序前请认真阅读 READINGME 和REPORT】】】

代码编写环境：Win10  Visual Studio2017

代码运行方法

打开visual studio 点击 文件->新建->项目

选择visual C++ 空项目

在右侧资源管理器中 右击头文件 添加现有项， 将code中两个头文件添加进项目

在右侧资源管理器中 右击源文件 添加现有项， 将code中两个源文件添加进项目

最后点击上方按钮    运行



操作指令



连接操作： Please connect in a format like:  【pin name+pin name】(There is no space around '+'! Press -1 to end)



赋值操作：Please connect in a format like: 【pin name=X】(X=0 or 1.There is no space around '='! Press -1 to end)





【【一些测试样例的指令放在“command”文件中，请根据需要进行测试】】





错误操作（会抛出异常）：

1.将自身输出与自身输入相连（成环）

2.输出与输出相连

3.或其他会产生环的连接
