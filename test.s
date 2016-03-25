	.name "zork"
	.comment "Just a basic living program"

l2:
	sti r1,%:live,%1
	and r1,%0,r1
live:	live %1
	zjmp %:live
	ld 34,r3
	sti r2,r3,r4
	live %1
	zjmp %1
