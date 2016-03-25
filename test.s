	.name "zork"
	.comment "Just a basic living program"

<<<<<<< HEAD
l2:
	sti r1,%:live,%1
	and r1,%0,r1
live:	live %1
	zjmp %:live
=======
	ld 34,r3
	sti r2,r3,r4
	live %1
	zjmp %1
>>>>>>> d3d9dfc503a2732b62ea73168119d136e1bcb3bc
