## learn-lldb
学会使用命令行工具debug, 排除某些情况由于`IDE`造成的影响
下载的官网 : https://apt.llvm.org/
> 从官网下载的工具会提供自动补全功能
## Detailed information

### With Args

```shell
lldb -- a.out arguments
// Example lldb -- a.out hello hello1
// OutPut (lldb) settings set -- target.run-args  "hello" "hhh"
// 类似于VScode launch Debug时设置参数列表
```
### Running

```
(lldb) run 
(lldb) r // Run的简写
```
### Setting BreakPoint

```
break set -f demo.cpp -l #
br s -f demo.cpp -l #
break set -f demo.cpp -l #
//以下可以是简写,推荐
b sample.cpp : [lineNumber]
```

**BreakPoint with Symbols**

On a function
`b [functionname]`

On a class method
`b Demo::demo()`

Inside a nameSpace
`b LLDBDemo::add(int int)`

### 操作断点

获得所有断点 ： `br list`
删除某个断点 ： `br delete [--name] [--location]`
* br delete (默认删除所有断点)
* br delete number (删除某个断点)


#### Step

step into the function 

`step` or `s`

#### next

step into next line

### Inspecting Variables

#### Print Variable Content
(lldb) p varname

#### Frame Variables
(lldb) frame variable
(lldb) fr v

#### backtracking
```
* thread #1, name = 'a.out', stop reason = step in
  * frame #0: 0x00005555555563af a.out`isValidParen(Paren=error: summary string parsing error) at sample.cpp:20:20
    frame #1: 0x00005555555566fc a.out`main at sample.cpp:53:7
    frame #2: 0x00007ffff7a75d90 libc.so.6`__libc_start_call_main(main=(a.out`main at sample.cpp:51), argc=1, argv=0x00007fffffffddd8) at libc_start_call_main.h:58:16
    frame #3: 0x00007ffff7a75e40 libc.so.6`__libc_start_main_impl(main=(a.out`main at sample.cpp:51), argc=1, argv=0x00007fffffffddd8, init=<unavailable>, fini=<unavailable>, rtld_fini=<unavailable>, stack_end=0x00007fffffffddc8) at libc-start.c:392:3
    frame #4: 0x00005555555562d5 a.out`_start + 37
(lldb) frame 
Available completions:
        diagnose   -- Try to determine what path the current stop location used to get to a register or address
        info       -- List information about the current stack frame in the current thread.
        recognizer -- Commands for editing and viewing frame recognizers.
        select     -- Select the current stack frame by index from within the current thread (see 'thread backtrace'.)
        variable   -- Show variables for the current stack frame. Defaults to all arguments and local variables in scope. Names of argument, local, file static and file global variables can be specified.
(lldb) frame info
frame #0: 0x00005555555563af a.out`isValidParen(Paren=error: summary string parsing error) at sample.cpp:20:20

```

* `Frame info` : 查看当前栈帧的使用情况