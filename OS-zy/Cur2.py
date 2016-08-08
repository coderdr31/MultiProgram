#!/usr/bin/python
# coding=utf-8
from os import system #system需要
import curses
def main(stdscreen):

    curses.init_pair(1, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_WHITE, curses.COLOR_BLACK)
    curses.init_pair(3, curses.COLOR_RED, curses.COLOR_BLACK)
    curses.init_pair(4, curses.COLOR_GREEN, curses.COLOR_BLACK)
    curses.init_pair(5, curses.COLOR_YELLOW, curses.COLOR_BLACK)

    stdscreen.clear()
    stdscreen.border(0) #边框
    stdscreen.addstr(6, 20, "1. fork", curses.color_pair(1))
    stdscreen.addstr(8, 20, "2. signal", curses.color_pair(2))
    stdscreen.addstr(10, 20, "3. pipe", curses.color_pair(3))
    stdscreen.addstr(12, 20, "4. popen", curses.color_pair(4))
    stdscreen.addstr(14, 20, "5. fifo", curses.color_pair(5))

    stdscreen.refresh()
    x = stdscreen.getch()
    if x == ord('1'):
        # stdscreen.clear()
        # stdscreen.refresh()
        curses.endwin()
        system("./process/1_fork/fork")
        stdscreen.getch() #使其等待输入，暂停
        curses.wrapper(main) #wrapper把初始化和结束等封装，循环调用main
    if x == ord('2'):
        curses.endwin()
        system("./process/2_signal/signal")
        stdscreen.getch()
        curses.wrapper(main)
    if x == ord('3'):
        curses.endwin()
        system("cd ./process/3_pipe && ./pipe")
        stdscreen.getch()
        curses.wrapper(main)
    if x == ord('4'):
        curses.endwin()
        system("./process/4_popen/popen")
        stdscreen.getch()
        curses.wrapper(main)
    if x == ord('5'):
        curses.endwin()
        system("./process/5_fifo/fifo2 &")
        system("./process/5_fifo/fifo1")
        stdscreen.getch()
        curses.wrapper(main)


if __name__ == '__main__':
    curses.wrapper(main)

