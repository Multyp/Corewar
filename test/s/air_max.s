	.name		"Lebrun"
	.comment	"Jaime"

begin:	lldi %:lol, %:lol, r1
	ld   %:lol, r1
	lld  %:lol, r1
lol:	live %4920
	fork %:begin
	ld %0, r3
	zjmp %:lol
