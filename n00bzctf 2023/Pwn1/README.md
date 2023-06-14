# Pwn1
We are given a connection to a server and a binary that runs there. <br>
First of all we want to decompile the binary. <br>
In <i>main</i> function the program takes input from user then returns fake flag. <br>
![preview](images/1.png)

We can also see that there is another function called <i>win</i> which returns shell. <br>
![preview](images/2.png)
### Solution
This code takes 80 bytes from user and tries to put it in 64 byte char table. That leads to overflow and we can use it to redirect code execution to <i>win</i> function. <br>
So we can just enter payload consisting of 72 bytes of padding and 8 bytes long address of <i>win</i> function<br> which we can check in gdb <br>
![preview](images/3.png)
![preview](images/4.png)
