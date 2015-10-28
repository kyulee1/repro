.text
.global foo
foo:
call goo
mov $3, %rax
ret

.data
.global eetype
.quad foo

