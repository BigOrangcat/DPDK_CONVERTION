cmd_i40e_lan_hmc.o = aarch64-linux-gnu-gcc -Wp,-MD,./.i40e_lan_hmc.o.d.tmp   -pthread  -march=armv8-a+crc -mtune=cortex-a72 -mtls-dialect=trad -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include -include /home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Wimplicit-fallthrough=2 -Wno-format-truncation -DPF_DRIVER -DVF_DRIVER -DINTEGRATED_VF -DX722_A0_SUPPORT -Wno-error -Wno-sign-compare -Wno-unused-value -Wno-unused-parameter -Wno-strict-aliasing -Wno-format -Wno-missing-field-initializers -Wno-pointer-to-int-cast -Wno-format-nonliteral -Wno-format-security -Wno-unused-variable -Wno-unused-but-set-variable  -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/build/rfs/rootfs_ubuntu_bionic_arm64/usr/include/aarch64-linux-gnu -o i40e_lan_hmc.o -c /home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/drivers/net/i40e/base/i40e_lan_hmc.c 
