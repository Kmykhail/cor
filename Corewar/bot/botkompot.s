.name "OKKZH"
.comment "FUCK YOU"

l2:     sti r1, %:live, %1
        and r1, %0, r1
l4:     ldi %:live, %1, r1
l3:     sti r1, %:live2, %1
        and r1, %0, r1
        fork %:live2
live:   live %1
        zjmp %:live
live2:  live %1
        zjmp %:l3
