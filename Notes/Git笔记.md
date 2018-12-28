# Git笔记

## 1. Git常用命令

+ 获得版本库
  + `git init`
  + `git clone`

+ 版本管理
  + `git add`
  + `git commit`
  + `git rm`
+ 查看信息
  + `git help`
  + `git log`
  + `git diff`
+ 远程协作
  + `git pull`
  + `git push`

---

`git log`查看提交记录

`git log -3`，查看最近三条的提交记录

`git log --pretty=oneline `，以单行的形式查看提交记录

`git log --pretty=format:"%h - %an,%ar : %s"`，以特定格式显示提交记录

---

Git的提交id（commit id）是一个摘要值，这个摘要值实际上是用sha1计算出来的。

---

`git checkout -- 文件名/文件夹名`，丢弃提交

---

对于user.name与user.email来说，有3个地方可以设置

1. `/etc/gitconfig`（几乎不会使用，如果使用的是Xcode自带的git的话这个目录是不存在的，需要手动创建），`git config --system`
2. `~/.gitconfig`（很常用），`git config --global`
3. 针对特定项目的，`.git/config`文件中，`git config --local`

上面三个设置，优先级由上到下递减，也就是说在3中配置了，会屏蔽掉1，2的配置。

`git config --local user.name '张三'`

`git config --local user.email '123@abc.com'`

查看文档：`git help config`  `git config --help`  `man git-config` `git config`

`git config user.name`：查看用户名

`git config user.email`：查看用户邮箱

----

注意：`git rm`与`rm`

`git mv`，rename

---

`git add --all` <==> `git add .`

提交描述信息写错了，需要修改，使用`git commit --amend -m "修正msg"`

## 2. `.gitignore`

`.gitignore`文件需要手动创建，将需要忽略的文件名放在这个文件中，支持增则表达式。

一些栗子：

要忽略项目目录下的`test.xcodeproject`文件，将文件名写入即可。

忽略项目目录下所有的`.xcodeproject`工程文件，则`*.xcodeproject`。

`!a.xcodeproject`，a.xcodeproject这个工程文件不忽略。

+ `*.c`#忽略所有以.c为后缀的文件
+ `!lib.c`#但是lib.c除外
+ `/TODO`#仅仅忽略项目根目录下的TODO文件，不包括subdir/TODO
+ `build/`#忽略build目录下的所有文件
+ `doc/*.txt`#会忽略doc/notes.txt，但不会忽略doc/server/arch.txt
+ `/*/test.txt`，忽略根目录下第一级子目录下的test.txt文件
+ `/**/test.txt`，忽略根目录下所有子目录里的test.txt文件

## 3. 分支branch

查看当前分支：`git branch`

新建分支：`git branch new_branch`

切换分支：`git checkout new_branch`

快捷切换回上一次的分支：`git checkout -`，这个和`cd -`类似

删除分支：`git branch -d new_branch`

​	**删除分支常见错误**：

​	1. 删除当前正处于的分支

```
error: 无法删除检出于 '/Users/hanoi_ahoj/mtgit' 的分支 'new_branch'。
```

​	2. 删除一个没有合并的分支

```
error: 分支 'new_branch' 没有完全合并。
如果您确认要删除它，执行 'git branch -D new_branch'
```

合并分支：`git merge new_branch`

### HEAD

HEAD指向的是当前分支

（HEAD保存在.git目录下的HEAD文件里，cat HEAD看一看）

### master

master本质上指向提交

+ HEAD指向当前分支

![1.png](https://wx2.sinaimg.cn/mw690/006wR0dcly1fy350gkfyhj31c00u0mxd.jpg)

+ 新建一个分支：dev

  ![2.png](https://wx1.sinaimg.cn/mw690/006wR0dcly1fy350glycpj31c00u00sz.jpg)

+ 在dev分支上进行了一次commit

  ![3.png](https://wx2.sinaimg.cn/mw690/006wR0dcly1fy350gq3cxj31c00u0q38.jpg)

+ fast-forward(即快进，快速合并，没有冲突)

  ![4.png](https://wx3.sinaimg.cn/mw690/006wR0dcly1fy350gmdrsj31c00u0wes.jpg)

+ 如果两个分支修改的同一个文件的同一行，在合并的时候Git是不知道以master为准还是别的分支为准，这时就会提示冲突，这个时候看这个文件的内容就会发现里面的内容被Git用自己的方式标注出来了冲突的地方，需要自己手动处理冲突。解决完后使用`git add file_name`来告诉Git这个冲突已经解决了。当在master分支中解决了这一个冲突后，在dev分支中再进行合并master分支，就不会提示冲突了，而是fast-forward。

# Mac/Linux下一些小技巧

优秀的工具：oh my zsh

拷贝文件`cp`，移动文件`mv`（也用来重命名）

当不想输入当前命令，可以使用`ctrl+c`

`rm -rf 文件夹名`，递归的删除文件夹

`ctrl+l`，相当于`clear`，清屏幕

`ctrl+a`，跳到当前命令的开头，`ctrl+e`，跳到当前命令的结尾

`l`，相当于`ls -al`，显示当前目录下所有文件，包括隐藏文件

`ctrl+f`，向下翻页，`ctrl+b`，向上翻页

`mkdir -p test/test1/test2`，递归建立多个目录

快速切换回上次的文件夹：`cd -`

同时执行多条命令：`mkdir mydir && cd mydir`

`.`代表当前目录，`..`代表上一级目录

