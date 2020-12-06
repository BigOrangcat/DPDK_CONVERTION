#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x59cc993a, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xb8b89dc4, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x78d2acf, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0x84bc974b, __VMLINUX_SYMBOL_STR(__arch_copy_from_user) },
	{ 0x8669fba3, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0x4aacd53e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xa87cf413, __VMLINUX_SYMBOL_STR(clear_bit) },
	{ 0xf1fdc1a2, __VMLINUX_SYMBOL_STR(__put_net) },
	{ 0x7183d245, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x526c3a6c, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xa17cb528, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0xce67c807, __VMLINUX_SYMBOL_STR(kthread_bind) },
	{ 0x2192e86, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xc2b00af2, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x2aad2022, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x52c12e8d, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0xd3259d65, __VMLINUX_SYMBOL_STR(test_and_set_bit) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x744c8fdb, __VMLINUX_SYMBOL_STR(netif_rx_ni) },
	{ 0x33741171, __VMLINUX_SYMBOL_STR(unregister_pernet_subsys) },
	{ 0xf5178be6, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0xe2eb0ddf, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x1157f5f0, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0xd0f90d9a, __VMLINUX_SYMBOL_STR(__cpu_online_mask) },
	{ 0x4d10c96e, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x91cc2145, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xfadf2436, __VMLINUX_SYMBOL_STR(memstart_addr) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x41e5e34f, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0x5e38de65, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x2469810f, __VMLINUX_SYMBOL_STR(__rcu_read_unlock) },
	{ 0x308e7904, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x992b137f, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0xfe487975, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0xa916b694, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0x8ddd8aad, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x3617bee6, __VMLINUX_SYMBOL_STR(alloc_netdev_mqs) },
	{ 0xb392ae64, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0x7f24de73, __VMLINUX_SYMBOL_STR(jiffies_to_usecs) },
	{ 0xfccb32f3, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x199f3ba3, __VMLINUX_SYMBOL_STR(register_pernet_subsys) },
	{ 0x76223778, __VMLINUX_SYMBOL_STR(ether_setup) },
	{ 0x3c578bac, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x7c580e7, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x54496b4, __VMLINUX_SYMBOL_STR(schedule_timeout_interruptible) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xae8c4d0c, __VMLINUX_SYMBOL_STR(set_bit) },
	{ 0x41acaf3c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xdcbd2898, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x5594772b, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x8d522714, __VMLINUX_SYMBOL_STR(__rcu_read_lock) },
	{ 0x7b90ccd6, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x3f99ceb4, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0x796d26e5, __VMLINUX_SYMBOL_STR(__init_rwsem) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

