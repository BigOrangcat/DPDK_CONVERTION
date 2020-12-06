cmd_l2fwd-qdma = aarch64-linux-gnu-gcc -o l2fwd-qdma  -pthread  -march=armv8-a+crc -mtune=cortex-a72 -mtls-dialect=trad -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/examples/l2fwd-qdma/build/include -I/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include -include /home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Wimplicit-fallthrough=2 -Wno-format-truncation  main.o -L/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/lib -Wl,-lrte_flow_classify -Wl,-lrte_pipeline -Wl,-lrte_table -Wl,-lrte_port -Wl,-lrte_pdump -Wl,-lrte_distributor -Wl,-lrte_ip_frag -Wl,-lrte_gro -Wl,-lrte_gso -Wl,-lrte_meter -Wl,-lrte_lpm -Wl,--whole-archive -Wl,-lrte_acl -Wl,--no-whole-archive -Wl,-lrte_jobstats -Wl,-lrte_metrics -Wl,-lrte_bitratestats -Wl,-lrte_latencystats -Wl,-lrte_power -Wl,-lrte_timer -Wl,-lrte_efd -Wl,--whole-archive -Wl,-lrte_cfgfile -Wl,-lrte_hash -Wl,-lrte_member -Wl,-lrte_vhost -Wl,-lrte_kvargs -Wl,-lrte_mbuf -Wl,-lrte_net -Wl,-lrte_ethdev -Wl,-lrte_cryptodev -Wl,-lrte_security -Wl,-lrte_eventdev -Wl,-lrte_rawdev -Wl,-lrte_mempool -Wl,-lrte_mempool_ring -Wl,-lrte_ring -Wl,-lrte_pci -Wl,-lrte_eal -Wl,-lrte_cmdline -Wl,-lrte_reorder -Wl,-lrte_sched -Wl,-lrte_kni -Wl,-lrte_bus_pci -Wl,-lrte_bus_vdev -Wl,-lrte_bus_dpaa -Wl,-lrte_bus_fslmc -Wl,-lrte_mempool_stack -Wl,-lrte_mempool_dpaa -Wl,-lrte_mempool_dpaa2 -Wl,-lrte_pmd_af_packet -Wl,-lrte_pmd_bond -Wl,-lrte_pmd_dpaa -Wl,-lrte_pmd_ppfe -Wl,-lrte_pmd_dpaa2 -Wl,-lrte_pmd_e1000 -Wl,-lrte_pmd_failsafe -Wl,-lrte_pmd_i40e -Wl,-lrte_pmd_ixgbe -Wl,-lrte_pmd_kni -Wl,-lrte_pmd_null -Wl,-lrte_pmd_ring -Wl,-lrte_pmd_tap -Wl,-lrte_pmd_virtio -Wl,-lrte_pmd_vhost -Wl,-lrte_pmd_null_crypto -Wl,-lrte_pmd_crypto_scheduler -Wl,-lrte_pmd_dpaa2_sec -Wl,-lrte_pmd_dpaa_sec -Wl,-lrte_pmd_skeleton_event -Wl,-lrte_pmd_sw_event -Wl,-lrte_pmd_dpaa_event -Wl,-lrte_pmd_dpaa2_event -Wl,-lrte_pmd_skeleton_rawdev -Wl,-lrte_pmd_dpaa2_qdma -Wl,-lrte_pmd_dpaa2_cmdif -Wl,--no-whole-archive -Wl,-lrt -Wl,-lm -Wl,-ldl -Wl,-export-dynamic -Wl,-export-dynamic -L/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/examples/l2fwd-qdma/build/lib -L/home/forlinx/work/OK10xx-linux-fs/flexbuild/packages/apps/dpdk/arm64-dpaa-linuxapp-gcc/lib -Wl,--as-needed -Wl,-Map=l2fwd-qdma.map -Wl,--cref 
