#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>
//#include <linux/stdlib.h>

static char baz[20]="Shivam";
static int foo=555;
//static int baz;
//static char baz[32]="Nivedita";
//static int bar;
static char bar='x';

static ssize_t bar_show(struct kobject *kobj, 
                        struct kobj_attribute *attr,
			char *buf)
{
        dump_stack();
        sprintf(buf, "%c", bar);
        printk("In bar_show: data string is %s\n", buf);
}


static ssize_t bar_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
        dump_stack();
	sscanf(buf, "%cu", &bar);
	printk("In bar_store: data  is %c\n", bar);
	return count;
}

static ssize_t baz_show(struct kobject *kobj, 
                        struct kobj_attribute *attr,
			char *buf)
{
        dump_stack();
        sprintf(buf, "%s", baz);
        printk("In baz_show: data string is %s\n", buf);
}


static ssize_t baz_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
        dump_stack();
	sscanf(buf, "%su", baz);
	printk("In baz_store: data  is %s\n", baz);
	return count;
}
static ssize_t foo_show(struct kobject *kobj, 
                        struct kobj_attribute *attr,
			char *buf)
{
        dump_stack();
        sprintf(buf, "%d", foo);
        printk("In foo_show: data string is %s\n", buf);
}


static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
        dump_stack();
	sscanf(buf, "%du", &foo);
	printk("In foo_store: data  is %d\n", foo);
	return count;
}

static struct kobj_attribute baz_attribute =
	__ATTR(baz, 0644, baz_show, baz_store);

static struct kobj_attribute foo_attribute =
	__ATTR(foo, 0644, foo_show, foo_store);

static struct kobj_attribute bar_attribute =
	__ATTR(bar, 0644, bar_show, bar_store);


static struct attribute *attrs[] = {
	&baz_attribute.attr,&foo_attribute.attr,&bar_attribute.attr,
	NULL,
};

static struct attribute_group attr_group = {
	.attrs = attrs,
};

static struct kobject *example_kobj;

static int __init example_init(void)
{
	int retval=0;

	example_kobj = kobject_create_and_add("kobject_example", kernel_kobj);
	if (!example_kobj)
		return -ENOMEM; 
                                
        retval = sysfs_create_group(example_kobj, &attr_group);


	return retval;
}

static void __exit example_exit(void)
{
	kobject_put(example_kobj);
}

module_init(example_init);
module_exit(example_exit);
MODULE_LICENSE("SHIVAM");
MODULE_AUTHOR("Shivam Gupta <shivamshankargupta@gmail.com>");
