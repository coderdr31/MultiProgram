#!/usr/bin/python
# coding=utf-8

# Queue封装了Condition的行为，如wait()&notify()，acquire()&release()
# 这个队列有一个condition，它有自己的lock。如果你使用Queue，你不需要为condition和lock而烦恼。

from threading import Thread, Lock
import time
import random
from Queue import Queue
import curses

len = 100
queue = Queue(6)
for i in range(1, 4):  # 绳子3米
    queue.put(0)
    pass
lock = Lock()


class ProducerThread(Thread):
    i = 0
    def run(self):
        global queue
        while True:
            if(self.i == len):
                break
            queue.put(0)  # put()在插入数据前有一个获取lock的逻辑
            # 同时，put()也会检查队列是否已满。如果已满，它会在内部调用wait()，生产者开始等待
            self.i += 1
            lock.acquire()
            #print "Ploice", self.i
            changeframe(self.screen)
            lock.release()
            time.sleep(random.random())
    def getscreen(self, screen):
        self.screen = screen


class ConsumerThread(Thread):
    i = 0
    def run(self):
        global queue
        while True:
            if(self.i == len):
                break
            num = queue.get()
            # get()从队列中移出数据前会获取lock. get()会检查队列是否为空，如果为空，消费者进入等待状态。
            self.i += 1
            queue.task_done()
            lock.acquire()
            #print "thief", self.i
            changeframe(self.screen)
            lock.release()
            time.sleep(random.random())
    def getscreen(self, screen):
        self.screen = screen

def changeframe(screen):
    screen.clear()
    for i in range(5,105):
        # from ipdb import set_trace
        # set_trace()
        screen.addstr(12, i, "_")
        screen.addstr(17, i, "_")
    screen.addstr(14, po.i, "P", curses.color_pair(2))
    screen.addstr(16, th.i, "T", curses.color_pair(3))
    screen.addstr(12,po.i,"%d" % po.i)
    screen.addstr(18,th.i,"%d" % th.i)
    screen.refresh() #要刷新
po = ProducerThread()
th = ConsumerThread()
def main(stdscreen):
    po.getscreen(stdscreen)
    th.getscreen(stdscreen)
    curses.init_pair(1, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_WHITE, curses.COLOR_RED)
    curses.init_pair(3, curses.COLOR_WHITE, curses.COLOR_GREEN)

    stdscreen.clear()
    stdscreen.border(0)
    stdscreen.addstr(12, 20, "1. Start Police & Thief", curses.color_pair(1))
    stdscreen.addstr(14, 20, "2. Exit ", curses.color_pair(1))
    stdscreen.refresh()
    x = stdscreen.getch()
    if x == ord('1'):
        po.start()
        th.start()
        changeframe(stdscreen)
    if x == ord('2'):
        curses.endwin()

if __name__ == '__main__':
    curses.wrapper(main)


#ProducerThread().start()
#ConsumerThread().start()
