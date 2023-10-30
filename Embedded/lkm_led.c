#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

static struct task_struct *blink_thread;

static int blink_function(void *data)
{
    const char *led_on = "1";
    const char *led_off = "0";
    mm_segment_t old_fs;
    struct file *filep;
    loff_t pos = 0;

    // Allow the thread to be interrupted and stopped
    allow_signal(SIGKILL);
    while (!kthread_should_stop())
    {
        // Turn LED on
        filep = filp_open("/sys/class/gpio/gpio44/value", O_WRONLY, 0);
        if (IS_ERR(filep))
        {
            printk(KERN_ALERT "Cannot open gpio44/value\n");
            return -1;
        }

        old_fs = get_fs();
        set_fs(KERNEL_DS);
        vfs_write(filep, led_on, 1, &pos);
        filp_close(filep, NULL);
        set_fs(old_fs);
        ssleep(3);
        if (kthread_should_stop())
            break;

        // Turn LED off
        filep = filp_open("/sys/class/gpio/gpio44/value", O_WRONLY, 0);
        if (IS_ERR(filep))
        {
            printk(KERN_ALERT "Cannot open gpio44/value\n");
            return -1;
        }

        old_fs = get_fs();
        set_fs(KERNEL_DS);
        vfs_write(filep, led_off, 1, &pos);
        filp_close(filep, NULL);
        set_fs(old_fs);
        ssleep(3);
    }
    return 0;
}

static int __init lkm_led_init(void)
{
    printk(KERN_INFO "Starting LED blinker thread\n");
    blink_thread = kthread_run(blink_function, NULL, "blink_thread");
    if (IS_ERR(blink_thread))
    {
        printk(KERN_ERR "Failed to create the blink thread\n");
        return PTR_ERR(blink_thread);
    }

    return 0;
}

static void __exit lkm_led_exit(void)
{
    printk(KERN_INFO "Stopping LED blinker thread\n");
    if (blink_thread)
    {
        kthread_stop(blink_thread);
    }
}

module_init(lkm_led_init);
module_exit(lkm_led_exit);