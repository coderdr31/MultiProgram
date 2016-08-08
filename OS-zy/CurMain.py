#!/usr/bin/python
#coding=utf-8
#!/usr/bin/env python

#http://www.cnblogs.com/starof/p/4703820.html?spm=5176.100239.blogcont49801.5.hbnizB
from os import system
import curses
from Cur2 import main

def get_param(prompt_string):
    screen.clear()
    screen.border(0)
    screen.addstr(2, 2, prompt_string)
    screen.refresh()
    input = screen.getstr(10, 10, 60)
    return input

def execute_cmd(cmd_string):
    system("clear")
    a = system(cmd_string)
    print ""
    if a == 0:
        print "Command executed correctly"
    else:
        print "Command terminated with error"
    raw_input("Press enter")
    print ""

x = 0

while x != ord("9"):
    screen = curses.initscr() #初始化
    curses.start_color()

    curses.init_pair(1, curses.COLOR_RED, curses.COLOR_WHITE)
    screen.clear()
    screen.border(0)
    screen.addstr(2, 2, "Please enter a number to choose")
    screen.addstr(4, 4, "1 - show the luoxuan")
    screen.addstr(5, 4, "2 - add users")
    screen.addstr(6, 4, "3 - del users")
    screen.addstr(7, 4, "4 - Police&Thief")
    screen.addstr(8, 4, "5 - PhilosophersDinner")
    screen.addstr(9, 4, "---------------------------------------------------------")
    screen.addstr(10, 4, "6 - Process")
    screen.addstr(11, 4, "7 -shell" )
    screen.addstr(15, 4, "9 - EXIT")
    screen.refresh()

    x = screen.getch()

    if x == ord('9'):
        curses.endwin()

    if x == ord('1'):
        curses.endwin()
        execute_cmd("g++ luoxuan.cpp -o lx.out  && ./lx.out")

    if x == ord('2'):
        curses.endwin()
        execute_cmd("./adduser")
    if x == ord('3'):
        curses.endwin()
        execute_cmd("./deluser")
        pass
    if x == ord('4'):
        curses.endwin()
        execute_cmd("python PoliceThief.py")
        pass

    if x == ord('5'):
        curses.endwin()
        execute_cmd("make philosopher")
        pass
    if x == ord('6'):
        curses.endwin()
        curses.wrapper(main) #本文件没main，调用Cur2的main
        # curses.noecho() #关闭回显
        curses.cbreak() #不用按回车 就立即响应
    pass
    if x == ord ('7'):
        curses.endwin()
        execute_cmd("./wshell")

curses.endwin()
