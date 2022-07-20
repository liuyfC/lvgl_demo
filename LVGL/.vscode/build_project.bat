::命令不显示
@echo off 
::keil应用程序的完整路径
set UV=D:\Keil_v5\UV4\UV4.exe
::传入第一个参数，-b表示编译，其他表示下载
set pra=%1 
::传入第二个参数，工程的完整路径
set UV_PRO_PATH=%2.\429.uvprojx 

if %pra% == -b (  ::根据输入参数进行动态输出提示信息
echo Init building ...
)else (
echo init Download ...
)
::创建中间文件并清空内容
echo .>build_log.txt 
"%UV%" -j0 %pra% "%UV_PRO_PATH%" -o build_log.txt 
::使用命令行进行相应的操作，并将操作日志保存在中间文件中
::显示中间文件内容
type build_log.txt
::显示处理结束
echo Done.
::删除中间文件
del build_log.txt
exit
