	.name		"Lebrun"
	.comment	"Jaime"

begin:	sti r1, %:lol, %1

lol:	live %4920
	fork %:begin
	ld %0, r3
	zjmp %:lol
