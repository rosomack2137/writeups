# sequence_gallery
In this challenge we have a website which takes parameter from our get request, adds <i>.dc</i> to this text and passes it as a parameter to `subprocess.run()`

It is intended to run one of scripts on the server. Also our parameter can't contain any spaces or `flag` string.<br>
![preview](images/1.png)<br>
### Solution
My first approach was to just try to inject a bash command, but `subprocess.run()` treats every string in list as separate argument no matter how many semicolons we use. So second thing that came
across my mind was to try make this second argument a command switch such as `--help` or `--expression`. So I looked into GNU dc documentation and saw that `!` in expression makes the rest of input 
treated as a system command. The last thing is to evade filters on `flag` and ` `. We can replace ` ` with `$IFS` which is bash variable for Internal Field Separator and we can separate `fl` and `ag` with
`$()`. At last we should add semicolon to ignore `.dc` which is added by the script. Final payload looks like this:
```
http://sequence-gallery.chal.crewc.tf:8080/?sequence=--expression=!cat${IFS}fl$()ag.txt;
```
