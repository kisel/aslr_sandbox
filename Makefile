default: build

build:
	gcc -no-pie -o test.nopie main.c
	gcc -pie -o test.pie main.c

demo:
	watch -n1 'echo "\n===== PIE"; ./test.pie ; echo "\n===== no-pie" ; ./test.nopie'

