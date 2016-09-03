.name "test"
.comment "OUKT"

live:
st r1, 6
live %1
test:
fork %:test
zjmp %:live
