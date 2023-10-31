#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>

static char buf[] = "hello!";
static char buf1[10];
int hello_init(void)
{
    struct  file *fp;
    mm_segment_t fs;
    loff_t pos;
    printk("hello enter\n");
    fp = filp_open("/root/kernel_file", O_RDWR|O_CREAT, 0644);
    if (IS_ERR(fp))
    {
        printk("create file error\n");
        return -1;
    }

    fs = get_fs();
    set_fs(KERNEL_DS);
    pos = 0;
    vfs_write(fp, buf, sizeof(buf), &pos);
    pos = 0;
    vfs_read(fp, buf1, sizeof(buf), &pos);
    printk("read: %s\n", buf1);
    set_fs(fs);
    filp_close(fp, NULL);
    return 0;
}
void hello_exit(void)
{
    printk("hello exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
