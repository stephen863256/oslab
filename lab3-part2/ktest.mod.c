#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

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
	{ 0x3f039918, "module_layout" },
	{ 0x63c125c5, "sysfs_remove_group" },
	{ 0x49ab7dae, "filp_close" },
	{ 0x75c00821, "kthread_stop" },
	{ 0x81755975, "sysfs_create_group" },
	{ 0x85d0f9ed, "mm_kobj" },
	{ 0xfc68c44c, "wake_up_process" },
	{ 0xe1321f00, "kthread_create_on_node" },
	{ 0x69acdf38, "memcpy" },
	{ 0x41780cb9, "mmput" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa916b694, "strnlen" },
	{ 0x1d19f77b, "physical_mask" },
	{ 0x65ec6fb4, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x72d79d83, "pgdir_shift" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x94f49e13, "find_vma" },
	{ 0xcd989dfd, "get_task_mm" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x4482cdb, "__refrigerator" },
	{ 0x32a6870e, "freezing_slow_path" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x7ab88a45, "system_freezing_cnt" },
	{ 0xe2c17b5d, "__SCT__might_resched" },
	{ 0x957226ac, "filp_open" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xe6360f77, "set_user_nice" },
	{ 0x9e61bb05, "set_freezable" },
	{ 0x48d88a2c, "__SCT__preempt_schedule" },
	{ 0xdecd8f1b, "kernel_write" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb34f0214, "pid_task" },
	{ 0xe324ee9d, "find_get_pid" },
	{ 0xc07351b3, "__SCT__cond_resched" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x5bce634, "current_task" },
	{ 0x4629334c, "__preempt_count" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1FE7C0DAD13C4AB7990C8CC");
