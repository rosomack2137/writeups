# Pwn1
We are given a connection to a server and a binary that runs there. <br>
First of all we want to decompile the binary. <br>
In <i>main</i> function the program takes input from user then returns fake flag. <br>
![preview](images/)

We can also see that there is another function called <i>win</i> which returns shell. <br>
![preview](images/)
### Solution
This code takes 80 bytes from user and tries to put it in 64 byte char table. That leads to overflow and we can use it to redirect code execution to win function. <br>
Now we open gdb, input some 80 bytes string with recognizable pattern and see what happens<br>
