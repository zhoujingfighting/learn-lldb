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

## TODO: