-- 以只读方式打开文件
--file = io.open("test.lua", "r")
for line in io.lines("test.lua") do
	print(line)
end
-- 关闭打开的文件
--file:close()
