.name "Eternity"
.comment "I shall live forever"

ld %1, r2
ld %2147483648, r6
ld %8388608, r7
ld %57672192, r3
ld %553873409, r4
ld %2097152, r5
live %-1
add r4, r6, r4
add r5, r7, r5
st r2, 30
st r1, 29
st r3, 29
st r4, 28
st r5, 27
fork %-40
