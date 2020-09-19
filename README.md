ASLR sandbox

### Info
```bash
$ sysctl kernel/randomize_va_space
kernel.randomize_va_space = 2

# 0 Disable ASLR

# 1 Randomize the positions of the stack, virtual dynamic shared object (VDSO) page, and shared memory regions.
# The base address of the data segment is located immediately after the end of the executable code segment.

# 2 same as 1 + data segment. default setting
```

### Demo
```bash
make demo
```

### Example run
```
===== PIE                                      ===== PIE
Hello from main                                Hello from main
func1 addr: 0x55abee4e11a9                     func1 addr: 0x56425edf71a9
func2 addr: 0x55abee4e11c0                     func2 addr: 0x56425edf71c0
addr of variable in main: 0x7ffc364f84ac       addr of variable in main: 0x7ffd1acad0bc
                                               
===== no-pie                                   ===== no-pie
Hello from main                                Hello from main
func1 addr: 0x401196                           func1 addr: 0x401196
func2 addr: 0x4011ad                           func2 addr: 0x4011ad
addr of variable in main: 0x7ffd87b3377c       addr of variable in main: 0x7ffe86ab7e5c
```

# GDB tips

```
(gdb) p func2
$2 = {<text variable, no debug info>} 0x555555555165 <func2>
call ((void (*)())(0x0000555555555165))()
c
```

### References
https://www.kernel.org/doc/Documentation/sysctl/kernel.txt

