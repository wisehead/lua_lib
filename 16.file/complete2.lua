-- 以只读方式打开文件
file = io.open("test.lua", "r")
file:seek("end",-25)
print(file:read("*a"))

-- 关闭打开的文件
file:close()
