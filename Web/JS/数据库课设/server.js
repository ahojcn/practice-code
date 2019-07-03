const http = require('http');
const mysql = require('mysql');
const url = require('url');
const querystring = require('querystring');

const STUDENTLOGIN = '/studentLogin'; // 学生登录
const TEACHERLOGIN = '/teacherLogin'; // 教师登录

const GET_STUDENT_INFO = '/students/getInfo'; // 获取学生个人信息
const GET_STUDENT_CHOSE = '/students/getChose'; // 获取学生选课信息

const GET_ALL_COURSE = '/course/getAll'; // 获取所有课程选题

const STUDENT_CHOSE_COURSE = '/students/choseCourse'; // 学生选课
const STUDENT_CANCEL_COURSE = '/students/cancelCourse'; // 学生取消选课

const TEACHER_GET_ALL_COURSE = '/teacher/getAllCourse'; // 老师获取自己的选课
const TEACHER_GET_STUDENTS_INFO = '/teacher/getStudentsInfo'; // 老师获取选自己的课题的学生
const TEACHER_PUT_STUDENT_GRADE = '/teacher/putStudentGrade'; // 老师给学生打分
const TEACHER_SEND_MSG = '/teacher/sendMsg'; // 老师给学生评价


// router
function router(req, res, db, pathname, query) {
    console.log('----------------- ⤵️ ----------------');
    console.log(new Date().toLocaleTimeString())
    console.log(pathname, query);
    // 路由
    if (pathname === STUDENTLOGIN) {
        studentLogin(res, db, query);
    } else if (pathname === TEACHERLOGIN) {
        teacherLogin(res, db, query);
    } else if (pathname === GET_STUDENT_INFO) {
        getStudentInfo(res, db, query);
    } else if (pathname === GET_STUDENT_CHOSE) {
        getStudentChose(res, db, query);
    } else if (pathname === GET_ALL_COURSE) {
        getAllCourse(res, db, query);
    } else if (pathname === STUDENT_CHOSE_COURSE) {
        studentChoseCourse(res, db, query);
    } else if (pathname === STUDENT_CANCEL_COURSE) {
        studentCancelCourse(res, db, query);
    } else if (pathname === TEACHER_GET_ALL_COURSE) {
        teacherGetAllCourse(res, db, query);
    } else if (pathname === TEACHER_GET_STUDENTS_INFO) {
        teacherGetStudentsInfo(res, db, query);
    } else if (pathname === TEACHER_PUT_STUDENT_GRADE) {
        teacherPutStudentGrade(res, db, query);
    } else if (pathname === TEACHER_SEND_MSG) {
        teacherSendMsg(res, db, query);
    } else {
        requestTo(res, "404 not found.", -404, "404 not found.")
    }
}


// 建立数据库连接，返回连接对象
function connectDatabase() {
    return mysql.createConnection({
        host: '192.168.1.112',
        user: 'root',
        password: '123',
        database: 'test'
    })
}

// 返回数据
function requestTo(res, msg, status, data) {
    let j = {
        msg: msg,
        status: status,
        data: data
    }
    res.write(JSON.stringify(j));
    res.end();
}

// 老师给学生发消息
// sno 学生号, pno 课程号, word 说的话
function teacherSendMsg(res, db, query) {
    db.query(`
    insert into says(sno, pno, msg, word, isread)
    value(${query.sno}, ${query.pno}, '老师给学生的意见', ${(query.word).toString()}, 0);`,
        function (err, data) {
            if (err) {
                requestTo(res, "faild", -2, err);
                console.log(err);
            } else {
                requestTo(res, "success", 0, data);
            }
        });
}

// 老师给学生打分
// sno 学生no
function teacherPutStudentGrade(res, db, query) {
    db.query(`
    update students set gender = 0
    where sno = ${query.sno};`,
        function (err, data) {
            if (err) {
                requestTo(res, "faild", -2, err);
            } else {
                requestTo(res, "success", 0, data);
            }
        });
}

// 老师获取选自己课题的学生
// tno 老师的no
function teacherGetStudentsInfo(res, db, query) {
    db.query(`
    select distinct course.pno, course.pname, students.sno, students.sname, students.sex, students.tel, students.gender
    from course, teacher, students
    where students.pno = course.pno and course.tno = ${query.tno};`,
        function (err, data) {
            if (err) {
                requestTo(res, "没有查到相关信息", -2, err)
            } else {
                requestTo(res, "success", 0, data)
            }
        });
}

// 获取学生个人信息
// sno
function getStudentInfo(res, db, query) {
    db.query(`
    select classes.cname, students.sno, students.sname, students.tel, students.gender
    from classes, students
    where students.cno = classes.cno and students.sno = ${query.sno}`,
        function (err, data) {
            if (err) {
                requestTo(res, "没有这个学生信息", -2, "")
            } else {
                data = JSON.stringify(data);
                // 没有查到信息
                if (data === '[]') {
                    requestTo(res, "没有这个学生信息", -2, "")
                } else {
                    data = JSON.parse(data);
                    requestTo(res, "success", 0, data)
                }
            }
        });
}

// 获取学生选课信息
// sno
function getStudentChose(res, db, query) {
    db.query(`
    select students.pno, students.sno, students.gender
    from students
    where students.sno = ${query.sno}`,
        function (err, data) {
            if (err) {
                requestTo(res, "没有此学生信息", -2, "");
            } else {
                data = JSON.stringify(data);
                // 没有查到信息
                if (data === '[]') {
                    requestTo(res, "没有此学生信息", -2, "");
                } else {
                    // 学生没有选课
                    data = JSON.parse(data);
                    if (data[0].pno === null) {
                        requestTo(res, "success", 0, data);
                    } else {
                        // 学生选课了
                        db.query(`select students.pno, students.sno, course.pname, students.gender
                        from students,course
                        where students.sno = ${query.sno}
                        and course.pno = students.pno;`,
                            function (err, info) {
                                if (err) {
                                    requestTo(res, "faild", -2, err);
                                } else {
                                    requestTo(res, "success", 0, info);
                                }
                            });
                    }
                }
            }
        })
}

// 获取所有可选题课程
// 无参数
function getAllCourse(res, db, query) {
    db.query(`
    select course.pno, course.pname, teacher.tname, course.zong
    from course, teacher
    where course.tno = teacher.tno`,
        function (err, data) {
            if (err) {
                requestTo(res, "faild", -2, "");
            } else {
                requestTo(res, "success", 0, data);
            }
        });
}

// 学生选课
// pno 课程号; sno 学生学号
function studentChoseCourse(res, db, query) {
    db.query(`
    update students set pno = ${query.pno}
    where sno = ${query.sno};`,
        function (err, data) {
            if (err) {
                requestTo(res, "failed", -2, err);
            } else {
                requestTo(res, "successed", 0, data);
            }
        });
}

// 学生取消选课
// pno 课程号；sno 学生号
function studentCancelCourse(res, db, query) {
    db.query(`
    update students set pno = null
    where sno = ${query.sno};`,
        function (err, data) {
            if (err) {
                requestTo(res, "failed", -2, err);
            } else {
                requestTo(res, "successed", 0, data);
            }
        });
}

// 教师获取自己带的课
// tno 教师号
function teacherGetAllCourse(res, db, query) {
    db.query(`
    select course.pname, course.zong
    from course
    where course.tno = ${query.tno};`,
        function (err, data) {
            if (err) {
                requestTo(res, "failed", -2, err);
            } else {
                requestTo(res, "successed", 0, data);
            }
        });
}

// 学生登录
// sno, password
function studentLogin(res, db, query) {
    console.log(query.sno, query.password);
    db.query(`SELECT sno,password FROM students where sno = ${query.sno}`, function (err, data) {
        if (err) {
            requestTo(res, "用户名或密码错误", -1, "")
        } else {
            data = JSON.stringify(data);
            // 没有查到信息
            if (data === '[]') {
                requestTo(res, "用户名或密码错误", -1, "")
            } else {
                data = JSON.parse(data);
                sno = data[0].sno;
                password = data[0].password;
                db.query(`SELECT cno,pno,sno,sname,sex,tel,gender FROM students where sno = ${query.sno}`, function (err, info) {
                    if (err) {
                        requestTo(res, err.sqlMessage, -1, "")
                    } else {
                        requestTo(res, "success", 0, info)
                    }
                })
            }
        }
    });
}

// 教师登录
// tno, password
function teacherLogin(res, db, query) {
    db.query(`SELECT tno,password FROM teacher where tno = ${query.tno}`, function (err, data) {
        if (err) {
            requestTo(res, "用户名或密码错误", -1, "")
        } else {
            data = JSON.stringify(data);
            // 没有查到信息
            if (data === '[]') {
                requestTo(res, "用户名或密码错误", -1, "")
            } else {
                data = JSON.parse(data);
                tno = data[0].tno;
                password = data[0].password;
                db.query(`SELECT tno,tname,yno FROM teacher where tno = ${query.tno}`, function (err, info) {
                    if (err) {
                        requestTo(res, err.sqlMessage, -1, "")
                    } else {
                        requestTo(res, "success", 0, info)
                    }
                })
            }
        }
    });
}

let server = http.createServer(function (req, res) {
    // 跨域请求头
    res.setHeader('access-control-allow-origin', '*');
    res.write('<head><meta charset="utf-8"/></head>');

    // 建立数据库连接
    let db = connectDatabase();

    // 解析请求
    let {
        pathname,
        query
    } = url.parse(req.url, true);

    // 路由跳转
    router(req, res, db, pathname, query);
});

server.listen(41366);