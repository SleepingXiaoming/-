实验项目1 银行家算法

**1.**   **实验目的与要求**

用C语言编写安全性算法及银行家算法，以帮助学生深刻理解银行家算法避免死锁的原理。

**2.** **实验内容提要**

（1）定义相关数据结构

（2）利用C语言或其他语言编写安全性算法

（3）调用安全性算法，编写银行家算法，并验证算法的有效性

**3****．输入数据**

| **进程**    | **Allocation**    | **Need**    | **Available** |
| ----------- | ----------------- | ----------- | ------------- |
| **A  B  C** | **A  B  C**       | **A  B  C** |               |
| **P0**      | **0  1  0**       | **7  4  3** | **3  3   2**  |
| **P1**      | **2  0  0**       | **1  2  2** |               |
| **P2**      | **3  0  2**       | **6  0  0** |               |
| **P3**      | **2  1  1**       | **0  1  1** |               |
| **P4**      | **0**    **0  2** | **4  3  1** |               |

验证当前状态是否为安全状态后，利用银行家算法判断如下资源请求能否满足，（所有要求是连续的）。

（1）判断该状态是否为安全状态；（需给出安全序列）

（2） P1：（1,0,2）；

（3） P4:（3,3, 0）；

（4） P0：（0,2,0）。

**4****．注意事项**

注意程序的输出格式，保证程序的可读性

**5.****实验报告的书写方法**

（1）实验目的与要求

（2）安全性算法流程图、银行家算法流程图（不必再一次展开安全性算法流程图）

（3）完整程序

（4）输出结果



实验项目2 页面置换算法

**1.** **实验目的与要求**

用C语言设计开发OPT、FIFO和LRU页面置换程序，模拟操作系统存储器管理功能，以帮助学生深刻理解操作系统如何采用请求分页方式来实现虚拟存储技术。

**2.** **实验内容提要**

（1）定义相关数据结构

（2）设计开发页面置换程序

（3）调试程序，查看结果

**3****．输入数据**

（1）分配的物理块数3

（2）页面走向4 3 2 1 4 3 5 4 3 2 1 5 0

**4****．注意事项**

（1）输出时明确指出每个页面被访问时的情况：

发生缺页中断，X号页面调入内存

发生页面置换，将X号页面调入内存，Y页面调出内存

命中

（2）最后计算缺页率

 
