#include <linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/uaccess.h>
#include<linux/io.h>
#include<linux/delay.h>


MODULE_AUTHOR("Ryuichi Ueda & Kohei Yanagisawa");
MODULE_DESCRIPTION("driver for stepper_motor control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;


static ssize_t motor_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
	char c;
	int ms = 800;
	int i;	
    	if(copy_from_user(&c, buf, sizeof(char)))
        	return -EFAULT;

    	if(c == '0'){
		gpio_base[10] = 1 << 24;
		for(i = 0; i < 200; i++ ){
			fsleep(ms);
			gpio_base[10] = 1 << 25;
			fsleep(ms);
			gpio_base[7] = 1 << 25;
		}

        }else if(c == '1'){
		gpio_base[7] = 1 << 24;
		for(i = 0; i < 200; i++ ){
			fsleep(ms);
			gpio_base[10] = 1 << 25;
			fsleep(ms);
			gpio_base[7] = 1 << 25;
		}
	}
    	return 1;
}

static struct file_operations motor_fops = {
    	.owner = THIS_MODULE,
    	.write = motor_write,
};

static int __init init_mod(void)
{
    	int retval;
    	retval = alloc_chrdev_region(&dev, 0, 1, "stepper_motor");
    	if(retval < 0){
        	printk(KERN_ERR "alloc_chrdev_region failed.\n");
        	return retval;
    	}
    	printk(KERN_INFO "%s is loaded. major:%d\n",__FILE__,MAJOR(dev));

    	cdev_init(&cdv, &motor_fops);
    	retval = cdev_add(&cdv, dev, 1);
    	if(retval < 0){
        	printk(KERN_ERR "cdev_add failed. major:%d, minor:%d",MAJOR(dev),MINOR(dev));
        	return retval;
    	}

    	cls = class_create(THIS_MODULE, "stepper_motor");
    	if(IS_ERR(cls)){
        	printk(KERN_ERR "class_create failed.");
        	return PTR_ERR(cls);
    	}
    	device_create(cls, NULL, dev, NULL, "stepper_motor%d", MINOR(dev));

    	gpio_base = ioremap(0xfe200000, 0xA0);

	const u32 step = 25;
        const u32 index = step/10;
        const u32 shift = (step%10)*3;
        const u32 mask = ~(0x7 << shift);
	gpio_base[index] = (gpio_base[index] & mask) | (0x1 << shift);

	const u32 dir = 24;
        const u32 index2 = dir/10;
        const u32 shift2 = (dir%10)*3;
        const u32 mask2 = ~(0x7 << shift2);
        gpio_base[index2] = (gpio_base[index2] & mask2) | (0x1 << shift2);

	return 0;
}

static void __exit cleanup_mod(void)
{
    	cdev_del(&cdv);
    	device_destroy(cls, dev);
    	class_destroy(cls);
    	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "%s is unloaded. major:%d\n",__FILE__,MAJOR(dev));
}

module_init(init_mod);
module_exit(cleanup_mod);
