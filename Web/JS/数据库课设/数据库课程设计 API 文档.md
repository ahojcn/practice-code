## 数据库课程设计 API 文档

所有接口返回值中的 status 代表成功还是失败，成功为0，所有的失败都是小于 0 的。

所有请求均为 post 请求。

服务器根地址：

```url
http://ahojcn.natapp1.cc
```

### 登录

#### 学生登录

地址：

```
/studentLogin
```

参数：

```
sno 学号 Int
password 密码 String
```

返回值：

```json
# 失败
{
    "msg": "用户名或密码错误",
    "status": -1,
    "data": ""
}

# 成功
{
    "msg": "success",
    "status": 0,
    "data": [
        {
            "cno": 1701,
            "pno": 1,
            "sno": 417083101,
            "sname": "孙悟空",
            "sex": "男",
            "tel": 13093944163,
            "gender": 60
        }
    ]
}
```

#### 教师登录

地址：

```
/teacherLogin
```

参数：

```
tno 教师号 Int
password 密码 String
```

返回值：

```json
# 成功
{
    "msg": "success",
    "status": 0,
    "data": [
        {
            "tno": 41701,
            "tname": "天上老君",
            "yno": 1
        }
    ]
}

# 失败
{
    "msg": "用户名或密码错误",
    "status": -1,
    "data": ""
}
```

### 学生

#### 获取学生信息

地址：

```
/students/getInfo
```

参数：

```
sno 学号 Int
```

返回：

```json
# 成功
{
    "msg": "success",
    "status": 0,
    "data": [
        {
            "cname": "计卓一班",
            "sno": 417083101,
            "sname": "孙悟空",
            "tel": 13093944163
        }
    ]
}

# 失败
{
    "msg": "没有这个学生信息",
    "status": -2,
    "data": ""
}
```

#### 获取学生选课信息

地址：

```
/students/getChose
```

参数：

```
sno 学号 Int
```

返回：

```json
# 失败
{
    "msg": "没有此学生信息",
    "status": -2,
    "data": ""
}

# 成功
# 学生未选课，data.pno = null
{
    "msg": "success",
    "status": 0,
    "data": [
        {
            "pno": null,
            "sno": 417083102
        }
    ]
}

# 学生选课了，data.pno != null
{
    "msg": "success",
    "status": 0,
    "data": [
        {
            "pno": 1,
            "sno": 417083101,
            "pname": "客户订购登记系统"
        }
    ]
}
```

#### 选一门课

地址：

```
/students/choseCourse
```

参数：

```
pno 课程号 Int
sno 学生学号 Int
```

返回示例：

```json
# 成功
{
    "msg": "successed",
    "status": 0,
    "data": { # 不用管
        "fieldCount": 0,
        "affectedRows": 1,
        "insertId": 0,
        "serverStatus": 2,
        "warningCount": 0,
        "message": "(Rows matched: 1  Changed: 1  Warnings: 0",
        "protocol41": true,
        "changedRows": 1
    }
}

# 失败
{
    "msg": "failed",
    "status": -2,
    "data": { # 不用管
        "code": "ER_BAD_FIELD_ERROR",
        "errno": 1054,
        "sqlMessage": "Unknown column '4170831a' in 'where clause'",
        "sqlState": "42S22",
        "index": 0,
        "sql": "\n    update students set pno = 1\n    where sno = 4170831a;"
    }
}
```

#### 学生取消选课

地址：

```
/students/cancelCourse
```

参数：

```
pno 课程号 Int
sno 学生号 Int
```

返回示例：

```json
# 成功
{
    "msg": "successed",
    "status": 0,
    "data": { # 不用管
        "fieldCount": 0,
        "affectedRows": 1,
        "insertId": 0,
        "serverStatus": 2,
        "warningCount": 0,
        "message": "(Rows matched: 1  Changed: 1  Warnings: 0",
        "protocol41": true,
        "changedRows": 1
    }
}

# 失败
{
    "msg": "failed",
    "status": -2,
    "data": { # 不用管
        "code": "ER_BAD_FIELD_ERROR",
        "errno": 1054,
        "sqlMessage": "Unknown column '417083101a' in 'where clause'",
        "sqlState": "42S22",
        "index": 0,
        "sql": "\n    update students set pno = null\n    where sno = 417083101a;"
    }
}
```



### 课程

#### 获取课程信息

地址：

```
/course/getAll
```

参数：

```
无
```

返回示例：

```json
# 成功
{
    "msg": "success",
    "status": 0,
    "data": [
        {
            "pno": 1, # 课程 id
            "pname": "客户订购登记系统", # 课程名
            "tname": "天上老君", # 指导老师
            "zong": 4 # 课程余量
        },
        {
            "pno": 2,
            "pname": "货存控制系统",
            "tname": "天上老君",
            "zong": 4
        },
        {
            "pno": 3,
            "pname": "人力资源管理系统",
            "tname": "天上老君",
            "zong": 4
        },
        {
            "pno": 4,
            "pname": "工资管理系统",
            "tname": "通天教主",
            "zong": 4
        },
        {
            "pno": 5,
            "pname": "学生管理系统",
            "tname": "通天教主",
            "zong": 4
        },
        {
            "pno": 6,
            "pname": "学校图书管理系统",
            "tname": "原始天尊",
            "zong": 4
        },
        {
            "pno": 7,
            "pname": "课程设计选题系统",
            "tname": "九天伏魔祖师",
            "zong": 4
        }
    ]
}

# 失败
{
    msg: "don't have this course info.",
    status: -2,
    data: ""
}
```



### 教师

#### 获取自己所带的选题信息

地址：

```
/teacher/getAllCourse
```

参数：

```
tno 教师号 Int
```

返回示例：

```json
# 成功
{
    "msg": "successed",
    "status": 0,
    "data": [
        {
            "pname": "客户订购登记系统",
            "zong": 4
        },
        {
            "pname": "货存控制系统",
            "zong": 4
        },
        {
            "pname": "人力资源管理系统",
            "zong": 4
        }
    ]
}

# 失败
{
    msg: "don't have this course info.",
    status: -2,
    data: ""
}
```



### 404

```json
{
  msg: "404 not found.",
  status: -404,
  data: "404 not found."
}
```

