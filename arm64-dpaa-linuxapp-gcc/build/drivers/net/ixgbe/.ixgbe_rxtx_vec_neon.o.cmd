cmd_ixgbe_rxtx_vec_neon.o = aarch64-linux-gnu-gcc -Wp,-MD,./.ixgbe_rxtx_vec_neon.o.d.tmp   -pthread  -march=armv8-a+crc -mtune=cortex-a72 -mtls-dialect=trad -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include -include /home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Wimplicit-fallthrough=2 -Wno-format-truncation -Wno-deprecated   -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/build/rfs/rootfs_ubuntu_bionic_arm64/usr/include/aarch64-linux-gnu -o ixgbe_rxtx_vec_neon.o -c /home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/net/ixgbe/ixgbe_rxtx_vec_neon.c 
