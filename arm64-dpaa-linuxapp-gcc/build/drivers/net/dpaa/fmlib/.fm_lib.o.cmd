cmd_fmlib/fm_lib.o = aarch64-linux-gnu-gcc -Wp,-MD,fmlib/.fm_lib.o.d.tmp  -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/net/dpaa  -pthread  -march=armv8-a+crc -mtune=cortex-a72 -mtls-dialect=trad -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include -include /home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Wimplicit-fallthrough=2 -Wno-format-truncation -Wno-pointer-arith -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/net/dpaa/ -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/net/dpaa/include -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/net/dpaa/fmlib -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/bus/dpaa -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/bus/dpaa/include/ -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/bus/dpaa/base/qbman -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/mempool/dpaa -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/event/dpaa -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/lib/librte_eal/common/include -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/lib/librte_eal/linuxapp/eal/include   -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/build/rfs/rootfs_ubuntu_bionic_arm64/usr/include/aarch64-linux-gnu -o fmlib/fm_lib.o -c /home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/net/dpaa/fmlib/fm_lib.c 
