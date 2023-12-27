cmd_/home/yxc/oslab/lab3-part2/modules.order := {   echo /home/yxc/oslab/lab3-part2/ktest.ko; :; } | awk '!x[$$0]++' - > /home/yxc/oslab/lab3-part2/modules.order
