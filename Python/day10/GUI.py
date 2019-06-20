import tkinter
import tkinter.messagebox

def main():
    flag = True

    # 修改标签上的文字
    def change_label_text():
        nonlocal flag
        flag = not flag
        color, msg = ('red', 'Hello, world!') if flag else ('blue', 'Hello, Python!')
        label.config(text=msg, fg=color)

    # 确认退出
    def confirm_to_quit():
        if tkinter.messagebox.askokcancel('温馨提示', '确定要退出吗？'):
            top.quit()

    top = tkinter.Tk()

    top.geometry('400x400')

    top.title('小游戏')

    label = tkinter.Label(top, text='Hello, world!', font='Arial -32', fg='red')
    label.pack(expand=1)

    panel = tkinter.Frame(top)

    btn1 = tkinter.Button(panel, text='修改', command=change_label_text)
    btn1.pack(side='left')
    btn2 = tkinter.Button(panel, text='退出', command=confirm_to_quit)
    btn2.pack(side='right')
    panel.pack(side='bottom')

    tkinter.mainloop()


if __name__ == '__main__':
    main()