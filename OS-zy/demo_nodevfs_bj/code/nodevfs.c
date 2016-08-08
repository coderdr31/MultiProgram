//nodevfs.c

#ifndef __KERNEL__   /*表明这将是用于内核的代码*/
#define __KERNEL__
#endif

#ifndef MODULE     /*表明这是以模块方式进行编译的驱动程序*/
#define MODULE
#endif

#include <linux/config.h>
#include <linux/module.h>
#include <linux/devfs_fs_kernel.h>
#include <linux/init.h>
#include <linux/kernel.h>   /* printk() */
#include <linux/slab.h>   /* kmalloc() */
#include <linux/fs.h>
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>    /* O_ACCMODE */
#include <linux/poll.h>    /* COPY_TO_USER */
#include <asm/system.h>     /* cli(), *_flags */

#define DEVICE_NAME "evan"
#define evan_MAJOR 99
#define evan_MINOR 0
static int MAX_BUF_LEN=1024;
static char drv_buf[1024];
static int WRI_LENGTH=0;

static void do_write()
{

    char H,L,dir;
    char moveh[4]={0,1,0,-1};
    char movel[4]={1,0,-1,0};
    char map[100][100];
    char th, tl, tc, tms;
    H = drv_buf[0];
    L = drv_buf[1];
    dir = 0,th = 0,tl = 0,tc = 0;
    int i, j;
    tms = H * L;
    for(i = 0; i < H; i ++)
        for(j = 0; j < L; j ++)	map[i][j] = -1;
    while(tms--)
    {
        map[th][tl] = tc;
        tc = (tc+1)%26;
        int nh = th + moveh[dir];
        int nl = tl + movel[dir];
        if(nh >= H || nh < 0 || nl >= L || nl < 0 || map[nh][nl] != -1)
        {
            dir = (dir + 1)%4;
        }
        th = th + moveh[dir];
        tl = tl + movel[dir];
    }
    for(i = 0; i < H; i ++)
        for(j = 0; j < L; j ++)
            drv_buf[i*L+j]= map[i][j];
}


static ssize_t evan_write(struct file *filp, char *buffer, size_t count)
{
    if (count>MAX_BUF_LEN) count=MAX_BUF_LEN;
    copy_from_user(drv_buf,buffer,count);
    WRI_LENGTH=count;
    printk("user write data to drivers!\n");
    do_write();
    return count;
}
/*在本程序中，copy_from_user(drv_buf,buffer,count);表示从用户空间的buffer缓冲区传
  递数据到内核空间的drv_buf之中，长度为count。*/


static ssize_t evan_read(struct file *filp, char *buffer, size_t count,loff_t *ppos)
{
    if (count>MAX_BUF_LEN) count=MAX_BUF_LEN;
    copy_to_user(buffer,drv_buf,count);
    printk("user read data from drivers!\n");
    do_write();
    return count;
}
/*在本程序中，copy_to_user(buffer,drv_buf,count);表示从内核空间的drv_buf缓冲区
  传递数据到用户空间的buffer之中，长度为count。*/

static int evan_ioctl(struct inode *inode,struct file *file,unsigned int cmd,unsigned long arg)
{
    printk("ioctl running!\n");
    switch(cmd)
    {default:break;}
    return 0;
}
/*  opctl方法是除了读写操作之外，对设备的控制方法。一般使用switch操作进行编码。*/

static int evan_open(struct inode *inode,struct file *file)
{
    MOD_INC_USE_COUNT;
    sprintf(drv_buf,"device open success!\n"); //输入到drv_buf
    printk("device open success!\n");
    return 0;
}
/* 　　当设备被激活之后，就会调用该方法。open方法主要提供给设备初始化的能力。而且如果驱动程序作为一个模块被装入之后，需要防止模块卸载的时候设备处于打开状态，所以需要进行设备计数。因此，open方法的作用主要如下：
 * 递增使用计数。
 * 检查特定设备错误。
 * 初始化特定设备。
 */

static int evan_release(struct inode *inode,struct file *filp)
{
    MOD_DEC_USE_COUNT;
    printk("device open success!\n");
    return 0;
}
/*close方法和open正好做相反的工作，用来关闭设备。同时如果驱动程序作为模块装入，则需要减少设备被引用的次数来方便驱动程序被卸载。因此，close方法的作用主要如下：
 * 释放资源，减少系统负担。
 * 关闭设备。
 * 使用计数递减。
 */

static struct file_operations evan_fops=
{
owner:	THIS_MODULE, //拥有者
        write:	evan_write,
        read:	evan_read,
        ioctl:	evan_ioctl, //控制操作
        open:	evan_open,  //打开操作
        release:	evan_release,  //释放操作
};

static int __init evan_init(void)   // 初始化evan设备
{
    int result;  　　//定义返回值
        SET_MODULE_OWNER(&evan_fops);//定义拥有者
    result=register_chrdev(evan_MAJOR,"evan",&evan_fops);//注册evan设备，使用操作集:主设备号,设备名称,设备的文件操作数据结构指针
    if(result<0) return result; 　　//出错就返回return
        printk(DEVICE_NAME " initialized\n"); 　　//打印设备初始化
            return 0;  　　//成功返回0值
}

static void __exit evan_exit(void)  　　//退出
{
    unregister_chrdev(evan_MAJOR,"evan");  　　//注销99号设备，evan
        printk(DEVICE_NAME " unloaded\n");  　　//打印信息
}

module_init(evan_init);  　　//加载该驱动程序，需要执行evan_init。
module_exit(evan_exit); 　　//退出该驱动程序，需要执行evan_exit。

