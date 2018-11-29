all: zformat zinspect zfilez zmkdir zrmdir ztouch zcreate zappend zmore zremove zlink

.c.o:
	gcc -c $< -o $@

zformat: zformat.c
	gcc vdisk.c oufs_lib_support.c zformat.c -o zformat
zinspect: zinspect.c
	gcc vdisk.c oufs_lib_support.c zinspect.c -o zinspect
zfilez: zfilez.c
	gcc vdisk.c oufs_lib_support.c zfilez.c -o zfilez
zmkdir: zmkdir.c
	gcc vdisk.c oufs_lib_support.c zmkdir.c -o zmkdir
zrmdir: zrmdir.c
	gcc vdisk.c oufs_lib_support.c zrmdir.c -o zrmdir
ztouch: ztouch.c
	gcc vdisk.c oufs_lib_support.c ztouch.c -o ztouch
zcreate: zcreate.c
	gcc vdisk.c oufs_lib_support.c zcreate.c -o zcreate
zappend: zappend.c
	gcc vdisk.c oufs_lib_support.c zappend.c -o zappend
zmore: zmore.c
	gcc vdisk.c oufs_lib_support.c zmore.c -o zmore
zremove: zremove.c
	gcc vdisk.c oufs_lib_support.c zremove.c -o zremove
zlink: zlink.c
	gcc vdisk.c oufs_lib_support.c zlink.c -o zlink

clean: 
	rm ./zformat ./zinspect ./zfilez ./zmkdir ./zrmdir ./ztouch ./zcreate ./zappend ./zmore ./zremove ./zlink
