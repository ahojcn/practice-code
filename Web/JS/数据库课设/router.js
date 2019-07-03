const STUDENTLOGIN = '/studentLogin'; // 学生登录
const TEACHERLOGIN = '/teacherLogin'; // 教师登录
const GET_STUDENT_INFO = '/students/getInfo'; // 获取学生个人信息
const GET_STUDENT_CHOSE = '/students/getChose'; // 获取学生选课信息
const GET_ALL_COURSE = '/course/getAll'; // 获取所有课程选题
const STUDENT_CHOSE_COURSE = '/students/choseCourse'; // 学生选课
const STUDENT_CANCEL_COURSE = '/students/cancelCourse'; // 学生取消选课
const TEACHER_GET_ALL_COURSE = '/teacher/getAllCourse'; // 老师获取自己的选课

// router
export function router(req, res, db, pathname, query) {
    // 路由跳转
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
    } else {
        requestTo(res, "404 not found.", -404, "404 not found.")
    }
}