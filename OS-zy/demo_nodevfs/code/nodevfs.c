//nodevfs.c

#ifndef __KERNEL__
#define __KERNEL__
#endif

#ifndef MODULE
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

static ssize_t evan_read(struct file *filp, char *buffer, size_t count,loff_t *ppos)
{
if (count>MAX_BUF_LEN) count=MAX_BUF_LEN;
copy_to_user(buffer,drv_buf,count);
printk("user read data from drivers!\n");
do_write();
return count;
}

static int evan_ioctl(struct inode *inode,struct file *file,unsigned int cmd,unsigned long arg)
{
printk("ioctl running!\n");
switch(cmd)
{default:break;}
return 0;
}

static int evan_open(struct inode *inode,struct file *file)
{
MOD_INC_USE_COUNT;
sprintf(drv_buf,"device open success!\n");
printk("device open success!\n");
return 0;
}

static int evan_release(struct inode *inode,struct file *filp)
{
MOD_DEC_USE_COUNT;
printk("device open success!\n");
return 0;
}

static struct file_operations evan_fops=
{
owner:	THIS_MODULE,
write:	evan_write,
read:	evan_read,
ioctl:	evan_ioctl,
open:	evan_open,
release:	evan_release,
};

static int __init evan_init(void)
{
int result;
SET_MODULE_OWNER(&evan_fops);
result=register_chrdev(evan_MAJOR,"evan",&evan_fops);
if(result<0) return result;
printk(DEVICE_NAME " initialized\n");
return 0;
}

static void __exit evan_exit(void)
{
unregister_chrdev(evan_MAJOR,"evan");
printk(DEVICE_NAME " unloaded\n");
}

module_init(evan_init);
module_exit(evan_exit);
