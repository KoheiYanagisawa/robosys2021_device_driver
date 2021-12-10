#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x5ff65bdc, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x452b7537, "class_destroy" },
	{ 0xede42b4e, "device_destroy" },
	{ 0x9f6d6924, "cdev_del" },
	{ 0x6b4b2933, "__ioremap" },
	{ 0xaf56600a, "arm64_use_ng_mappings" },
	{ 0xcd985cfb, "device_create" },
	{ 0xa60791c4, "__class_create" },
	{ 0xef11e836, "cdev_add" },
	{ 0x97215deb, "cdev_init" },
	{ 0xc5850110, "printk" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x9f49dcc4, "__stack_chk_fail" },
	{ 0xec3d2e1b, "trace_hardirqs_off" },
	{ 0xd697e69a, "trace_hardirqs_on" },
	{ 0x4b0a3f52, "gic_nonsecure_priorities" },
	{ 0xf9a482f9, "msleep" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0xb788fb30, "gic_pmr_sync" },
	{ 0x5c1c3eb4, "cpu_hwcaps" },
	{ 0x5e2d7875, "cpu_hwcap_keys" },
	{ 0x14b89635, "arm64_const_caps_ready" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E38702FE5072D61F48AE01B");
