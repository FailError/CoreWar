.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, :live, r1

live:	live %1
		zjmp %:live

#0b68 0100 0f00 0106 6401 0000 0008 0101   DIR
#0000 0001 09ff fb

#0b68 0100 0d00 0106 7401 0006 0101 0000   INDIR
#0001 09ff fbff fb