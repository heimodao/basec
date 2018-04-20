local str = "12ab34,eed,56"
local func_itor = string.gmatch(str, "%d+")

-- 查看func_itor类型
print("func_itor is", func_itor)

-- 第一次调用函数func_itor
print("func_itor ret is ", func_itor())

-- 再次调用函数func_itor
print("func_itor ret is ", func_itor())

-- 使用循环来打印
local sourcestr = "hello world from Lua"
local index = 1
print("\noutput capture using loop:")
for word in string.gmatch(sourcestr, "%a+") do
    print(index, word)
    index = index + 1
end

-- 查找属性对
local attrstr = "from=world, to=Lua, name=AlbertS"
print("\noutput attr pair capture using loop:")
for k,v in string.gmatch(attrstr, "(%w+)=(%w+)") do
    print(k, v)
end

local nonumstr = "fadfasd,.;p[];'asd"
local func_numitor = string.gmatch(nonumstr, "%d+")
local numret = func_numitor()
print("\nnumret ret is", numret)


-- 级联test.test2.test3
local attrs = "test.test2.test3"

for attr in string.gmatch(attrs,"([^.]+)%.?") do
	print(attr)
end